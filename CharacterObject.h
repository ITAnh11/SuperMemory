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

private:
	SDL_Rect m_Rect;
	int m_frame;
	SDL_Rect m_SpriteClips[WALKING_ANIMATION_FRAMES];
};

#endif // !CHARACTER_OBJECT_H_
