#pragma once
#include <iostream>
#include <vector>
#include "GameObject.h"
#include "Ball.h"
#include "Rocket.h"
#include "Global.h"
#include "Block.h"

class CollisionManager
{
public:
	CollisionManager(const std::vector<GameObject*> &v) : allSceneObjects(v), bounceTimer(0) {};
	void checkCollisions();

private:
	int bounceTimer;
	const std::vector<GameObject*> &allSceneObjects;

};