#include <ncurses.h>
#include <unistd.h>

int height = 10;
int width = 20;
int size;
int start_y = 1; int start_x = 6;
//int max_x, max_y;


//**************FUNCTION TO DRAW BOB*******************//
int c_visual(int max_x, int max_y) {

	noecho();
	WINDOW * c_screen = newwin(height, width, start_y, (max_x/3)+2);


	refresh();

	wrefresh(c_screen);

	//width = columns, height = rows
	int pos; //current position in the image
	int eye1 = 5*width+8;
	int eye2 = 5*width+10;
	int mouth = 5*width + 9;

	size = height * width;
	char bob[size];


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

	bob[eye1] = 'O';
	bob[eye2] = 'O';
	bob[mouth] = 'w';


 	//PRINT BOB
	start_color();
	init_pair(1, COLOR_BLUE, COLOR_BLACK);
	for(int x=0; x < width; x++) {

		for(int y=0; y < height; y++) {
			pos = y*width + x;
			if (pos > 65 && pos < 73 ||
					pos > 84 && pos < 94 ||
					pos > 104 && pos < 114 ||
				  pos > 125 && pos < 133){
			  wattron(c_screen, COLOR_PAIR(1));
			}
			mvwaddch(c_screen, y, x, bob[pos]);
			wattroff(c_screen, COLOR_PAIR(1));
		}
	}

	box(c_screen, 0, 0);
	wrefresh(c_screen);

	//getch();

 		return 0;
}
