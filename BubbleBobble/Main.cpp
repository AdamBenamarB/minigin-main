#if _DEBUG
#if __has_include(<vld.h>)
#include <vld.h>
#endif
#endif
#include "Game.h"

int main(int, char* []) {
	Game bubbleBobble{};
	bubbleBobble.Run();
	return 0;
}

