#pragma once
#include "GameObject.h"
#include <cmath>
#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include <windows.h>
#include <mmsystem.h>
#include "MyContainer.h"
#include "Global.h"
class Ball :public GameObject
{
public:
	Ball(int x, int y, int height, int width, const Texture * texture, float speedX, float speedY, std::string animationPath, int framesCount)
		:GameObject(x, y, height, width, texture), speedX(speedX), speedY(speedY), baseSpeedX(speedX),
		baseSpeedY(speedY), framesCounter(-1), framesCount(framesCount), frames(MyContainer<Texture*>())
	{
		speed = sqrt(speedX * speedX + speedY * speedY);
		double tg = speedY / speedX ;
		for (int i = 0; i < framesCount; i++)
		{
			std::string filename = animationPath + "/frame" + std::to_string(i + 1) + ".png";
			Texture *bgFrame = new Texture(filename);
			frames.push_front(bgFrame);
		}
		
	};
	const Texture* getTexture()
	{
		if (framesCounter >= 4 * (framesCount - 1))
			framesCounter = 0;
		framesCounter++;
		return frames[framesCounter / 4];


	};
private:
	double speedX;
	double speedY;
	double speed;
	double baseSpeedX;
	double baseSpeedY;
	double baseSpeed;
	double angle = 0;
	int framesCounter;
	int framesCount;
	std::string animationPath;
	MyContainer<Texture*> frames;

	void rotate()
	{
		double xSpeedTmp = speedX;
		speedX = speedX * cos(angle * M_PI / 180.0) - speedY *sin(angle * M_PI / 180.0);
		speedY = xSpeedTmp * sin(angle * M_PI / 180.0) + speedY * cos(angle * M_PI / 180.0);

		angle *= 0.99;
	}
	
	
public:
	void move()
	{
		x += speedX;
		y += speedY;
		rotate();
		if (abs(speedY) < 0.5 * abs(baseSpeedY))
		{
			if (speedY < 0)
			{
				speedY = -0.5 * abs(baseSpeedY);
			}
			else
			{
				speedY = 0.5 * abs(baseSpeedY);
			}
		}
		if (y > windowHeight + 100)
		{
			isDestroyed = true;
		}
	}
	inline void setSpeedX(double x){ this->speedX = x; }
	inline void setSpeedY(double y) { this->speedY= y; }
	inline void setAngle(double x) { angle = x; }
	inline float getSpeedY() { return speedY; }
	inline float getSpeedX() { return speedX; }
	inline float getBaseXSpeed() { return baseSpeedX; }
	inline float getBaseYSpeed() { return baseSpeedY; }
	void ballCollisionEffect() {};
	void horizontalReflection() 
	{
		//PlaySound(TEXT("res/sounds/ball.wav"), NULL, SND_FILENAME | SND_ASYNC);
		if(speedX >0)
		speedX = -abs(baseSpeedX);
		else
		speedX = abs(baseSpeedX);

		angle =  - angle;
	};
	void verticalReflection() 
	{
		//PlaySound(TEXT("res/sounds/ball.wav"), NULL, SND_FILENAME | SND_ASYNC);
		if (speedY < 0)
			speedY = abs(baseSpeedY);
		else
			speedY = -abs(baseSpeedY);
		angle = - angle;
	};
	~Ball()
	{
		int size = frames.getSize();
		for (int i = 0; i < size; i++)
		{
			delete frames[i];
		}
	}

};
