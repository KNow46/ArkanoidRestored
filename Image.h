#pragma once
#include "InterfaceObject.h"
class Image : public InterfaceObject
{
public:
	Image(int x, int y, int height, int width, const Texture* texture, const Texture* hoverTexture)
		:InterfaceObject(x, y, height, width, texture, hoverTexture) {}

	Image(int x, int y, int height, int width, const Texture* texture)
		:InterfaceObject(x, y, height, width, texture) {}

	void ballCollisionEffect() {};
};