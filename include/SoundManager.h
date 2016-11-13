#ifndef SOUNDMANAGER_H
#define SOUNDMANAGER_H
#include<SDL.h>
#include "SDL_mixer.h"
#include<iostream>
#include<string>
#include<map>

enum sound_type
{
    SOUND_MUSIC = 0,
    SOUND_SFX = 1
};
class SoundManager
{
    public:
        SoundManager();
        virtual ~SoundManager();
        static SoundManager* Instance();
        bool load(std::string filename,std::string ID,sound_type type);
        void playSound(std::string ID,int loop);
        void playMusic(std::string ID,int loop);
        void stopMusic(){Mix_HaltMusic();}
        SoundManager(const SoundManager&);
        SoundManager&operator=(const SoundManager&);
        void stop(std::string);
    protected:
    private:
        static SoundManager* _instance;
        std::map<std::string,Mix_Chunk*>m_sfxs;
        std::map<std::string,Mix_Music*>m_music;

};

#endif // SOUNDMANAGER_H
