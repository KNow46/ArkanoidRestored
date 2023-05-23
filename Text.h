#pragma once
#include <vector>
#include "InterfaceObject.h"
#include "Texture.h"
#include "Image.h"
#include <math.h> 

class Text : public InterfaceObject
{
public:
	enum textObjectType { points, none };

	Text(int x, int y, int width, int height, const Texture* texture, std::string strText, int fontSize, textObjectType type);
	Text(int x, int y, int width, int height, const Texture* texture, std::string strText, int fontSize, std::string fontPath, textObjectType type);

	std::vector<Image*> getText();

	Image* getTextAtIndex(int index);

	void changeText(std::string newText);

	textObjectType getType();

private:
	void stringTextToTexture();

	std::vector<Image*> text;
	std::string fontPath;
	int fontSize;
	std::string strText;
	textObjectType type;
};
