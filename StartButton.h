#pragma once
#include "InterfaceObject.h"
#include <vector>
#include "Texture.h"
#include "LevelGenerator.h"

class StartButton : public InterfaceObject
{
public:
    StartButton(int x, int y, int height, int width, std::string texturePath, std::string textureHoveredPath, std::vector<InterfaceObject*>& allInterfaceObjects, LevelGenerator& levelGenerator);

    void onClick();

    Text* getPointsPtr();

    static bool isGameStarted();

    void setIsGameStarted(bool);

protected:
    std::vector<InterfaceObject*>& allInterfaceObjects;
    Text* pointsPtr;
    LevelGenerator& levelGenerator;
    static bool gameIsStarted;
};
