# include <ncurses.h>

//HEADERS
#include "c_visual.h"
#include "menu.h"

int main( int argc, char* arg[] ) {

	initscr();
	//"stdscr" to refer to the current screen

	refresh();
	//FUNCTIONS THAT WILL GO HERE
	c_visual();


	endwin(); //bye
	return 0;
}
