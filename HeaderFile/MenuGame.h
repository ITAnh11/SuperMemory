#ifndef MENU_GAME_H_
#define MENU_GAME_H_

#include "Common.h"
#include "global.h"


namespace MENU
{
	enum StatusGameOver
	{
		O_QUIT,
		O_PLAY_AGAIN,
		O_RETURN_MENU,
		O_NONE,
	};

	enum StatusGameWin
	{
		W_QUIT,
		W_NEXT_LEVEL,
		W_RETURN_MENU,
		W_NONE,
	};

	enum StatusGameStart
	{
		S_QUIT,
		S_NEWGAME,
		S_CONTINUE,
		S_SELLECT_LEVEL,
		NONE,
	};

	bool createText();

	StatusGameOver GameOVER();

	StatusGameWin GameWIN();

	StatusGameStart GameSTART();

	void SellectLevel();

	void loadSaveGame();

	void createSaveGame();
}

#endif // !MENU_GAME_H_
