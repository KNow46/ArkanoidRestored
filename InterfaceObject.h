#pragma once
#include "GameObject.h"
#include <functional>
class InterfaceObject : public GameObject
{
public:
	InterfaceObject(int x, int y, int height, int width, const Texture* texture, const Texture* hoverTexture)
		:GameObject(x, y, height, width, texture),  isHovered(0), hoverTexture(hoverTexture) {};
	InterfaceObject(int x, int y, int height, int width, const Texture* texture)
		:GameObject(x, y, height, width, texture), isHovered(0), hoverTexture(texture) {};

	virtual void onClick() {};
	void ballCollisionEffect() {};
	
	void setIsHovered(bool isHovered)
	{
		this->isHovered = isHovered;
	}
	virtual const Texture* getTexture()
	{ 
		if (isHovered == false)
			return texture;
		else
			return hoverTexture;
	};
protected:
	//bool isVisible;
	bool isHovered;
	const Texture* hoverTexture;
};