#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <string>
#include <vector>

#include "Global.h"
#include "Renderer.h"
#include "VertexBuffer.h"
#include "VertexBufferLayout.h"
#include "IndexBuffer.h"
#include "VertexArray.h"
#include "Shader.h"
#include "Texture.h"
#include "GameObject.h"
#include "Rocket.h"
#include "Ball.h"
#include "CollisionManager.h"
#include "Block.h"
#include "Background.h"
#include "MyContainer.h"
#include "BallBlock.h"
#include "Image.h"
#include "InterfaceObject.h"
#include "StartButton.h"
#include "Text.h"

//transforms to range (-1,1)
//if transforming point set length to 0
//(isX == 1) if you are transforming x coordinate
float transformToOpenGl(const float &position, const float &length, bool isX)
{
    float result = 0.0f;
    if (isX == false)
    {
        result = -((position + length / 2.0) / windowHeight * 2.0 - 1.0);
    }
    else
    {
        result = (position + length / 2.0) / windowWidth * 2.0 - 1.0;
    }
    return result;
}

void rendererScene(std::vector<GameObject*>sceneObjects, Renderer& renderer, Shader& shader, VertexArray& va, VertexBuffer& vb, VertexBufferLayout& layout, IndexBuffer& ib, GLFWwindow* window)
{
    for (int i = 0; i < sceneObjects.size(); i++)
    {
        if (sceneObjects[i]->getIsDestroyed() == false)
        {
            float positionsTransformed[] = {
            transformToOpenGl(sceneObjects[i]->getX(), 0, 1),  transformToOpenGl(sceneObjects[i]->getY() + sceneObjects[i]->getHeight(),0,0), 0.0f, 0.0f,
            transformToOpenGl(sceneObjects[i]->getX() + sceneObjects[i]->getWidth(), 0, 1) , transformToOpenGl(sceneObjects[i]->getY() + sceneObjects[i]->getHeight(),0,0), 1.0f, 0.0f,
            transformToOpenGl(sceneObjects[i]->getX() + sceneObjects[i]->getWidth(), 0, 1) , transformToOpenGl(sceneObjects[i]->getY(), 0, 0) , 1.0f, 1.0f,
             transformToOpenGl(sceneObjects[i]->getX(), 0, 1), transformToOpenGl(sceneObjects[i]->getY(), 0, 0), 0.0f, 1.0f
            };

           vb.changeData(positionsTransformed, 4 * 4 * sizeof(float));
            //va.AddBuffer(vb, layout);
           // va.Bind();
           
            sceneObjects[i]->getTexture()->Bind(1);

            renderer.Draw(va, ib, shader);

			if (dynamic_cast<Block*>(sceneObjects[i]))
			{
                Block* block = static_cast<Block*>(sceneObjects[i]);
				glEnable(GL_SCISSOR_TEST);

				glScissor(block->getX(), windowHeight - block->getY() - block->getHeight(), block->getWidth(), block->getHeight());

                std::vector<GameObject*> converted;
                for (int j = 0; j < block->getCracks().size(); j++)
                {
                    converted.push_back(block->getCrackAtIndex(j));
                }
             
                if(converted.size() > 0)
                rendererScene(converted, renderer, shader, va, vb, layout, ib, window);
                glDisable(GL_SCISSOR_TEST);
			}
        }
    }	
}
void rendererInterfaceObjects(std::vector<InterfaceObject*>interfaceObjects, Renderer& renderer, Shader& shader, VertexArray& va, VertexBuffer& vb, VertexBufferLayout& layout, IndexBuffer& ib, GLFWwindow* window)
{
    for (int i = 0; i < interfaceObjects.size(); i++)
    {
        if (interfaceObjects[i] != nullptr && interfaceObjects[i]->getIsDestroyed() == false)
        {
            float positionsTransformed[] = {
            transformToOpenGl(interfaceObjects[i]->getX(), 0, 1),  transformToOpenGl(interfaceObjects[i]->getY() + interfaceObjects[i]->getHeight(),0,0), 0.0f, 0.0f,
            transformToOpenGl(interfaceObjects[i]->getX() + interfaceObjects[i]->getWidth(), 0, 1) , transformToOpenGl(interfaceObjects[i]->getY() + interfaceObjects[i]->getHeight(),0,0), 1.0f, 0.0f,
            transformToOpenGl(interfaceObjects[i]->getX() + interfaceObjects[i]->getWidth(), 0, 1) , transformToOpenGl(interfaceObjects[i]->getY(), 0, 0) , 1.0f, 1.0f,
             transformToOpenGl(interfaceObjects[i]->getX(), 0, 1), transformToOpenGl(interfaceObjects[i]->getY(), 0, 0), 0.0f, 1.0f
            };
            vb.changeData(positionsTransformed, 4 * 4 * sizeof(float));
            va.AddBuffer(vb, layout);
            va.Bind();

            interfaceObjects[i]->getTexture()->Bind(1);

            renderer.Draw(va, ib, shader);
            if (dynamic_cast<Text*>(interfaceObjects[i]))
            {
                Text* text = dynamic_cast<Text*>(interfaceObjects[i]);
                glEnable(GL_SCISSOR_TEST);

                glScissor(text->getX(), windowHeight - text->getY() - text->getHeight(), text->getWidth(), text->getHeight());

                std::vector<GameObject*> converted;
                for (int j = 0; j < text->getText().size(); j++)
                {
                    converted.push_back(text->getTextAtIndex(j));
                }

                if (converted.size() > 0)
                    rendererScene(converted, renderer, shader, va, vb, layout, ib, window);
                glDisable(GL_SCISSOR_TEST);
            }
        }
    }
}


