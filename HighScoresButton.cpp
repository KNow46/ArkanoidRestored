#include "HighScoresButton.h"
#include "Text.h"
#include <fstream>
#include "BackButton.h"
#include "Image.h"
#include "Global.h"
HighscoresButton::HighscoresButton(int x, int y, int height, int width, const Texture* texture, std::vector<InterfaceObject*>& allInterfaceObjects, const Texture* hoverTexture, LevelGenerator& levelGenerator)
    : InterfaceObject(x, y, height, width, texture, hoverTexture), allInterfaceObjects(allInterfaceObjects), allInterfaceObjectsCopy(allInterfaceObjects), levelGenerator(levelGenerator) {}

void HighscoresButton::onClick() {
    isDestroyed = true;
    while (!allInterfaceObjects.empty()) {
        if (allInterfaceObjects.back() != this) {
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

    Texture* highscoresTableTexture = new Texture("res/textures/highscoresTable.png");
    Image* highscoresTable = new Image(200, 50, windowWidth - 400, windowHeight - 100, highscoresTableTexture);
    allInterfaceObjects.push_back(highscoresTable);

    Text* points[5];
    for (int i = 0; i < 5; i++) 
    {
        Texture* pointsBackground = new Texture("res/textures/empty.png");
        points[i] = new Text(windowWidth / 2 - 50, 100 + 60 * i, 200, 50, pointsBackground, "0", 20, Text::none);
    }
    pointsPtr = points[0];

    for (int i = 0; i < 5; i++) {
        points[i]->changeText(std::to_string(highscores[i]));
    }
    for (int i = 0; i < 5; i++) {
        allInterfaceObjects.push_back(points[i]);
    }

    Texture* backButtonTexture = new Texture("res/textures/backButton.png");
    Texture* backButtonHoveredTexture = new Texture("res/textures/backButtonHovered.png");
    BackButton* backButton = new BackButton(50, 350, 100, 50, backButtonTexture, allInterfaceObjects, backButtonHoveredTexture, levelGenerator);
    allInterfaceObjects.push_back(backButton);

    
}