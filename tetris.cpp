#include "tetris.hpp"
	
Tetris::Tetris()
{
	figure = new Figure();
	screen = new Screen();
}
	
Tetris::~Tetris()
{
	delete figure;
	delete screen;
}

void Tetris::start_game(void)
{
	int ch;
	screen->init_screen();
	
	
	screen->print_figure();

	/* Loop through to get user requests */
	while((ch = getch()) != KEY_F(1))
	{
		switch(ch)
		{
			case KEY_DOWN:

				break;
			case KEY_UP:

				break;
			case KEY_RIGHT:


				break;
			case KEY_LEFT:


				break;
			default:

				break;
		}
	}
}
