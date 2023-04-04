#include "../HeaderFile/CharacterObject.h"

CharacterObject::CharacterObject()
{
	m_Rect = { 0,0,0,0 };
	m_frame = 0;
	m_LR = RIGHT;
	m_IsMove = true;
	m_IsChecked = false;
	m_scale = 1;
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

void CharacterObject::setScale(const int scale)
{
	m_scale = scale;
}

void CharacterObject::renderClips(const int x, const int y)
{
	SDL_Rect* currentClip = &m_SpriteClips[m_frame];
	++m_frame;
	if (m_frame >= ANIMATION_FRAMES) m_frame = 0;
	if (m_LR == LEFT) render(x, y, currentClip, 0, 0, SDL_FLIP_HORIZONTAL);
	else render(x, y, currentClip);
}

void CharacterObject::handleMove()
{
	m_Rect.x += (CHARACTER_SPEED * m_LR);
	if (m_LR == LEFT)
	{
		if (m_Rect.x + m_Width <= 0)
		{
			m_IsMove = false;
		}
	}
	else
	{
		if (m_Rect.x > SCREEN_WIDTH)
		{
			m_IsMove = false;
		}
	}
}

void CharacterObject::randomLeftRight()
{
	int r = rand() % 2;
	if (r == 0)
	{
		m_LR = LEFT;
		m_Rect.x = SCREEN_WIDTH;
	}
	else
	{
		m_LR = RIGHT;
		m_Rect.x = -(m_Width / ANIMATION_FRAMES);
	}
	r = rand() % (SCREEN_HEIGHT - m_Height) - 100;
	r = SCREEN_HEIGHT / 2;
	m_Rect.y = r;
}

void CharacterObject::handleInputAction(SDL_Event event)
{

}

void CharacterObject::reset()
{
	m_IsMove = true;
	m_IsChecked = false;
	if (m_LR == RIGHT)
	{
		m_Rect.x = -(m_Width / ANIMATION_FRAMES);
	}
	else
	{
		m_Rect.x = SCREEN_WIDTH;
	}
}