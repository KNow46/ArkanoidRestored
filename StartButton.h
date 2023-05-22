#include "InterfaceObject.h"
#include <vector>
#include "Texture.h"
#include "Rocket.h"
#include "Ball.h"
#include "Block.h"
#include "BallBlock.h"
#include "BackGround.h"
#include "Text.h"
#include "LevelGenerator.h"
class StartButton : public InterfaceObject
{
public:
	StartButton(int x, int y, int height, int width, const Texture* texture, std::vector<InterfaceObject*>& allInterfaceObjects, const Texture* hoverTexture, LevelGenerator& levelGenerator)
		:InterfaceObject(x, y, height, width, texture, hoverTexture), allInterfaceObjects(allInterfaceObjects), levelGenerator(levelGenerator), gameIsStarted(false){};


	void onClick()
	{
		gameIsStarted = true;
		isDestroyed = true;
		while (!allInterfaceObjects.empty()) 
		{
			if (allInterfaceObjects.back() != this)
			{
				delete allInterfaceObjects.back();
			}
			allInterfaceObjects.pop_back();
		}

		Texture* pointsBackground = new Texture("res/textures/textBackgroundGray.png");
		Text* points = new Text(500, 29, 100, 20, pointsBackground, "0", 10, Text::points);
		pointsPtr = points;
		allInterfaceObjects.push_back(points);

		levelGenerator.setPointsPtr(pointsPtr);
		levelGenerator.generate();
	}
	Text* getPointsPtr() { return pointsPtr; }
	bool isGameStarted()
	{
		return gameIsStarted;
	}
protected:

	std::vector<InterfaceObject*> &allInterfaceObjects;
	Text* pointsPtr;
	LevelGenerator& levelGenerator;
	bool gameIsStarted;
};