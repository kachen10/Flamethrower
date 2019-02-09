#include <ncurses.h>
#include <stdlib.h>
#include <time.h>

//i need this to change smth
int main(int argc, char** argv) {

	initscr();
	start_color();

	flames();

	endwin();
	return 0;

}

void flames (void) {

	int width, height, size, *b, i;
	const char characters[] = {' ', '.', ':', '^', '*', 'x', 's', 'S', '#', '$'};

	//get max for screen
	getmaxyx(stdscr, height, width);
	size = width*height;
	//init color pairs
	init_pair(1, 0, 0);
	init_pair(2,1,0);
	init_pair(3,3,0);
	init_pair(4,4,0);
	clear();

	//no idea what this does
	b=calloc((size+width+1), sizeof(int));
	nodelay(stdscr, TRUE);
	srand(time(NULL));

	for(;;) {
		//WHAT???
		for(i=0; i<width/9; i++)
			b[(int)(((float)rand()/(float)RAND_MAX)*width+width*(height-1))]=65;

		for (i=0; i < size; i++)
			{
			b[i]=(b[i]+b[i+1]+b[i+width]+b[i+width+1])/4;
			if (b[i] > 15)
				attrset(COLOR_PAIR(4)|A_BOLD);
			else if (b[i] > 9)
				attrset(COLOR_PAIR(3)|A_BOLD);
			else if (b[i] > 4)
				attrset(COLOR_PAIR(2)|A_BOLD);
			else
				attrset(COLOR_PAIR(1)|A_BOLD);
			if (i < size-1)
				{
				move(i/width, i%width);
				if (b[i] > 9)
					addch(characters[9]);
				else
					addch(characters[b[i]]);
				}
			}
		refresh();
		timeout(30);
		if (getch() != ERR)
			break;
		}

	free(b);
	return;
}
