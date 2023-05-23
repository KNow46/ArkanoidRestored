#include "Ball.h"
#include <cmath>
#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include <windows.h>
#include <mmsystem.h>
#include "Global.h"

Ball::Ball(int x, int y, int height, int width, const Texture* texture, float speedX, float speedY, std::string animationPath, int framesCount)
    : GameObject(x, y, height, width, texture), speedX(speedX), speedY(speedY), baseSpeedX(speedX), baseSpeedY(speedY),
    framesCounter(-1), framesCount(framesCount), frames(MyContainer<Texture*>())
{
    speed = sqrt(speedX * speedX + speedY * speedY);
    double tg = speedY / speedX;
    for (int i = 0; i < framesCount; i++)
    {
        std::string filename = animationPath + "/frame" + std::to_string(i + 1) + ".png";
        Texture* bgFrame = new Texture(filename);
        frames.push_front(bgFrame);
    }
}

const Texture* Ball::getTexture()
{
    if (framesCounter >= 4 * (framesCount - 1))
        framesCounter = 0;
    framesCounter++;
    return frames[framesCounter / 4];
}

void Ball::rotate()
{
    double xSpeedTmp = speedX;
    speedX = speedX * cos(angle * M_PI / 180.0) - speedY * sin(angle * M_PI / 180.0);
    speedY = xSpeedTmp * sin(angle * M_PI / 180.0) + speedY * cos(angle * M_PI / 180.0);

    angle *= 0.99;
}

void Ball::move()
{
    x += speedX;
    y += speedY;
    rotate();
    if (abs(speedY) < 0.5 * abs(baseSpeedY))
    {
        if (speedY < 0)
        {
            speedY = -0.5 * abs(baseSpeedY);
        }
        else
        {
            speedY = 0.5 * abs(baseSpeedY);
        }
    }
    if (y > windowHeight + 100)
    {
        isDestroyed = true;
    }
}

void Ball::setSpeedX(double x)
{
    this->speedX = x;
}

void Ball::setSpeedY(double y)
{
    this->speedY = y;
}

void Ball::setAngle(double x)
{
    angle = x;
}

float Ball::getSpeedY()
{
    return speedY;
}

float Ball::getSpeedX()
{
    return speedX;
}

float Ball::getBaseXSpeed()
{
    return baseSpeedX;
}

float Ball::getBaseYSpeed()
{
    return baseSpeedY;
}

void Ball::ballCollisionEffect()
{
}

void Ball::horizontalReflection()
{
    if (speedX > 0)
        speedX = -abs(baseSpeedX);
    else
        speedX = abs(baseSpeedX);

    angle = -angle;
}

void Ball::verticalReflection()
{
    if (speedY < 0)
        speedY = abs(baseSpeedY);
    else
        speedY = -abs(baseSpeedY);
    angle = -angle;
}

Ball::~Ball()
{
    int size = frames.getSize();
    for (int i = 0; i < size; i++)
    {
        delete frames[i];
    }
}
