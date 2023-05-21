#pragma once
#include <vector>
//#include <string>
#include "InterfaceObject.h"
#include "Texture.h"
#include "Image.h"
#include <math.h> 

class Text : public InterfaceObject
{
public:
	enum textObjectType { points, none };
	//deafult font path constructor
	Text(int x, int y, int width, int height, const Texture * texture, std::string strText, int fontSize, textObjectType type) :
		InterfaceObject(x, y, width, height, texture, texture), fontPath("res/textures/ansi"), fontSize(fontSize), strText(strText)
	,type(type){
		stringTextToTexture();
	}
	//custom font path
	Text(int x, int y, int width, int height, const Texture* texture, std::string strText, int fontSize, std::string fontPath, textObjectType type) :
		InterfaceObject(x, y, width, height, texture, texture), fontPath(fontPath), fontSize(fontSize), strText(strText), type(type) {
		stringTextToTexture();
	}

	//int returnTextWidth()
	//{
	//	return strText.length() * fontSize;
	//}
	//int returnTextHeight()
	//{
	//	return fontSize * 2;
	//}

	std::vector<Image*> getText()
	{
		return text;
	}
	Image* getTextAtIndex(int index)
	{
		return text[index];
	}
	void changeText(std::string newText)
	{
		int currTextSize = text.size();
		for (int i = 0; i < currTextSize; i++)
		{
			delete(text[i]);
		}
		for (int i = 0; i < currTextSize; i++)
		{
			text.pop_back();
		}
		strText = newText;
		stringTextToTexture();
	}
	textObjectType getType()
	{
		return type;
	}
private:
	void stringTextToTexture()
	{
		for (int i = 0; i < strText.length(); i++)
		{
			double positionX = x + (i * fontSize) % width;
			int line = floor(i * fontSize/width);
			
			double positionY = y + line * fontSize * 2;
			switch (strText[i])
			{
				case '0':
				{
					Texture* texture = new Texture(fontPath + "/0.png");
					Image* letterImage = new Image(positionX, positionY, fontSize* 0.9, fontSize * 1.8, texture);
					text.push_back(letterImage);
					break;
				}
				case '1':
				{
					Texture* texture = new Texture(fontPath + "/1.png");
					Image* letterImage = new Image(positionX, positionY, fontSize * 0.9, fontSize * 1.8, texture);
					text.push_back(letterImage);
					break;
				}
				case '2':
				{
					Texture* texture = new Texture(fontPath + "/2.png");
					Image* letterImage = new Image(positionX, positionY, fontSize * 0.9, fontSize * 1.8, texture);
					text.push_back(letterImage);
					break;
				}
				case '3':
				{
					Texture* texture = new Texture(fontPath + "/3.png");
					Image* letterImage = new Image(positionX, positionY, fontSize * 0.9, fontSize * 1.8, texture);
					text.push_back(letterImage);
					break;
				}
				case '4':
				{
					Texture* texture = new Texture(fontPath + "/4.png");
					Image* letterImage = new Image(positionX, positionY, fontSize * 0.9, fontSize * 1.8, texture);
					text.push_back(letterImage);
					break;
				}
				case '5':
				{
					Texture* texture = new Texture(fontPath + "/5.png");
					Image* letterImage = new Image(positionX, positionY, fontSize * 0.9, fontSize * 1.8, texture);
					text.push_back(letterImage);
					break;
				}
				case '6':
				{
					Texture* texture = new Texture(fontPath + "/6.png");
					Image* letterImage = new Image(positionX, positionY, fontSize * 0.9, fontSize * 1.8, texture);
					text.push_back(letterImage);
					break;
				}
				case '7':
				{
					Texture* texture = new Texture(fontPath + "/7.png");
					Image* letterImage = new Image(positionX, positionY, fontSize * 0.9, fontSize * 1.8, texture);
					text.push_back(letterImage);
					break;
				}
				case '8':
				{
					Texture* texture = new Texture(fontPath + "/8.png");
					Image* letterImage = new Image(positionX, positionY, fontSize * 0.9, fontSize * 1.8, texture);
					text.push_back(letterImage);
					break;
				}
				case '9':
				{
					Texture* texture = new Texture(fontPath + "/9.png");
					Image* letterImage = new Image(positionX, positionY, fontSize * 0.9, fontSize * 1.8, texture);
					text.push_back(letterImage);
					break;
				}

			}
		}
	}
	std::vector<Image*>text;
	std::string fontPath;
	int fontSize;
	std::string strText;
	textObjectType type;
};