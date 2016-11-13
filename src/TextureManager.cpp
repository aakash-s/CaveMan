#include "TextureManager.h"


TextureManager* TextureManager::_instance = 0;

TextureManager::TextureManager()
{

    //ctor
}

TextureManager::~TextureManager()
{
    //dtor
}

/// The following function takes the name of the file to load and the renderer , if the file is successfully loaded
/// it stores it into a map named as textureMap using the key ID supplied to this function

bool TextureManager::load(string filename,string ID,SDL_Renderer* renderer)
{
    SDL_Surface* tempSurface = IMG_Load(filename.c_str());
    if(tempSurface == NULL){
        cout<<"Surface could not be initialized SDL_Error: "<<SDL_GetError()<<"\n";
        return false;
    }
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer,tempSurface);
    SDL_FreeSurface(tempSurface);
    if(texture != 0){
            textureMap[ID] = texture;
            return true;
        }
    return false;
}


/// The following function takes the ID of the image to be drawn and then using the parameters supplied to this function
/// it draws the image keyed by the ID to the renderer
void TextureManager::draw(string ID,int x,int y,int width,int height,SDL_Renderer* renderer, SDL_RendererFlip flip)
{
    SDL_Rect srcRect,destRect;

    srcRect.x = 0;
    destRect.y = 0;
    srcRect.w = 128;
    destRect.w = width;
    srcRect.h = 55;
    destRect.h = height;
    destRect.x = x;
    destRect.y = y;
    SDL_RenderCopyEx(renderer,textureMap[ID],&srcRect,&destRect,0,0,flip);
}




void TextureManager::drawTile(std::string id,int margin,int spacing,int x,int y,int width,int height,int currentRow,
                              int currentFrame,SDL_Renderer*render)
{

    SDL_Rect srcRect,destRect;
    srcRect.x = margin + (spacing + width)*currentFrame;
    srcRect.y = margin + (spacing + height)*currentRow;
    srcRect.w = destRect.w = width;
    srcRect.h = destRect.h = height;
    destRect.x = x;
    destRect.y = y;
    SDL_RenderCopyEx(render,textureMap[id],&srcRect,&destRect,0,0,SDL_FLIP_NONE);
}


/// The following function is almost same as the draw function but it differs in the fact that it calculates the x and y
/// parameters of the source rectangle based on two dynamic parameters called currentRow and currentFrame , those two parameters
/// will be updated further to ensure animation
void TextureManager::drawFrame(string ID,int x,int y,int width,int height,int currentRow,int currentFrame,SDL_Renderer*renderer
                        ,       SDL_RendererFlip flip)
{
    int k=0;
    if(ID == "lion")k=20;
    else k=0;
    SDL_Rect srcRect,destRect;
    srcRect.x = width*currentFrame + k;
    srcRect.y = height*currentRow;
    destRect.x = x;
    destRect.y = y;
    srcRect.w = destRect.w = width;
    srcRect.h = destRect.h = height;
    destRect.x = x;
    destRect.y = y;

    SDL_RenderCopyEx(renderer,textureMap[ID],&srcRect,&destRect,0,0,flip);
}

/// Function to make the class a singleton
TextureManager* TextureManager::Instance()
{
    if(_instance == 0){
        _instance = new TextureManager();
    }
    return _instance;
}

void TextureManager::clearFromTextureMap(std::string ID)
{
    textureMap.erase(ID);
}


void TextureManager::drawBack(string ID,int x,int y,int width,int height,int currentRow,int currentFrame,SDL_Renderer*renderer)
{
    SDL_Rect srcRect,destRect;
    srcRect.x = currentFrame;
    srcRect.y = height*currentRow;
    destRect.x = x;
    destRect.y = y;
    srcRect.w = destRect.w = width;
    srcRect.h = destRect.h = height;
    destRect.x = x;
    destRect.y = y;

    SDL_RenderCopyEx(renderer,textureMap[ID],&srcRect,&destRect,0,0,SDL_FLIP_NONE);
}
