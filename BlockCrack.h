#pragma once
#pragma once
#include "Texture.h"
#include "GameObject.h"

class BlockCrack : public GameObject
{
public:
	BlockCrack(int x, int y, int height, int width, std::string texturePath)
		:GameObject(x, y, height, width, texturePath){};

	void ballCollisionEffect() {};

private:

};