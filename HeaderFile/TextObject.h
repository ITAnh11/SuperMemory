#ifndef TEXT_OBJECT_H_
#define TEXT_OBJECT_H_

#include "Common.h"
#include "BaseObject.h"

class TextObject :public BaseObject
{
public:
	enum Status_Button
	{
		B_INSIDES,
		B_PRESS,
		B_NONE,
	};

	//Creates image from font string
	bool loadFromRenderedText(std::string textureText, SDL_Color textColor);

	//mouse event
	Status_Button handleInputAction(SDL_Event event);

	SDL_Rect getPos() const { return m_Pos; }

	void setPos(const int x, const int y);
private:
	SDL_Rect m_Pos;
};

#endif //!TEXT_OBJECT_H_