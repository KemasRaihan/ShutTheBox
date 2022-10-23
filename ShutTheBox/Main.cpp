#include <iostream>
#include <crtdbg.h>
#include "Game.h"
using namespace std;

int main()
{
#ifdef _DEBUG
	//  _CrtSetBreakAlloc(87);
	_onexit(_CrtDumpMemoryLeaks);
#endif

	srand(time(NULL));
	Game game = Game();
	game.play();
	return 0;
}