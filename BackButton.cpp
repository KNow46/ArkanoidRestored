#include "BackButton.h"
#include "StartButton.h"
#include "HighScoresButton.h"
#include "Text.h"

BackButton::BackButton(int x, int y, int height, int width, const Texture* texture, std::vector<InterfaceObject*>& allInterfaceObjects, const Texture* hoverTexture, LevelGenerator& levelGenerator)
    : InterfaceObject(x, y, height, width, texture, hoverTexture), allInterfaceObjects(allInterfaceObjects), levelGenerator(levelGenerator) {}

void BackButton::onClick() 
{

    isDestroyed = true;
    while (!allInterfaceObjects.empty()) 
    {
        if (allInterfaceObjects.back () != this) 
        {
            delete allInterfaceObjects.back();
        }
        allInterfaceObjects.pop_back();
    }

    Texture* startButtonTexture = new Texture("res/textures/startButton.png");
    Texture* startButtonHoveredTexture = new Texture("res/textures/startButtonHovered.png");

    StartButton* startButton = new StartButton(windowWidth / 2 - 75, 100, 150, 80, startButtonTexture, allInterfaceObjects, startButtonHoveredTexture, levelGenerator);
    allInterfaceObjects.push_back(startButton);

    Texture* highscoresButtonTexture = new Texture("res/textures/highscoresButton.png");
    Texture* highscoresButtonHoveredTexture = new Texture("res/textures/highscoresButtonHovered.png");
    HighscoresButton* highscoresButton = new HighscoresButton(windowWidth / 2 - 75, 200, 150, 80, highscoresButtonTexture, allInterfaceObjects, highscoresButtonHoveredTexture, levelGenerator);
    allInterfaceObjects.push_back(highscoresButton);
}