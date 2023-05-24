#pragma once
#include "InterfaceObject.h"
#include "StartButton.h"
#include "HighscoresButton.h"
#include <vector>

class GameOverScreen : public InterfaceObject
{
public:
	GameOverScreen(int x, int y, int width, int height, std::string texturePath, StartButton* startButton, HighscoresButton* highscoresButton, std::vector<InterfaceObject*>& allInterfaceObjects, bool &isGameLost)
	:InterfaceObject(x, y, width, height, texturePath), isGameLost(isGameLost) , allInterfaceObjects(allInterfaceObjects), startButton(startButton), highscoresButton(highscoresButton){}

	void onClick()
	{
		while (!allInterfaceObjects.empty())
		{
			if (allInterfaceObjects.back() != this)
			{
				delete allInterfaceObjects.back();
			}
			allInterfaceObjects.pop_back();
		}

		isGameLost = false;
		startButton->setIsGameStarted(false);
		allInterfaceObjects.push_back(startButton);
		allInterfaceObjects.push_back(highscoresButton);

		delete this;
	}


private:
	StartButton* startButton;;
	HighscoresButton* highscoresButton;
	bool& isGameLost;
	std::vector<InterfaceObject*>& allInterfaceObjects;
	
};