#pragma once
#include "GameObject.h"
#include <string>
#include "MyContainer.h"

class Ball : public GameObject
{
public:
    Ball(int x, int y, int height, int width, float speedX, float speedY, std::string animationPath, int framesCount);
    
    ~Ball();

    void move();

    void rotate();

    void ballCollisionEffect();

    void horizontalReflection();

    void verticalReflection();

    const Texture* getTexture();

    void setSpeedX(double x);

    void setSpeedY(double y);

    void setAngle(double x);

    float getSpeedY();

    float getSpeedX();

    float getBaseXSpeed();

    float getBaseYSpeed();

private:
    double speedX;
    double speedY;
    double speed;
    double baseSpeedX;
    double baseSpeedY;
    double baseSpeed;
    double angle;
    int framesCounter;
    int framesCount;
    std::string animationPath;
    MyContainer<Texture*> frames;
 
};
