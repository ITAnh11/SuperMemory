#ifndef CHARACTER_OBJECT_H_
#define CHARACTER_OBJECT_H_

#include "Common.h"
#include "BaseObject.h"

class CharacterObject : public BaseObject
{
public:
	CharacterObject();
	~CharacterObject();

	void setXY(const int x, const int y);
	void setClip(const int frame);

	void renderClips(const int x, const int y);

	void handleMove();
	void randomLeftRight();
	void isChecked() { m_IsChecked = true; }

	SDL_Rect getRect() const { return m_Rect; }
	

	bool getIsMove() const { return m_IsMove; }
	LeftRight getLeftRight() const { return m_LR; }
	
	bool getIsChecked() const { return m_IsChecked; }

	void reset();

private:
	SDL_Rect m_Rect;
	int m_frame;
	SDL_Rect m_SpriteClips[WALKING_ANIMATION_FRAMES];
	LeftRight m_LR;
	bool m_IsMove;
	bool m_IsChecked;
};

#endif // !CHARACTER_OBJECT_H_
