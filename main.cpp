#include "tetris.hpp"

using namespace std;

int main()
{
	Tetris *tetris = new Tetris();
	tetris->start_game();
	delete tetris;
	return 0;
}