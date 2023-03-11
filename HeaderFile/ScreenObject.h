#ifndef SCREEN_OBJECT_H_
#define SCREEN_OBJECT_H_

#include "../HeaderFile/Common.h"
#include "../HeaderFile/BaseObject.h"

class ScreenObject : public BaseObject
{
public:
	ScreenObject();
	~ScreenObject();

	void handleMove();
	bool getIsmove() const { return m_isMove; }
	SDL_Rect getRect() const { return m_Rect; }

	void reset();

private:
	SDL_Rect m_Rect;
	bool m_isMove;
};

#endif // !SCREEN_OBJECT_H_

