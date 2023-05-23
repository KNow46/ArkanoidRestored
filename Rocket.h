#pragma once
#include "GameObject.h"
#include <string>
#include "MyContainer.h"

enum owner { player, enemy };

class Rocket : public GameObject
{
public:
    Rocket(int x, int y, int height, int width, const Texture* texture, std::string animationPath, int framesCount, owner owner);

    void setSpeed(double x);

    const Texture* getTexture();

    double getSpeed();

    owner getOwner();

    ~Rocket();

private:
    double speed;
    int framesCounter;
    int framesCount;
    std::string animationPath;
    MyContainer<Texture*> frames;
    owner rocketOwner;

    void ballCollisionEffect();
};




