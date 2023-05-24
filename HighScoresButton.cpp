#include "HighScoresButton.h"
#include "Text.h"
#include <fstream>
#include "BackButton.h"
#include "Image.h"
#include "Global.h"
#include "StartButton.h"
HighscoresButton::HighscoresButton(int x, int y, int height, int width, std::string texturePath, std::string textureHoveredPath, std::vector<InterfaceObject*>& allInterfaceObjects, LevelGenerator& levelGenerator)
    : InterfaceObject(x, y, height, width, texturePath, textureHoveredPath), allInterfaceObjects(allInterfaceObjects), allInterfaceObjectsCopy(allInterfaceObjects), levelGenerator(levelGenerator) {}

void HighscoresButton::onClick() {
    isDestroyed = true;
    while (!allInterfaceObjects.empty()) {
        if (allInterfaceObjects.back() != this) 
        {
            if(!dynamic_cast<StartButton*>(allInterfaceObjects.back()))
                delete allInterfaceObjects.back();
        }
        allInterfaceObjects.pop_back();
    }
    std::ifstream file("HighScores.txt");
    std::string line;

    if (file.is_open()) {
        int i = 0;
        while (std::getline(file, line)) {
            highscores[i] = std::stoi(line);
            i++;
        }
    }

    Image* highscoresTable = new Image(200, 50, windowWidth - 400, windowHeight - 100, "res/textures/highscoresTable.png");
    allInterfaceObjects.push_back(highscoresTable);

    Text* points[5];
    for (int i = 0; i < 5; i++) 
    {
        points[i] = new Text(windowWidth / 2 - 50, 100 + 60 * i, 200, 50, "0", 20, Text::none);
    }
    pointsPtr = points[0];

    for (int i = 0; i < 5; i++) {
        points[i]->changeText(std::to_string(highscores[i]));
    }
    for (int i = 0; i < 5; i++) {
        allInterfaceObjects.push_back(points[i]);
    }

    BackButton* backButton = new BackButton(50, 350, 100, 50, "res/textures/backButton.png", "res/textures/backButtonHovered.png", allInterfaceObjects,levelGenerator);
    allInterfaceObjects.push_back(backButton);

    
}