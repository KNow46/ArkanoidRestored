#include "Rocket.h"

Rocket::Rocket(int x, int y, int height, int width, std::string animationPath, int framesCount, owner owner)
    : GameObject(x, y, height, width, "res/textures/empty.png"), framesCounter(-1), framesCount(framesCount), frames(MyContainer<Texture*>()), speed(0), rocketOwner(owner)
{
    for (int i = 0; i < framesCount; i++)
    {
        std::string filename = animationPath + "/frame" + std::to_string(i + 1) + ".png";
        Texture* bgFrame = new Texture(filename);
        frames.push_front(bgFrame);
    }
}
void Rocket::setSpeed(double x)
{
    speed = x;
}

const Texture* Rocket::getTexture()
{
    framesCounter += 3;

    if (framesCounter >= (framesCount - 1))
        framesCounter = 0;

    return frames[(framesCounter)];
}

double Rocket::getSpeed()
{
    return speed;
}

owner Rocket::getOwner()
{
    return rocketOwner;
}

Rocket::~Rocket()
{
    int size = frames.getSize();
    for (int i = 0; i < size; i++)
    {
        delete frames[i];
    }
}

void Rocket::ballCollisionEffect()
{

}