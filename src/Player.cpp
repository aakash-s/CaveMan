#include "Player.h"
#include "InputHandler.h"
#include "CollosionManager.h"
#include "Camera.h"
#include "TextureManager.h"
#include "GameStateMachine.h"
#include "GameOverState.h"
#include "SoundManager.h"
#include "GameWon.h"
Player::Player()
{
    flip = 0;
    lastsafepos = position+vector2D(0,100);
    jump_pressed = false;
    can_jump = true;
    jumping = false;
    moveLeft = false;
    moveRight = false;
    jumpheight = 100;
    dead = false;
    num_frames = 7;
    attack = false;
    can_attack = true;
    health=100;
    run = false;
    //ctor
}

Player::~Player()
{
    //dtor
}

void Player::draw()
{
     //std::cout<<position.getX()<<"\t"<<position.getY()<<"\n";

    if(flip == true)
    {
        TextureManager::Instance()->drawFrame(ID,int(position.getX()-Camera::Instance()->getPosition().getX()),
                                              int(position.getY()),
                                              width,height,currentRow,currentFrame,Game::Instance()->getRenderer(),
                                              SDL_FLIP_HORIZONTAL);
    }
     else
    {
        TextureManager::Instance()->drawFrame(ID,int(position.getX()-Camera::Instance()->getPosition().getX())
                                              ,int(position.getY()),
                                              width,height,currentRow,currentFrame,Game::Instance()->getRenderer());
    }
}


void Player::clean()
{

}

void Player::load(int xpos,int ypos,int _width,int _height,int _cR,int _cF,std::string _ID)
{
    velocity.setX(0);velocity.setY(0);
    acceleration.setX(0);acceleration.setY(0);
    position.setX(xpos);
    position.setY(ypos);
    width = _width;
    height = _height;
    ID = _ID;
    currentRow = _cR;
    currentFrame = _cF;
    flip = 0;
    Camera::Instance()->setTarget(&position);
}


void Player::handleMovement(vector2D velocity)
{

    vector2D newPos = position;
    newPos.setX(position.getX() + velocity.getX());
    if(!CollosionManager::Instance()->checkPlayerTileCollosion(newPos,width,height))
    {
        position = newPos;
    }
    else
    {
        velocity.setX(0);
    }
    newPos = position;
    newPos.setY(position.getY() + velocity.getY());
    if(!CollosionManager::Instance()->checkPlayerTileCollosion(newPos,width,height ) and position.getX()>0)
    {
        position = newPos;
    }
    else
    {
        velocity.setY(0);
        lastsafepos = position;
        can_jump = true;
        jumping = false;

    }


}


void Player::update()
{
    if(position.getX()>=15800)
    {
        Mix_Volume(-1,MIX_MAX_VOLUME/50);
        SoundManager::Instance()->playSound("level",0);
        Game::Instance()->getGameStateMachine()->changeState(new GameWon());
    }
    handleInput();

    if(position.getY()>475){
            health=0;
            dead=true;
               SoundManager::Instance()->playSound("death",0);
            SoundManager::Instance()->stopMusic();
             Game::Instance()->getGameStateMachine()->changeState(new GameOverState());
    }
    if(attack){
            SoundManager::Instance()->playSound("attack",0);
            currentFrame = ((SDL_GetTicks()/(1000/14))%num_frames);
            goto j;
    }

    if(moveLeft){
            if(run)velocity.setX(-15);
            else
            velocity.setX(-10);
            currentFrame = ((SDL_GetTicks()/(1000/8))%num_frames);
            flip = true;
    }
    if(moveRight){
            if(run)velocity.setX(15);
            else
            velocity.setX(10);
            currentFrame = ((SDL_GetTicks()/(1000/8))%num_frames);
            flip = false;
    }
    if(!moveLeft and !moveRight){
            velocity.setX(0);
            currentFrame = 7;
    }
    j:
    if(position.getY() < lastsafepos.getY()-jumpheight)
    {

        jumping = false;
        currentRow = 0;
        num_frames = 7;
    }
    if(!jumping){

            velocity.setY(16);
            }
    else {
            currentRow=2;
            num_frames=3;
            currentFrame = ((SDL_GetTicks()/(1000/2))%num_frames);
            velocity.setY(-16);
    }
    handleMovement(velocity);

}


void Player::handleInput()
{
    if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_D)/* and position.getX()<mapWidth*/){
        moveLeft = false;
        moveRight = true;
    }

    else if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_A)and position.getX()>420)
    {
        moveLeft = true;
        moveRight = false;
    }
    else{
        moveLeft = false;
        moveRight = false;
    }
    if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_LCTRL))run = true;
    if(!InputHandler::Instance()->isKeyDown(SDL_SCANCODE_LCTRL))run = false;
    if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_SPACE) and can_jump and !jump_pressed)
    {

        jumping = true;
        can_jump = false;
        lastsafepos = position;
        jump_pressed = true;
        if(jump_pressed) SoundManager::Instance()->playSound("jump",0);
    }
   if(!InputHandler::Instance()->isKeyDown(SDL_SCANCODE_SPACE) and can_jump)
    {

        jump_pressed = false;
    }
   if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_RETURN) and can_attack)
   {

       currentFrame=0;
       attack=true;
       can_attack = false;
       num_frames = 5;
       currentRow++;

   }
   if(!InputHandler::Instance()->isKeyDown(SDL_SCANCODE_RETURN))
   {
       attack = false;
       can_attack = true;
       num_frames = 7;
       currentRow = 0;
   }

}


void Player::boom()
{
    currentRow=1;
    currentFrame=7;
    health-=10;
    if(health<=0){
            dead = true;
           if(dead == true){
            Mix_Volume(-1,MIX_MAX_VOLUME/50);
            SoundManager::Instance()->playSound("death",0);
            SoundManager::Instance()->playSound("death",0);
            SoundManager::Instance()->playSound("death",0);
           Mix_Volume(-1,MIX_MAX_VOLUME);
          SoundManager::Instance()->stopMusic();
         Game::Instance()->getGameStateMachine()->changeState(new GameOverState());
         }
}

}
