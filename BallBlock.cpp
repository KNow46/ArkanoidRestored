#include "BallBlock.h"

BallBlock::BallBlock(int x, int y, int height, int width, std::string texturePath, int hp, std::vector <GameObject*>& allSceneObjects, Text* points)
	:Block(x, y, height, width, texturePath, hp, points), allSceneObjects(allSceneObjects) {};

void BallBlock::ballCollisionEffect(int damage)
{
	hp = hp - damage;
	if (hp <= 0)
	{
		isDestroyed = true;
		Texture* texture = new Texture("res/textures/ball.png");
		allSceneObjects.push_back(new Ball(x+width/2, y + height, 20, 20, -4, -4, "res/textures/ballAnimation", 15));
		*playerPoints += 50;
		points->changeText(std::to_string(*playerPoints));
	}
}
