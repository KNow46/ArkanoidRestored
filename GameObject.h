#pragma once
#include <string>
#include <iostream>
#include "Texture.h"

class GameObject
{
public:
    GameObject(int x, int y,int width, int height,  const Texture *texture )
        :x(x), y(y), height(height), width(width), texture(texture), graphicTransition({ 0,0 }), isDestroyed(false) {};
    

protected:
    bool isDestroyed;
    int height;
    int width;
    const Texture* texture;

    struct graphicTransition //if in file object isn't in the middle of canvas
    {
        int x, y;
    };
    graphicTransition  graphicTransition;

    int graphicLayerImportance; //for example 0 - background
    double x;
    double y;
public:

    virtual void ballCollisionEffect() = 0;
    inline int getHeight() { return height; };
    inline int getWidth() { return width; };
    inline int getX() { return x; };
    inline int getY() { return y; };
    inline void setX(float xx) { x = xx; };
    inline void setY(float yy) { y = yy; };
    virtual void onClick() {};
    inline bool getIsDestroyed() { return isDestroyed; };
    virtual const Texture * getTexture () { return texture; };
    ~GameObject() { delete texture; };
    /*enum objectCollisionType
    {
        noCollision,
        collision
    };
    objectCollisionType objectCollisionType;
    virtual void ballCollision();*/

};
