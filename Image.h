#pragma once
#include "GameObject.h"

class Image : public GameObject
{
public:
	Image(int x, int y, int height, int width, const Texture* texture)
		:GameObject(x, y, height, width, texture) {};
	void ballCollisionEffect() {};

};