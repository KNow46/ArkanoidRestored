#pragma once
#include "GameObject.h"
#include "Texture.h"
#include <string>
#include "Global.h"
#include <vector>
#include <sstream>
#include <forward_list>
#include "MyContainer.h"

class Background : public GameObject
{
public:
    Background(std::string animationPath, const Texture* basicTexture, int framesCount);

    const Texture* getTexture();

    ~Background();

private:
    int framesCounter;
    int framesCount;
    std::string animationPath;
    MyContainer<Texture*> frames;

    void ballCollisionEffect();
};