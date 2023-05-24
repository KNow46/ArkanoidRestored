#include "Background.h"

Background::Background(std::string animationPath, int framesCount)
    : GameObject(0, 0, windowWidth, windowHeight, "res/textures/empty.png"), framesCounter(-1), framesCount(framesCount), frames(MyContainer<Texture*>())
{
    for (int i = 0; i < framesCount; i++)
    {
        std::string filename = animationPath + "/frame" + std::to_string(i + 1) + ".png";
        Texture* bgFrame = new Texture(filename);
        frames.push_front(bgFrame);
    }
}

const Texture* Background::getTexture()
{
    if (framesCounter >= 4 * (framesCount - 1))
        framesCounter = 0;
    framesCounter++;
    return frames[framesCounter / 4];
}

Background::~Background()
{
    int size = frames.getSize();
    for (int i = 0; i < size; i++)
    {
        delete frames[i];
    }
}

void Background::ballCollisionEffect()
{
    // implementation in child classes
}