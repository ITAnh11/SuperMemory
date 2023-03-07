#ifndef SCREEN_OBJECT_H_
#define SCREEN_OBJECT_H_

#include "Common.h"
#include "BaseObject.h"

class ScreenObject : public BaseObject
{
public:
	ScreenObject();
	~ScreenObject();

	SDL_Rect getRect() const { return m_Rect; }

private:
	SDL_Rect m_Rect;
};

#endif // !SCREEN_OBJECT_H_

