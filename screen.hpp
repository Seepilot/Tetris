#ifndef SCREEN_H
#define SCREEN_H
#pragma once

#include <ncurses.h>
#include "figure.hpp"

class Screen  
{
	private:
		WINDOW *fig_win;
		WINDOW *score_win;
		WINDOW *next_fig_win;
		Figure *fig;

	public:

		Screen();
		~Screen();
		void init_screen(void);
		void deinit_screen(void);
		void print_figure(void);
		void set_figure(Figure *f);
		Figure* get_figure(void);
		void remove_figure(void);


};
#endif