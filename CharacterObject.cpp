#include "CharacterObject.h"

CharacterObject::CharacterObject()
{
	m_Rect = { 0,0,0,0 };
	m_frame = 0;
}

CharacterObject::~CharacterObject()
{
}

void CharacterObject::setXY(const int x, const int y)
{
	m_Rect.x = x;
	m_Rect.y = y;
}

void CharacterObject::setClip(const int frame)
{
	for (int i = 0; i < frame; ++i)
	{
		m_SpriteClips[i].x = i * (m_Width / frame);
		m_SpriteClips[i].y = 0;
		m_SpriteClips[i].w = m_Width / frame;
		m_SpriteClips[i].h = m_Height;
	}
}

void CharacterObject::renderClips(const int x, const int y)
{
	SDL_Rect* currentClip = &m_SpriteClips[m_frame / (WALKING_ANIMATION_FRAMES * 2)];
	++m_frame;
	if (m_frame >= WALKING_ANIMATION_FRAMES * WALKING_ANIMATION_FRAMES * 2) m_frame = 0;
	else render(x, y, currentClip);
}
