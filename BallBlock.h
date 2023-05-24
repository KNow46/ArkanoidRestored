#pragma once
#include <vector>
#include "Block.h"
#include "Ball.h"
#include "Text.h"

class BallBlock : public Block
{
public:
	BallBlock(int x, int y, int height, int width, std::string texturePath, int hp, std::vector <GameObject*>& allSceneObjects, Text* points);

	virtual void ballCollisionEffect(int damage);

protected:
	std::vector<GameObject*> &allSceneObjects;
};