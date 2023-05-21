#pragma once
#include "Texture.h"
#include "GameObject.h"
#include <vector>
#include "BlockCrack.h"
#include "Text.h"
#include <string>
class Block: public GameObject
{
public:
	Block(int x, int y, int height, int width, const Texture* texture, int hp, Text* points)
		:GameObject(x, y, height, width, texture), hp(hp), crackTexture(new Texture("res/textures/crack.png")), points(points){};

	virtual void ballCollisionEffect(int damage);
	void ballCollisionEffect() {};
	void addCrack(int x, int y);
	std::vector<BlockCrack*> getCracks();
	BlockCrack *getCrackAtIndex(int index);
	static void SetPlayerPoints(int* points)
	{
		playerPoints = points;
	}
protected:
	int hp;
	Texture* crackTexture;
	std::vector<BlockCrack*> cracks;
	static int* playerPoints;
	Text* points;

};