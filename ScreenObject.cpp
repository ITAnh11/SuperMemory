#include "ScreenObject.h"

ScreenObject::ScreenObject()
{
	m_Rect = { 0,0,0,0 };
	m_isMove = true;
}

ScreenObject::~ScreenObject()
{
}

void ScreenObject::handleMove()
{
	m_Rect.x -= SCREEN_SPEED;
	if (abs(m_Rect.x) == m_Width - SCREEN_WIDTH) m_isMove = false;
}

void ScreenObject::reset()
{
	m_Rect.x = 0;
	m_isMove = true;
}