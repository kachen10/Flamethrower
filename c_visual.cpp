#include <ncurses.h>

int c_visual () {

	/*****VARIABLES*******/
	//box dimensions
	int height, width, start_y, start_x;
	height = 10;
	width = 20;
	start_y = start_x = 0;
	
	//box border
	int left, right, top, bottom, tlc, trc, blc, brc; 
	left = right = (int)'|';
	top = bottom = (int)'-';
	trc = tlc = blc = brc = (int)'&';
	
	/*****THE ACTION SPACE*******/
	WINDOW * c_screen = newwin(height, width, start_y, start_x);
	refresh();
	
	//box(c_screen, (int)side_border, (int)top_border);
	
	//TO BE IN CONTROL OF HOW YOUR BOX BORDER LOOKS:
	//wborder(win, left, right, top, bottom, tlc, trc, blc, brc);
	wborder(c_screen, left, right, top, bottom, tlc, trc, blc, brc);
	mvwprintw(c_screen, 1, 1, "this is my box");
	wrefresh(c_screen);
	
	getch();
	getch();
	
	return 0;

}

