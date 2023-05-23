#pragma once
#include "InterfaceObject.h"
#include <vector>
#include "Texture.h"
#include "LevelGenerator.h"

class HighscoresButton : public InterfaceObject 
{
public:
    HighscoresButton(int x, int y, int height, int width, const Texture* texture, std::vector<InterfaceObject*>& allInterfaceObjects, const Texture* hoverTexture, LevelGenerator& levelGenerator);

    void onClick();

protected:
    std::vector<InterfaceObject*>& allInterfaceObjects;
    std::vector<InterfaceObject*> allInterfaceObjectsCopy;
    int highscores[5];
    Text* pointsPtr;
    LevelGenerator& levelGenerator;
};