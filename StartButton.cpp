#include "StartButton.h"

bool StartButton::gameIsStarted = false;

StartButton::StartButton(int x, int y, int height, int width, std::string texturePath, std::string textureHoveredPath, std::vector<InterfaceObject*>& allInterfaceObjects, LevelGenerator& levelGenerator)
    : InterfaceObject(x, y, height, width, texturePath, textureHoveredPath), allInterfaceObjects(allInterfaceObjects), levelGenerator(levelGenerator)
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

    Text* points = new Text(500, 29, 100, 20, "0", 10, Text::points);
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
