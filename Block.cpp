#include "Block.h"
int* Block::playerPoints = new int(0);

void Block::ballCollisionEffect(int damage)
{
	hp = hp - damage;
	if (hp <= 0)
	{
		*playerPoints += 30;
		points->changeText(std::to_string(*playerPoints));
		isDestroyed = true;
	}
}

void Block::addCrack(int x, int y)
{
		BlockCrack * blockCrack = new BlockCrack(x-15, y-15, 30, 30, crackTexturePath);
		cracks.push_back(blockCrack);

}

std::vector<BlockCrack*> Block::getCracks()
{
	return cracks;
}

BlockCrack* Block::getCrackAtIndex(int index)
{
	return cracks[index];
}

