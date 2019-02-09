#include <ncurses.h>
#include <string>
#include "menu.h"
using namespace std;


int menu() {
  WINDOW * menu;

  // Calculate placement of new window
  int y, x, height, width;
  getmaxyx( stdscr, y, x );
  height = 6, width = 5;

  printw( "Press F1 to kill Bob." );
  refresh();

  // Create window for input
  menu = new_window( height, x-12 , y-8, width);
  //
  int user_input;
  while ( (user_input = getch()) != KEY_F(1) ) {
    char choices[3] = { "feed", "play", "study" };

  }
  endwin();
  return 0;
}

WINDOW * new_window( int height, int width, int starty, int startx ) {

  WINDOW * menuwin = newwin( height, width, starty, startx );
  box( menuwin, 0, 0 );

  wrefresh( menuwin );
  keypad( menuwin, true );

  return menuwin;

}

void close_window( WINDOW * menu_win ) {
  wrefresh( menu_win );
  delwin( menu_win );

}
