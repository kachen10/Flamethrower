#include <ncurses.h>

//**************FUNCTION TO DRAW BOB*******************//
void bob_stage1(int height, int width, int size, WINDOW * win) {

	//width = columns, height = rows
	int pos; //current position in the image
	
	char bob[size] = {};
	for (int i=0; i < size; i++) {
		bob[i] = ' ';
		//addch(bob[i]);
	}
	
	for(int x=0; x < width; x++) {
		
		for(int y=0; y < height; y++) {
			pos = y*width + x;
			mvaddch(y, x, bob[pos]);
		}
	} 
	
	wrefresh(win);
}


///*******FUNCTION TO DRAW EVERYTHING + THE BOX*****///
int c_visual () {

	/*****VARIABLES*******/
	//box dimensions
	int height, width, start_y, start_x, size;
	height = 10;
	width = 20;
	size = height * width;
	start_y = start_x = 0;
	
	//box border
	int left, right, top, bottom, tlc, trc, blc, brc; 
	left = right = (int)'|';
	top = bottom = (int)'-';
	trc = tlc = blc = brc = (int)'+';
	
	/*****THE ACTION SPACE*******/
	noecho();
	WINDOW * c_screen = newwin(height, width, start_y, start_x);
	refresh();
	
	//draw a box
	wborder(c_screen, left, right, top, bottom, tlc, trc, blc, brc);
	//mvwprintw(c_screen, 1, 1, "this is my box");
	wrefresh(c_screen);
	
	//draw bob (stage 1)
	bob_stage1(height, width, size, c_screen);
	
	getch();
	getch();
	
	return 0;

}

