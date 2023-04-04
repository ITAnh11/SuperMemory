#ifndef TEXT_OBJECT_H_
#define TEXT_OBJECT_H_

#include "Common.h"
#include "BaseObject.h"

class TextObject :public BaseObject
{
public:
	//Creates image from font string
	bool loadFromRenderedText(std::string textureText, SDL_Color textColor);

private:
};

#endif //!TEXT_OBJECT_H_