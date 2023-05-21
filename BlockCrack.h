#pragma once
#pragma once
#include "Texture.h"
#include "GameObject.h"

class BlockCrack : public GameObject
{
public:
	BlockCrack(int x, int y, int height, int width, const Texture* texture)
		:GameObject(x, y, height, width, texture){};

	void ballCollisionEffect() {};

private:

};