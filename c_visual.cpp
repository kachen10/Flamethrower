#include <ncurses.h>

int c_visual () {

	int height, width, start_y, start_x;
	height = 20;
	width = 20;
	start_y = start_x = 10;
	
	WINDOW * c_screen = newwin(height, width, start_y, start_x);
	refresh();
	
	box(c_screen, 0, 0);
	////mvprintw(c_screen, 1, 1, "this is my box");
	//wrefresh(c_screen);
	
	return 0;

}


