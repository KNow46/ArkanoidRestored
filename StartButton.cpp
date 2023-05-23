#include "StartButton.h"

StartButton::StartButton(int x, int y, int height, int width, const Texture* texture, std::vector<InterfaceObject*>& allInterfaceObjects, const Texture* hoverTexture, LevelGenerator& levelGenerator)
    : InterfaceObject(x, y, height, width, texture, hoverTexture), allInterfaceObjects(allInterfaceObjects), levelGenerator(levelGenerator), gameIsStarted(false)
{
}

void StartButton::onClick()
{
    gameIsStarted = true;
    isDestroyed = true;
    while (!allInterfaceObjects.empty())
    {
        if (allInterfaceObjects.back() != this)
        {
            delete allInterfaceObjects.back();
        }
        allInterfaceObjects.pop_back();
    }

    Texture* pointsBackground = new Texture("res/textures/textBackgroundGray.png");
    Text* points = new Text(500, 29, 100, 20, pointsBackground, "0", 10, Text::points);
    pointsPtr = points;
    allInterfaceObjects.push_back(points);

    levelGenerator.setPointsPtr(pointsPtr);
    levelGenerator.generate();
}

Text* StartButton::getPointsPtr()
{
    return pointsPtr;
}

bool StartButton::isGameStarted()
{
    return gameIsStarted;
}