//void level1(std::vector<GameObject*> &allSceneObjects)
//{
//	Texture* texture = new Texture("res/textures/rocket.png");
//    Texture* texture2 = new Texture("res/textures/ball.png");
//    Texture* texture3= new Texture("res/textures/block.png");
//    Texture* texture4 = new Texture("res/textures/BallBlock.png");
//
//
//	allSceneObjects.push_back(new Rocket(0, 440, 120, 30, *texture, "res/textures/rocketAnimation", 43,player));
//	allSceneObjects.push_back(new Ball(200, 300, 40, 40, *texture2, 4, 4, "res/textures/ballAnimation", 15));
//
//	for (int i = 0; i < 9; i++)
//	{
//		allSceneObjects.push_back(new Block(50 + i * 60, 200, 60, 30, *texture3, 2));
//	}
//	for (int i = 0; i < 5; i++)
//	{
//		allSceneObjects.push_back(new BallBlock(50 + i * 120, 150, 60, 30, *texture4, 2, allSceneObjects));
//	}
//	for (int i = 0; i < 9; i++)
//	{
//		allSceneObjects.push_back(new Block(50 + i * 60, 100, 60, 30, *texture3, 2));
//	}
//
//
//	allSceneObjects.push_back(new Background("res/textures/backgroundAnimation", *texture2, 27));
//}
void clearDestroyed(std::vector <GameObject*>& allSceneObjects)
{
    std::vector<GameObject*> newAllSceneObjects;

    for(int i = allSceneObjects.size(); i > 0; i--)
    {
        if (allSceneObjects[i-1]->getIsDestroyed() == false)
        {
            newAllSceneObjects.push_back(allSceneObjects[i-1]);
        }
    }
    for (int i = allSceneObjects.size(); i > 0; i--)
    {
        allSceneObjects.pop_back();
    }
    for (int i = newAllSceneObjects.size(); i > 0; i--)
    {
        allSceneObjects.push_back(newAllSceneObjects[i-1]);
    }
    //std::cout << allSceneObjects.size() << std::endl;
  
}
bool checkWin(std::vector<GameObject*> &allSceneObjects)
{
    bool win = true;
    for (int i = 0; i < allSceneObjects.size(); i++)
    {
        if (dynamic_cast<Block*>(allSceneObjects[i]))
        {
            if (allSceneObjects[i]->getIsDestroyed() == false)
            {
                win = false;
            }
        }
    }
    return win;
}
void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
    {
        double xpos, ypos;
        glfwGetCursorPos(window, &xpos, &ypos);
       void* userPointer = glfwGetWindowUserPointer(window);
       if (std::vector<InterfaceObject*>* allInterfaceObjectsPtr = static_cast<std::vector<InterfaceObject*>*>(userPointer))
       {
           for (int i = 0; i < allInterfaceObjectsPtr->size(); i++)
           { 
                   if (xpos > (*allInterfaceObjectsPtr)[i]->getX() && xpos < (*allInterfaceObjectsPtr)[i]->getX() + (*allInterfaceObjectsPtr)[i]->getWidth())
                   {
                       if(ypos > (*allInterfaceObjectsPtr)[i]->getY() && ypos < (*allInterfaceObjectsPtr)[i]->getY() + (*allInterfaceObjectsPtr)[i]->getHeight())
                       {
                           (*allInterfaceObjectsPtr)[i]->onClick();
                       }
                   }
           }
       }

    }
}
void hoverInterfaceObjects(int x, int y, std::vector<InterfaceObject*>& allInterfaceObjects)
{
    for (int i = 0; i < allInterfaceObjects.size(); i++)
    {
      
        if (x > allInterfaceObjects[i]->getX() && x < allInterfaceObjects[i]->getX() + allInterfaceObjects[i]->getWidth() && y > allInterfaceObjects[i]->getY() && y < allInterfaceObjects[i]->getY() + allInterfaceObjects[i]->getHeight())
        {
            allInterfaceObjects[i]->setIsHovered(true);
        }
        else
        {
            allInterfaceObjects[i]->setIsHovered(false);
        }
    }
}
int main(void)
{
    int points = 0;
    Block::SetPlayerPoints(&points);

    std::vector<GameObject*> allSceneObjects;
    std::vector<InterfaceObject*> allInterfaceObjects;
    std::vector<Rocket*> rockets;

    CollisionManager collisionManager(allSceneObjects);

    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;
    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(windowWidth, windowHeight, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }
    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    if (glewInit() != GLEW_OK)
        std::cout << "glew error";
    else
        std::cout << "glew initialized properly\n";

    std::cout << glGetString(GL_VERSION);

	
        float positions[] = {
            -1.0f, -1.0f, 0.0f, 0.0f,
            1.0f, -1.0f, 1.0f, 0.0f,
            1.0f, 1.0f, 1.0f, 1.0f,
            -1.0f, 1.0f, 0.0f, 1.0f
        };
        unsigned int indicies[] = {
            0,1,2,
            2,3,0
        };

        GLCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));
        GLCall(glEnable(GL_BLEND));

        VertexArray va;
        VertexBuffer vb(positions, 4 * 4  * sizeof(float));

        VertexBufferLayout layout;

        layout.Push<float>(2);
        layout.Push<float>(2);

        va.AddBuffer(vb, layout);
        IndexBuffer ib(indicies, 6);
        Shader shader("res/shaders/Basic.shader");
        Renderer renderer;

		shader.Bind();
		shader.SetUniform1i("u_Texture", 1);


        glfwSetWindowUserPointer(window, &allInterfaceObjects);

       // level1(allSceneObjects);

        Texture* startButtonTexture = new Texture("res/textures/startButton.png");
        Texture* startButtonHoveredTexture = new Texture("res/textures/startButtonHovered.png");

        LevelGenerator levelGenerator(allSceneObjects, allInterfaceObjects);

        StartButton *startButton= new StartButton(windowWidth / 2 - 75, 100, 150, 80, startButtonTexture, allInterfaceObjects, startButtonHoveredTexture, levelGenerator);
        allInterfaceObjects.push_back(startButton);

       

       // allInterfaceObjects[0]->setIsVisible(true);


       //Rocket* rocket = dynamic_cast<Rocket*>(allSceneObjects[0]);
		
        float lastFramesCursorPosition[6];

        glfwSetMouseButtonCallback(window, mouse_button_callback);
        
        //Texture* texture2 = new Texture("res/textures/winScreen.png");


        int loopCounter = 0;
        double xpos, ypos;

        //testing only DELETE LATER
        double lastTime = glfwGetTime();
        int frameCount = 0;

        /* Loop until the user closes the window */
        while (!glfwWindowShouldClose(window))
        {
            glfwGetCursorPos(window, &xpos, &ypos);

            if (checkWin(allSceneObjects) == true && startButton->getPointsPtr() != nullptr)
            {
               
               levelGenerator.increaseLevel();
               levelGenerator.generate();
            }

            for (int i = 0; i < allSceneObjects.size(); i++)
            {
                if (dynamic_cast<Rocket*>(allSceneObjects[i]))
                {
                    Rocket* rocket = dynamic_cast<Rocket*>(allSceneObjects[i]);
                    if (rocket->getOwner() == player)
                    {
                        rocket->setX(xpos - rocket->getWidth() / 2);
                        rocket->setSpeed(lastFramesCursorPosition[5] - lastFramesCursorPosition[0]);
                    }
                }
            }

            hoverInterfaceObjects(xpos, ypos, allInterfaceObjects);
            renderer.Clear();

           rendererScene(allSceneObjects, renderer, shader, va, vb, layout, ib, window);
            rendererInterfaceObjects(allInterfaceObjects, renderer, shader, va, vb, layout, ib, window);

            collisionManager.checkCollisions();


            lastFramesCursorPosition[5] = lastFramesCursorPosition[4];
            lastFramesCursorPosition[4] = lastFramesCursorPosition[3];
            lastFramesCursorPosition[3] = lastFramesCursorPosition[2];
            lastFramesCursorPosition[2] = lastFramesCursorPosition[1];
            lastFramesCursorPosition[1] = lastFramesCursorPosition[0];
            lastFramesCursorPosition[0] = xpos;

          

          

            loopCounter++;
            if (loopCounter % 300 == 0)
            {
                clearDestroyed(allSceneObjects);
            }
            if (loopCounter == INT_MAX)
            {
                loopCounter = 0;
            }

            //TESTING DELETE LATER
            double currentTime = glfwGetTime();
            frameCount++;
            if (currentTime - lastTime >= 1.0)
            {
                std::cout << "FPS: " << frameCount << std::endl;

                frameCount = 0;
                lastTime = currentTime;
                std::cout << allSceneObjects.size() << std::endl;
            }
            /* Poll for and process events */
            GLCall(glfwPollEvents());
            /* Swap front and back buffers */
            GLCall(glfwSwapBuffers(window));
        }
    glfwTerminate();
    return 0;
}
