#pragma once
#include "InterfaceObject.h"
#include <vector>
#include "Texture.h"
#include "LevelGenerator.h"

class BackButton : public InterfaceObject {
public:
    BackButton(int x, int y, int height, int width, std::string texturePath, std::string textureHoveredPath, std::vector<InterfaceObject*>& allInterfaceObjects, LevelGenerator& levelGenerator);

    void onClick();

protected:
    std::vector<InterfaceObject*>& allInterfaceObjects;
    Text* pointsPtr;
    LevelGenerator& levelGenerator;
};