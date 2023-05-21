#include "CollisionManager.h"

int upperMargin = 56;
int sideMargin = 26;

void CollisionManager::checkCollisions()
{
	//wall collisions
	for (int i = 0; i < allSceneObjects.size(); i++)
	{
		if (allSceneObjects[i] != nullptr && allSceneObjects[i]->getIsDestroyed() == false)
		{
			if (dynamic_cast<Ball*>(allSceneObjects[i]))
			{

				Ball* ball = static_cast<Ball*>(allSceneObjects[i]);
				if (ball->getX() < sideMargin)
				{
					ball->horizontalReflection();
					ball->setX(sideMargin + 5);
				}
				if(ball->getX() + ball->getWidth() > windowWidth - sideMargin)
				{
					ball->horizontalReflection();
					ball->setX(windowWidth-5- sideMargin -ball->getWidth());
				}
				if (ball->getY() < 56)
				{
					ball->verticalReflection();
					ball->setY(upperMargin + 5);
				}
				ball->move();
				//std::cout << ball->getY() <<std::endl;
				//rocket collision
				for (int i = 0; i < allSceneObjects.size(); i++)
				{
					if (allSceneObjects[i] != nullptr)
					{
						if (dynamic_cast<Rocket*>(allSceneObjects[i]))
						{
							Rocket* rocket = static_cast<Rocket*>(allSceneObjects[i]);

							if (ball->getY() + ball->getHeight() >= rocket->getY() && ball->getY() + ball->getHeight() <= rocket->getY() + ball->getHeight() * 0.6)
							{
								if (ball->getX() + ball->getWidth() * 0.7 > rocket->getX() && ball->getX() + ball->getWidth() * 0.3 < rocket->getX() + rocket->getWidth())
								{
									
									ball->verticalReflection();
									ball->setY(rocket->getY() - ball->getHeight() - 3);
									ball->setAngle(-0.01 * rocket->getSpeed());
								}
							}
						}
					}
				}
				int cornersCount = 8;
				struct corner { float x; float y; };
				corner ballCorners[8];//eight points on the ball
				//up-left
				ballCorners[0].x = ball->getX() + ball->getWidth() * 1 / 6;
				ballCorners[0].y = ball->getY() + ball->getHeight() * 1 / 6;

				//up
				ballCorners[1].x = ball->getX() + ball->getWidth() / 2;
				ballCorners[1].y = ball->getY();

				//up-right"
				ballCorners[2].x = ball->getX() + ball->getWidth() * 5 / 6;
				ballCorners[2].y = ball->getY() + ball->getHeight() * 1 / 6;

				//left"
				ballCorners[3].x = ball->getX();
				ballCorners[3].y = ball->getY() + ball->getHeight() / 2;

				//right
				ballCorners[4].x = ball->getX() + ball->getWidth();
				ballCorners[4].y = ball->getY() + ball->getHeight() / 2;

				//bottom-left
				ballCorners[5].x = ball->getX() + ball->getWidth() * 1 / 6;
				ballCorners[5].y = ball->getY() + ball->getHeight() * 5 / 6;

				//bottom
				ballCorners[6].x = ball->getX() + ball->getWidth() / 2;
				ballCorners[6].y = ball->getY() + ball->getHeight();

				//bottom-right
				ballCorners[7].x = ball->getX() + ball->getWidth() * 5 / 6;
				ballCorners[7].y = ball->getY() + ball->getHeight() * 5 / 6;
				for (int i = 0; i < allSceneObjects.size(); i++)
				{
					if (dynamic_cast<Block*>(allSceneObjects[i]) && allSceneObjects[i]->getIsDestroyed() == false)
					{
						Block* block = static_cast<Block*>(allSceneObjects[i]);

						int cornerInside = -1;
	
						for (int i = 0; i < cornersCount; i++)//checking if corner is inside of block. cornerInside = -1 if it is not
						{
							if (ballCorners[i].x >= block->getX() && ballCorners[i].x <= block->getX() + block->getWidth())
							{
								if (ballCorners[i].y >= block->getY() && ballCorners[i].y <= block->getY() + block->getHeight())
								{
									cornerInside = i;
									break;
								}

							}
						}
						if (cornerInside != -1)
						{
							float safetyTeleport = 3;

							if (cornerInside == 0) //corner number 0 collision actitions
							{
								//std::cout << 0 << std::endl << std::endl;
								//"if" is used to checking which side is closer to corner which got into collision with block
								if (abs(ballCorners[0].x - (block->getX() + block->getWidth())) < abs(ballCorners[0].y - (block->getY() + block->getHeight())))
								{
									ball->setX(block->getX() + block->getWidth() + safetyTeleport);
									ball->horizontalReflection();
								}
								else
								{
									ball->setY(block->getY() + block->getHeight() + safetyTeleport);
									ball->verticalReflection();
								}
								block->addCrack(ballCorners[0].x, ballCorners[0].y);
							}
							if (cornerInside == 2)//corner number 2 collision actitions
							{
								//std::cout << 2 << std::endl << std::endl;
								if (abs(ballCorners[2].x - block->getX()) < abs(ballCorners[2].y - (block->getY() + block->getHeight())))
								{
									ball->setX(block->getX() - ball->getWidth() - safetyTeleport);
									ball->horizontalReflection();
								}
								else
								{
									ball->setY(block->getY() + block->getHeight() + safetyTeleport);
									ball->verticalReflection();
								}
								block->addCrack(ballCorners[2].x, ballCorners[2].y);
							}
							if (cornerInside == 5)
							{
								//std::cout << 5 << std::endl << std::endl;
								if (abs(ballCorners[5].x - (block->getX() + block->getWidth())) < abs(ballCorners[5].y - block->getY()))
								{
									ball->setX(block->getX() + block->getWidth() + safetyTeleport);
									ball->horizontalReflection();
								}
								else
								{
									ball->setY(block->getY() - ball->getHeight() - safetyTeleport);
									ball->verticalReflection();
								}
								block->addCrack(ballCorners[5].x, ballCorners[5].y);
							}
							if (cornerInside == 7)
							{
								//std::cout << 7 << std::endl << std::endl;
								if (abs(ballCorners[7].x - block->getX()) < abs(ballCorners[7].y - block->getY()))
								{
									ball->setX(block->getX() - ball->getWidth() - safetyTeleport);
									ball->horizontalReflection();
								}
								else
								{
									ball->setY(block->getY() - ball->getHeight() - safetyTeleport);
									ball->verticalReflection();
								}
								block->addCrack(ballCorners[7].x, ballCorners[7].y);
							}
							if (cornerInside == 1)
							{
								//std::cout << 1 << std::endl << std::endl;
								block->addCrack(ballCorners[1].x, ballCorners[1].y);

								ball->verticalReflection();
								ball->setY(block->getY() + block->getHeight() + safetyTeleport);
							}
							if (cornerInside == 3)
							{
								//std::cout << 3 << std::endl << std::endl;
								block->addCrack(ballCorners[3].x, ballCorners[3].y);

								ball->horizontalReflection();
								ball->setX(block->getX() + block->getWidth() + safetyTeleport);
								
							}
							if (cornerInside == 4)
							{
								//std::cout << 4 << std::endl << std::endl;
								block->addCrack(ballCorners[4].x, ballCorners[4].y);

								ball->horizontalReflection();
								ball->setX(block->getX() - ball->getWidth() - safetyTeleport);

							}
							if (cornerInside == 6)
							{
								//std::cout << 6 << std::endl << std::endl;

								block->addCrack(ballCorners[6].x, ballCorners[6].y);

								ball->verticalReflection();
								ball->setY(block->getY() - ball->getHeight() - safetyTeleport);
							}
							{
								block->ballCollisionEffect(1); //hitting block
							}
						}
					}
				}


			}
		}
	}


}

