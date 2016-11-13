#include "LevelParser.h"
#include "TextureManager.h"
#include "Game.h"
#include "TileLayer.h"
#include "Player.h"
#include "LevelParser.h"
#include "CollosionManager.h"
#include "GameObjectFactory.h"

LevelParser::LevelParser()
{
    //ctor
}

LevelParser::~LevelParser()
{
    //dtor
}

void LevelParser::parseTilesets(TiXmlElement*tilesetRoot,std::vector<Tileset>* tilesets)
{

    TextureManager::Instance()->load(tilesetRoot->FirstChildElement()->Attribute("source"),tilesetRoot->Attribute("name"),
                                     Game::Instance()->getRenderer());
    Tileset tilesetObj;
    tilesetRoot->FirstChildElement()->Attribute("width",&tilesetObj.width);
    tilesetRoot->FirstChildElement()->Attribute("height",&tilesetObj.height);
    tilesetRoot->Attribute("firstgid",&tilesetObj.firstGID);
    tilesetRoot->Attribute("tilewidth",&tilesetObj.tileWidth);
    tilesetRoot->Attribute("tileheight",&tilesetObj.tileHeight);
    tilesetRoot->Attribute("spacing",&tilesetObj.spacing);
    tilesetRoot->Attribute("margin",&tilesetObj.margin);
    tilesetRoot->Attribute("columns",&tilesetObj.num_cols);
    tilesetObj.name = tilesetRoot->Attribute("name");
    tilesets->push_back(tilesetObj);
}
void LevelParser::parseTileLayer(TiXmlElement*tileLayerRoot,std::vector<Layer*>*layers,std::vector<Layer*>*c_layers,
                                 std::vector<Tileset>*tilesets,
                                 int gameWidth,int gameHeight)
{

    TileLayer* tileLayerObj = new TileLayer(tilesize,*tilesets,width,height);
    std::vector<std::vector<int>>data;
    TiXmlElement*dataNode;
    TiXmlElement*propNode;
    int temp;

    for(TiXmlElement*e=tileLayerRoot->FirstChildElement();e!=NULL;e=e->NextSiblingElement())
    {
        if(e->Value() == std::string("data"))
            dataNode = e;
        if(e->Value() == std::string("properties"))
            propNode = e;
    }

    std::vector<unsigned int>gids;
    for(TiXmlElement*e=dataNode->FirstChildElement();e!=NULL;e=e->NextSiblingElement())
    {
        e->Attribute("gid",&temp);
        gids.push_back(temp);
    }

    std::vector<int>layerRow(width);
    for(int j=0;j<height;j++){
        data.push_back(layerRow);
    }

    for(int rows = 0;rows<height;rows++)
    {
        for(int cols =0;cols<width;cols++)
        {
            data[rows][cols] = gids[rows*width + cols];
        }
    }

    tileLayerObj->setTileIDs(data);

    layers->push_back(tileLayerObj);
    if(propNode->FirstChildElement()->Attribute("value") == std::string("yes"))c_layers->push_back(tileLayerObj);
}





Level*LevelParser::parseLevel(const char*levelFile)
{
    TiXmlDocument levelDocument;
    levelDocument.LoadFile(levelFile);

    Level* _level = new Level();
    TiXmlElement*root = levelDocument.RootElement();     /// Root element is map
    root->Attribute("tilewidth",&tilesize);              /// These are the dimensions of the map
    root->Attribute("width",&width);
    root->Attribute("height",&height);

    for(TiXmlElement*e=root->FirstChildElement();e!=NULL;e=e->NextSiblingElement())            /// root element map has 2 types
    {                                                                                          /// of children,either TileLayer
            if(e->Value()==std::string("tileset")){
                parseTilesets(e,_level->getTilesets());
            }                                                                                    /// or a tileset
    }
    /** e is the tileset then parse tileset is called along with the getTileset() method of the newly created Level file
        ,The getTileset will return the address of the Tilesets type vector maintained by the level type object */
    for(TiXmlElement*e=root->FirstChildElement();e!=NULL;e=e->NextSiblingElement())            /// root element map has 2 types
        {                                                                                          /// of children,either TileLayer
                if(e->Value()==std::string("layer")){
                    parseTileLayer(e,_level->getLayers(),_level->getc_Layers(),_level->getTilesets(),width,height);
                }                                                                                    /// or a tileset
        }

    /** Similarly parseLayer is called */
    GameObjectFactory::Instance()->registerType("player",new playerCreator());
    GameObject*hero = GameObjectFactory::Instance()->create("player");
    hero->load(425,285,50,81,0,0,"hero");
    TextureManager::Instance()->load("assets/hero_hero.png","hero",Game::Instance()->getRenderer());
    _level->setPlayer(hero);

    CollosionManager::Instance()->setLayers(_level->getc_Layers());
    CollosionManager::Instance()->sethero(_level->get_player());

    return _level;
}








