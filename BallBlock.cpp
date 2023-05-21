#include "BallBlock.h"

void BallBlock::ballCollisionEffect(int damage)
{
	hp = hp - damage;
	if (hp <= 0)
	{
		isDestroyed = true;
		Texture* texture = new Texture("res/textures/ball.png");
		allSceneObjects.push_back(new Ball(x+width/2, y + height, 20, 20, texture, -4, -4, "res/textures/ballAnimation", 15));
		*playerPoints += 50;
		points->changeText(std::to_string(*playerPoints));
	}
}
