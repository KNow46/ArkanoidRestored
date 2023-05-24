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
	LevelGenerator(std::vector<GameObject*>& allSceneObjects, std::vector<InterfaceObject*>& allInterfaceObjects) :
		allInterfaceObjects(allInterfaceObjects), allSceneObjects(allSceneObjects), currentLevel(1) {};

	void setPointsPtr(Text* ptr)
	{
		pointsPtr = ptr;
	}

	void setCurrentLevel(int level)
	{
		currentLevel = level;
	}
	void generate()
	{

		while(!allSceneObjects.empty())
		{
			delete allSceneObjects.back();
			allSceneObjects.pop_back();
		}
		if (currentLevel == 1)
		{

			allSceneObjects.push_back(new Background("res/textures/backgroundAnimation", 28));

			allSceneObjects.push_back(new Rocket(0, 440, 120, 30, "res/textures/rocketAnimation", 43, player));

			allSceneObjects.push_back(new Ball(200, 300, 40, 40, -4, -4, "res/textures/ballAnimation", 15));


			for (int i = 0; i < 1; i++)
			{
				allSceneObjects.push_back(new Block(50 + i * 60, 200, 60, 30, "res/textures/block.png", 2, pointsPtr));
			}
			for (int i = 0; i < 5; i++)
			{
				allSceneObjects.push_back(new BallBlock(50 + i * 120, 150, 60, 30, "res/textures/BallBlock.png", 2, allSceneObjects, pointsPtr));
			}
		}
		else if (currentLevel == 2)
		{

			allSceneObjects.push_back(new Background("res/textures/backgroundAnimation", 28));

			allSceneObjects.push_back(new Rocket(0, 440, 120, 30, "res/textures/rocketAnimation", 43, player));

			allSceneObjects.push_back(new Ball(200, 300, 40, 40, -4, -4, "res/textures/ballAnimation", 15));


			for (int i = 0; i < 9; i++)
			{
				allSceneObjects.push_back(new Block(50 + i * 60, 200, 60, 30, "res/textures/block.png", 2, pointsPtr));
			}
			for (int i = 0; i < 5; i++)
			{
				allSceneObjects.push_back(new BallBlock(50 + i * 120, 150, 60, 30, "res/textures/BallBlock.png", 2, allSceneObjects, pointsPtr));
			}

		}
		else if (currentLevel == 3)
		{

			allSceneObjects.push_back(new Background("res/textures/backgroundAnimation", 28));

			allSceneObjects.push_back(new Rocket(0, 440, 120, 30, "res/textures/rocketAnimation", 43, player));

			allSceneObjects.push_back(new Ball(200, 300, 40, 40, -4, -4, "res/textures/ballAnimation", 15));

			for (int i = 0; i < 9; i++)
			{
				allSceneObjects.push_back(new Block(50 + i * 60, 200, 60, 30, "res/textures/block.png", 2, pointsPtr));
			}
			for (int i = 0; i < 9; i++)
			{
				allSceneObjects.push_back(new Block(50 + i * 60, 250, 60, 30, "res/textures/block.png", 2, pointsPtr));
			}
		}
		else if (currentLevel == 4)
		{

			allSceneObjects.push_back(new Background("res/textures/backgroundAnimation",28));

			allSceneObjects.push_back(new Rocket(0, 440, 120, 30, "res/textures/rocketAnimation", 43, player));

			allSceneObjects.push_back(new Ball(200, 300, 40, 40, -4, -4, "res/textures/ballAnimation", 15));

			for (int i = 0; i < 9; i++)
			{
				allSceneObjects.push_back(new Block(50 + i * 60, 200, 60, 30, "res/textures/block.png", 2, pointsPtr));
			}
			for (int i = 0; i < 9; i++)
			{
				allSceneObjects.push_back(new Block(50 + i * 60, 250, 60, 30, "res/textures/block.png", 2, pointsPtr));
			}
			for (int i = 0; i < 9; i++)
			{
				allSceneObjects.push_back(new Block(50 + i * 60, 150, 60, 30, "res/textures/block.png", 2, pointsPtr));
			}
		}
		else if (currentLevel == 5)
		{
			allSceneObjects.push_back(new Background("res/textures/backgroundAnimation", 28));

			allSceneObjects.push_back(new Rocket(0, 440, 120, 30,"res/textures/rocketAnimation", 43, player));

			allSceneObjects.push_back(new Ball(200, 300, 40, 40, -4, -4, "res/textures/ballAnimation", 15));

			for (int i = 0; i < 9; i++)
			{
				allSceneObjects.push_back(new Block(50 + i * 60, 200, 60, 30, "res/textures/block.png", 2, pointsPtr));
			}
			for (int i = 0; i < 9; i++)
			{
				allSceneObjects.push_back(new Block(50 + i * 60, 250, 60, 30, "res/textures/block.png", 2, pointsPtr));
			}
			for (int i = 0; i < 9; i++)
			{
				allSceneObjects.push_back(new Block(50 + i * 60, 100, 60, 30, "res/textures/block.png", 2, pointsPtr));
			}
			for (int i = 0; i < 5; i++)
			{
				allSceneObjects.push_back(new BallBlock(50 + i * 120, 150, 60, 30, "res/textures/BallBlock.png", 2, allSceneObjects, pointsPtr));
			}
		}
		else if (currentLevel > 5)
		{
			allSceneObjects.push_back(new Block(0, 0, windowWidth, windowHeight, "res/textures/winScreen2.png", 2, pointsPtr));
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