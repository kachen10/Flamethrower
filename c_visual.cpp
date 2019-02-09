#include <ncurses.h>
#include <unistd.h>

int height = 10;
int width = 20;
int size;
int start_y = 0; int start_x = 0;
int max_x, max_y;


//**************FUNCTION TO DRAW BOB*******************//
int c_visual() {

	noecho();
	WINDOW * c_screen = newwin(height, width, start_y, start_x);
	refresh();
	
	wrefresh(c_screen);

	//width = columns, height = rows
	int pos; //current position in the image
	int eye1 = 5*width+8;
	int eye2 = 5*width+10;
	int mouth = 5*width + 9;
	
	size = height * width;
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
	
	wrefresh(c_screen);
	
	getch();
 		
 		return 0;
}


