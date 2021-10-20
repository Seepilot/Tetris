#include "screen.hpp"

Screen::Screen()
{
	
}
	
Screen::~Screen()
{
	
}

void Screen::init_screen(void)
{
	/* Initialize curses */
	initscr();				/* Start curses mode */
	start_color();			/* Start the color functionality */
	cbreak();				/* Line buffering disabled, Pass on everything to me */
	curs_set(0);			/* Turn the cursor off. */
	noecho();
	keypad(stdscr, TRUE);	/* Enable F1-Key */

	init_pair(1, COLOR_CYAN, COLOR_BLACK);
	init_pair(2, COLOR_CYAN, COLOR_BLUE);

	fig_win = subwin(stdscr, 20, 20, 1, 3);
	bkgd(COLOR_PAIR(1));
	wbkgd(fig_win, COLOR_PAIR(2));
	
	refresh();
	wrefresh(fig_win);
}

void Screen::deinit_screen(void)
{
	remove_figure();
	delwin(fig_win);
	endwin();
}


void Screen::print_figure(void)
{
	
	mvwaddstr(fig_win, 0, 0, "XXXXXX");
	mvwaddstr(fig_win, 1, 2, "XX");

	mvwaddstr(fig_win, 3, 0, "  ");
	mvwaddstr(fig_win, 4, 0, "    ");
	mvwaddstr(fig_win, 5, 0, "  ");

	mvwaddstr(fig_win, 7, 2, "  ");
	mvwaddstr(fig_win, 8, 0, "    ");
	mvwaddstr(fig_win, 9, 2, "  ");

	mvwaddstr(fig_win, 12, 0, "      ");
	mvwaddstr(fig_win, 11, 2, "  ");

	wrefresh(fig_win);
}

void Screen::set_figure(Figure *f)
{
	fig = f;
}

Figure* Screen::get_figure(void)
{
	return fig;
}

void Screen::remove_figure(void)
{
	fig = NULL;
}