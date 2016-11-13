#ifndef LAYER_H
#define LAYER_H
#include<vector>
#include"Vector2D.h"
class Layer
{
    public:
        Layer();
        virtual ~Layer();
        virtual void render() = 0;
        virtual void update() = 0;
        virtual std::vector<std::vector<int> > getTileIDs() = 0;
        virtual vector2D getPosition() = 0;
        virtual int getTileSize()=0;
        virtual void change(int,int)=0;
    protected:
    private:

};

#endif // LAYER_H
