#pragma once
#include "GameObject.h"
#include "Texture.h"
#include <string>
#include "Global.h"
#include <vector>
#include <sstream>
#include <forward_list>
#include "MyContainer.h"
class Background : public GameObject
{
public:
	Background(std::string animationPath, const Texture * basicTexture, int framesCount) 
		:GameObject(0, 0, windowWidth, windowHeight, basicTexture), framesCounter(-1), framesCount(framesCount), frames(MyContainer<Texture*>())
	{
		for (int i = 0; i < framesCount; i++)
		{
			std::string filename = animationPath + "/frame" + std::to_string(i + 1) + ".png";
			Texture* bgFrame= new Texture(filename);
			frames.push_front(bgFrame);
		}
	};

	const Texture * getTexture() 
	{ 
		if (framesCounter >=  4* (framesCount-1))
			framesCounter = 0;
		framesCounter++;
		return frames[framesCounter / 4];
		
		
	};
	~Background()
	{
		int size = frames.getSize();
		for (int i = 0; i < size; i++)
		{
			delete frames[i];
		}
	}
private:
	int framesCounter;
	int framesCount;
	std::string animationPath;
	MyContainer<Texture*> frames;
	void ballCollisionEffect() {};
};