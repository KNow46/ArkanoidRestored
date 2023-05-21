#pragma once
#include <vector>
#include "Block.h"
#include "Ball.h"
#include "Text.h"

class BallBlock : public Block
{
public:
	BallBlock(int x, int y, int height, int width, const Texture* texture, int hp, std::vector <GameObject*> &allSceneObjects, Text* points)
	:Block(x, y, height, width, texture, hp, points), allSceneObjects(allSceneObjects)
	{ };
	virtual void ballCollisionEffect(int damage);
protected:
	std::vector<GameObject*> &allSceneObjects;
};