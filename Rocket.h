#pragma once
#include "GameObject.h"
#include <string>
#include "MyContainer.h"
#include <cmath>
enum owner{player, enemy};
class Rocket: public GameObject
{
public:
	Rocket(int x, int y, int height, int width, const Texture* texture, std::string animationPath, int framesCount, owner owner)
		:GameObject(x, y, height, width, texture), framesCounter(-1), framesCount(framesCount), frames(MyContainer<Texture*>())
	{
		for (int i = 0; i < framesCount; i++)
		{
			std::string filename = animationPath + "/frame" + std::to_string(i + 1) + ".png";
			Texture* bgFrame = new Texture(filename);
			frames.push_front(bgFrame);
		}
	};
	void setSpeed(double x)
	{
		speed = x;

	}
	const Texture* getTexture()
	{
		framesCounter+=3;

		if (framesCounter >=   (framesCount - 1))
			framesCounter = 0;
		
		return frames[(framesCounter) ];


	};
	double getSpeed() { return speed; }
	owner getOwner()
	{
		return owner;
	}
	~Rocket()
	{
		int size = frames.getSize();
		for (int i = 0; i < size; i++)
		{
			delete frames[i];
		}
	}
private:
	double speed;
	int framesCounter;
	int framesCount;
	std::string animationPath;
	MyContainer<Texture*> frames;
	owner owner;
	//inline void setX(float x) { this->x = x;};
	void  ballCollisionEffect() {};

};