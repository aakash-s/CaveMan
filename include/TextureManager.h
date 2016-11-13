#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H
#include<iostream>
#include<map>
#include<SDL.h>
#include<SDL_image.h>
using namespace std;

/*___ This class deals with the loading of images and drawing them to the renderer ___*/


class TextureManager
{
    public:

        virtual ~TextureManager();
        bool load(std::string filename,std::string ID,SDL_Renderer* render);
        void draw(std::string ID,int xpos,int ypos,int width,int height,SDL_Renderer*renderer,SDL_RendererFlip flip = SDL_FLIP_NONE);
        void drawFrame(std::string ID,int xpos,int ypos,int width,int height,int currentRow,int currentFrame,
                       SDL_Renderer* renderer,SDL_RendererFlip = SDL_FLIP_NONE);
        void clearFromTextureMap(std::string);
        std::map<std::string,SDL_Texture*> textureMap;
        static TextureManager*Instance();
        void drawTile(std::string id,int margin,int spacing,int x,int y,int width,int heigth,int currentRow,int currentFrame,
                      SDL_Renderer*render);
        void drawBack(string ID,int x,int y,int width,int height,int currentRow,int currentFrame,SDL_Renderer*renderer
                               );
    protected:
    private:
        TextureManager();
        static TextureManager* _instance;
};

#endif // TEXTUREMANAGER_H
