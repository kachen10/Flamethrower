#include <ncurses.h>
#include <string>
#include "menu.h"
using namespace std;

int N = 3;

int menu() {
  WINDOW * menu;
  string choices[3] = { "feed", "play", "study" };

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
      int hightlight = 1;
      mvprintw(0,0,"Use arrow keys to go up and down, enter to make a choices");
      refresh();
      switch( user_input ) {
          case KEY_UP:
            if ( hightlight == 1 ) { hightlight = N; };
          case KEY_DOWN:
            if ( hightlight == N ) { hightlight = 1; }
            else { hightlight ++; };
          default:
            hightlight = 1;
    }
    for ( int i = 0; i < N; i++ ) {
      if ( i == hightlight ) {
        wattron( menu, A_REVERSE );
        mvwprintw( menu, i+1, 1, choices[i].c_str() );
        wattroff( menu, A_REVERSE );
      }
  }

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
/*
void close_window( WINDOW * menu_win ) {
  wrefresh( menu_win );
  delwin( menu_win );

}


void print_selections(WINDOW * menu, int hightlight ) {
    for ( int i = 0; i < N; i++ ) {
      if ( i == hightlight ) {
        wattron( menu, A_REVERSE );
        mvwprintw( menu, i+1, 1, choices[i].c_str() );
        wattroff( menu, A_REVERSE );
      }
  }
}
*/
