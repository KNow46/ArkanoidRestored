#include "Text.h"

Text::Text(int x, int y, int width, int height, std::string strText, int fontSize, textObjectType type)
	: InterfaceObject(x, y, width, height, "res/textures/empty.png"), fontPath("res/textures/ansi"), fontSize(fontSize), strText(strText), type(type)
{
	stringTextToTexture();
}

Text::Text(int x, int y, int width, int height, std::string strText, int fontSize, std::string fontPath, textObjectType type)
	: InterfaceObject(x, y, width, height, "res/textures/empty.png"), fontPath(fontPath), fontSize(fontSize), strText(strText), type(type)
{
	stringTextToTexture();
}

std::vector<Image*> Text::getText()
{
	return text;
}

Image* Text::getTextAtIndex(int index)
{
	return text[index];
}

void Text::changeText(std::string newText)
{
	int currTextSize = text.size();
	for (int i = 0; i < currTextSize; i++)
	{
		delete (text[i]);
	}
	for (int i = 0; i < currTextSize; i++)
	{
		text.pop_back();
	}
	strText = newText;
	stringTextToTexture();
}

Text::textObjectType Text::getType()
{
	return type;
}

void Text::stringTextToTexture()
{
	for (int i = 0; i < strText.length(); i++)
	{
		double positionX = x + (i * fontSize) % width;
		int line = floor(i * fontSize / width);

		double positionY = y + line * fontSize * 2;
		switch (strText[i])
		{
			case '0':
			{
				Image* letterImage = new Image(positionX, positionY, fontSize * 0.9, fontSize * 1.8, fontPath + "/0.png");
				text.push_back(letterImage);
				break;
			}
			case '1':
			{
				Image* letterImage = new Image(positionX, positionY, fontSize * 0.9, fontSize * 1.8, fontPath + "/1.png");
				text.push_back(letterImage);
				break;
			}
			case '2':
			{
				Image* letterImage = new Image(positionX, positionY, fontSize * 0.9, fontSize * 1.8, fontPath + "/2.png");
				text.push_back(letterImage);
				break;
			}
			case '3':
			{
				Image* letterImage = new Image(positionX, positionY, fontSize * 0.9, fontSize * 1.8, fontPath + "/3.png");
				text.push_back(letterImage);
				break;
			}
			case '4':
			{
				Image* letterImage = new Image(positionX, positionY, fontSize * 0.9, fontSize * 1.8, fontPath + "/4.png");
				text.push_back(letterImage);
				break;
			}
			case '5':
			{
				Image* letterImage = new Image(positionX, positionY, fontSize * 0.9, fontSize * 1.8, fontPath + "/5.png");
				text.push_back(letterImage);
				break;
			}
			case '6':
			{
				Image* letterImage = new Image(positionX, positionY, fontSize * 0.9, fontSize * 1.8, fontPath + "/6.png");
				text.push_back(letterImage);
				break;
			}
			case '7':
			{
				Image* letterImage = new Image(positionX, positionY, fontSize * 0.9, fontSize * 1.8, fontPath + "/7.png");
				text.push_back(letterImage);
				break;
			}
			case '8':
			{
				Image* letterImage = new Image(positionX, positionY, fontSize * 0.9, fontSize * 1.8, fontPath + "/8.png");
				text.push_back(letterImage);
				break;
			}
			case '9':
			{
				Image* letterImage = new Image(positionX, positionY, fontSize * 0.9, fontSize * 1.8, fontPath + "/9.png");
				text.push_back(letterImage);
				break;
			}

		}
	}
}
