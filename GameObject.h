#pragma once
#include <string>
#include <iostream>
#include "Texture.h"

class GameObject
{
public:
    GameObject(int x, int y,int width, int height,  const Texture *texture )
        :x(x), y(y), height(height), width(width), texture(texture), isDestroyed(false) {};

    ~GameObject() { delete texture; };

    virtual void ballCollisionEffect() = 0;

    inline int getHeight() { return height; };

    inline int getWidth() { return width; };

    inline int getX() { return x; };

    inline int getY() { return y; };

    inline void setX(float x) { this->x = x; };

    inline void setY(float y) { this->y = y; };

    virtual void onClick() {};

    inline bool getIsDestroyed() { return isDestroyed; };

    virtual const Texture* getTexture() { return texture; };

protected:
    bool isDestroyed;
    int height;
    int width;
    const Texture* texture;
   // int graphicLayerImportance; //for example 0 - background
    double x;
    double y;


};
