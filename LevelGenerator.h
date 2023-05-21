#pragma once
#include "InterfaceObject.h"
#include <vector>
#include "Texture.h"
#include "Rocket.h"
#include "Ball.h"
#include "Block.h"
#include "BallBlock.h"
#include "BackGround.h"
#include "Text.h"
class LevelGenerator
{
public:
	LevelGenerator(std::vector<GameObject*>& allSceneObjects, std::vector<InterfaceObject*>& allInterfaceObjects):
	allInterfaceObjects(allInterfaceObjects), allSceneObjects(allSceneObjects),currentLevel(1){};

	void setPointsPtr(Text* ptr)
	{
		pointsPtr = ptr;
	}
	void generate()
	{

		int size = allSceneObjects.size();
		for (int i = 0; i < size; i++)
		{
			allSceneObjects.pop_back();
		}
		if (currentLevel == 1)
		{
			Texture* texture = new Texture("res/textures/rocket.png");
			Texture* texture2 = new Texture("res/textures/ball.png");
			Texture* texture3 = new Texture("res/textures/block.png");
			//Texture* texture4 = new Texture("res/textures/BallBlock.png");

			allSceneObjects.push_back(new Background("res/textures/backgroundAnimation", texture2, 28));

			allSceneObjects.push_back(new Rocket(0, 440, 120, 30, texture, "res/textures/rocketAnimation", 43, player));
			allSceneObjects.push_back(new Ball(200, 300, 40, 40, texture2, 4, 4, "res/textures/ballAnimation", 15));

			for (int i = 0; i < 9; i++)
			{
				allSceneObjects.push_back(new Block(50 + i * 60, 200, 60, 30, texture3, 2, pointsPtr));
			}
		}
		else if (currentLevel == 2)
		{

			Texture* texture = new Texture("res/textures/rocket.png");
			Texture* texture2 = new Texture("res/textures/ball.png");
			Texture* texture3 = new Texture("res/textures/block.png");
			Texture* texture4 = new Texture("res/textures/BallBlock.png");

			allSceneObjects.push_back(new Background("res/textures/backgroundAnimation", texture2, 28));

			allSceneObjects.push_back(new Rocket(0, 440, 120, 30, texture, "res/textures/rocketAnimation", 43, player));
			allSceneObjects.push_back(new Ball(200, 300, 40, 40, texture2, 4, 4, "res/textures/ballAnimation", 15));

			for (int i = 0; i < 9; i++)
			{
				allSceneObjects.push_back(new Block(50 + i * 60, 200, 60, 30, texture3, 2, pointsPtr));
			}
			for (int i = 0; i < 5; i++)
			{
				allSceneObjects.push_back(new BallBlock(50 + i * 120, 150, 60, 30, texture4, 2, allSceneObjects, pointsPtr));
			}

		}
		else if (currentLevel == 3)
		{

		}
		else if (currentLevel == 4)
		{

		}
		else if (currentLevel == 5)
		{

		}

	}
	void increaseLevel()
	{
		currentLevel++;
	}

protected:
	std::vector<GameObject*>& allSceneObjects;
	std::vector<InterfaceObject*>& allInterfaceObjects;
	Text* pointsPtr;
	int currentLevel;
};