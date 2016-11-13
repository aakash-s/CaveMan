#include "SoundManager.h"
SoundManager* SoundManager::_instance = 0;
SoundManager::SoundManager()
{
    Mix_Init(MIX_INIT_OGG);
    Mix_OpenAudio(22050,AUDIO_S16,2,4096);
    //ctor
}

SoundManager::~SoundManager()
{
    Mix_CloseAudio();
    //dtor
}
SoundManager*SoundManager::Instance()
{
    if(_instance == 0)_instance = new SoundManager();
    return _instance;
}

bool SoundManager::load(std::string filename,std::string id,sound_type type)
{
    if(type == SOUND_MUSIC)
    {
        Mix_Music* pMusic = Mix_LoadMUS(filename.c_str());
        if( pMusic == 0 )
        {
            std::cout<<"Could Not Load Music "<<Mix_GetError()<<"\n";
            return false;
        }
        m_music[id]=pMusic;
        return true;
    }
    else if(type == SOUND_SFX)
    {
        Mix_Chunk* pChunk = Mix_LoadWAV(filename.c_str());
        if(pChunk == 0)
        {
            std::cout<<"Could Not Load SFX "<<Mix_GetError()<<"\n";
            return false;
        }
        m_sfxs[id]=pChunk;
        return true;
    }
    return false;

}

void SoundManager::stop(std::string id)
{
    Mix_FreeChunk(m_sfxs[id]);
}


void SoundManager::playMusic(std::string id,int loop)
{
    Mix_PlayMusic(m_music[id],-1);
}

void SoundManager::playSound(std::string id,int loop)
{
    Mix_PlayChannel(-1,m_sfxs[id],loop);
}
