#include <ncurses.h>
#include <unistd.h>

//**************FUNCTION TO DRAW BOB*******************//
void bob_stage1(int height, int width, int size, WINDOW * win) {

	//width = columns, height = rows
	int pos; //current position in the image
	int eye1 = 5*width+8;
	int eye2 = 5*width+10;
	int mouth = 5*width + 9;
	
	char bob[size] = {};
	
	
	//PREPARE BOB
	for (int i=0; i <size; i++) {
		bob[i] = ' ';
	}
	
	for (int x=0; x < width; x++) {
	
		for(int y=0; y < height; y ++) {
			pos = y*width + x;
			
			if(y == 3 || y == 6) {
				if (x >= 6 && x <= 12) {
			 		bob[pos] = '=';
			 	} 
			} 	
			else if(y == 4 | y == 5) {
				if ( x == 5 | x == 13) {
					bob[pos] = '|';
				}
			} 
			
		}
	
	}
	
	int flag = 1;
	bob[eye1] = '0';
	bob[eye2] = '0';
	bob[mouth] = '.';
 		
 		
 	//PRINT BOB
	for(int x=0; x < width; x++) {
		
		for(int y=0; y < height; y++) {
			pos = y*width + x;
			mvaddch(y, x, bob[pos]);
		}
	} 
 		
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
	
	wrefresh(c_screen);
	
	//draw bob (stage 1)
	bob_stage1(height, width, size, c_screen);
	wborder(c_screen, left, right, top, bottom, tlc, trc, blc, brc);
	
	getch();
	getch();
	
	return 0;

}

