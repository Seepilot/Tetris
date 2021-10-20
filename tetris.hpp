#ifndef TETRIS_H
#define TETRIS_H
#pragma once


//class Figure;
#include "figure.hpp"
#include "screen.hpp"
	
class Tetris
{
	private:
		Figure *figure;
		Screen *screen;

	public:

		Tetris();
		~Tetris();
		void start_game(void);

};
#endif