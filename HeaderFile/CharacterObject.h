#ifndef CHARACTER_OBJECT_H_
#define CHARACTER_OBJECT_H_

#include "../HeaderFile/Common.h"
#include "../HeaderFile/BaseObject.h"

class CharacterObject : public BaseObject
{
public:
	// Direction character
	enum LeftRight
	{
		LEFT = -1,
		RIGHT = 1,
	};

	CharacterObject();
	~CharacterObject();

	void setXY(const int x, const int y);
	void setClip();

	void renderClips(const int x, const int y);

	void handleMove();
	void randomLeftRight();
	void isChecked() { m_IsChecked = true; }

	void handleInputAction(SDL_Event event);

	SDL_Rect getRect() const { return m_Rect; }

	bool getIsMove() const { return m_IsMove; }
	LeftRight getLeftRight() const { return m_LR; }

	bool getIsChecked() const { return m_IsChecked; }

	void reset();

	void setNumFrame(const int val) { m_num_frame = val; }
	std::string getNumframeFromNamefile(std::string s) const;

private:
	SDL_Rect m_Rect;
	int m_frame;
	SDL_Rect m_SpriteClips[20];
	LeftRight m_LR;
	bool m_IsMove;
	bool m_IsChecked;
	int m_num_frame;
};

#endif // !CHARACTER_OBJECT_H_
