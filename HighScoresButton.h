#pragma once
#include <vector>
#include <fstream>
#include "InterfaceObject.h"
#include "Texture.h"
#include "Rocket.h"
#include "Ball.h"
#include "Block.h"
#include "BallBlock.h"
#include "BackGround.h"
#include "Text.h"

class HighscoresButton : public InterfaceObject
{
public:
	HighscoresButton(int x, int y, int height, int width, const Texture* texture, std::vector<InterfaceObject*>& allInterfaceObjects, const Texture* hoverTexture)
		:InterfaceObject(x, y, height, width, texture, hoverTexture), allInterfaceObjects(allInterfaceObjects), allInterfaceObjectsCopy(allInterfaceObjects){};


	void onClick()
	{
		isDestroyed = true;
		while (!allInterfaceObjects.empty())
		{
			if (allInterfaceObjects.back() != this)
			{
				delete allInterfaceObjects.back();
			}
			allInterfaceObjects.pop_back();
		}

		std::ifstream file("HighScores.txt");
		std::string line;

		if (file.is_open())
		{
			int i = 0;
			while (std::getline(file, line))
			{
				highscores[i] = std::stoi(line);
				i++;
			}
		}

		Text* points[5];
		Texture* pointsBackground = new Texture("res/textures/textBackgroundGray.png");
		for (int i = 0; i < 5; i++)
		{
			points[i] = new Text(windowWidth / 2 - 100, 100+60*i, 200, 50, pointsBackground, "0", 30, Text::none);
			
		}
		pointsPtr = points[0];

		for (int i = 0; i < 5; i++)
		{
			points[i]->changeText(std::to_string(highscores[i]));
		}
		for (int i = 0; i < 5; i++)
		{
			allInterfaceObjects.push_back(points[i]);
		}

	}
protected:
	std::vector<InterfaceObject*>& allInterfaceObjects;
	std::vector<InterfaceObject*> allInterfaceObjectsCopy;
	int highscores[5];
	Text* pointsPtr;

};