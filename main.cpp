# include <ncurses.h>

//HEADERS
#include "c_visual.h"
#include "menu.h"

int main( int argc, char* arg[] ) {

	int max_y, max_x;
	
	initscr();
	//"stdscr" to refer to the current screen

	refresh();
	getmaxyx(stdscr, max_y, max_x);
	//FUNCTIONS THAT WILL GO HERE
	
	c_visual(max_x, max_y);
	menu(max_x, max_y);
	
	refresh();

	endwin(); //bye
	return 0;
}
