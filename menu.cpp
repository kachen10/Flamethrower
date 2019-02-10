#include <ncurses.h>
#include <string>
#include "menu.h"
#include "creature.h"
using namespace std;

int N = 3;
string choices[3] = { "feed", "play", "study" };

int menu( int max_x, int max_y ) {
  WINDOW * menu;

  Creature* bob = new Creature();

  // Calculate placement of new window
  int y, x, height, width;
  //getmaxyx( stdscr, y, x ); <-- max_x and max_y replace these values
  height = 6, width = 5;

  printw( "Press F1 to kill Bob." );
  refresh();

  // Create window for input
	menu = newwin(max_y/3, max_x, max_y-8, 0);
  box( menu, 0, 0 );
  refresh();
  wrefresh( menu );
  keypad( menu, true );
  //print_selections( menu, 0 );

  //printw( menu, 0+1, 1, choices[0].c_str() );
  //

  int user_input;
  int highlight = 0;
  while ( 1 ) {
    print_selections( menu, highlight );
    user_input = wgetch(menu);
      //mvprintw(0,0,"Use arrow keys to go up and down, enter to make a choice");
      //wmove( menu, 4, 0 );
      mvwprintw ( menu, 4, 1, "");

      switch( user_input ) {

          case KEY_UP:
            if ( highlight == 0 ) { highlight = N-1; break; }
            else { highlight--; break; }
          case KEY_DOWN:
            if ( highlight == N-1 ) { highlight = 0; break; }
            else { highlight++; break; }
          case KEY_F(1):
            if ( user_input == KEY_F(1) ) { break; }
          case 10:
            if ( highlight == 0 ) {  wclrtoeol( menu ); bob->feed(menu); break; }
            if ( highlight == 1 ) { wclrtoeol( menu ); bob->play(menu);  break; }
            if ( highlight == 2 ) { wclrtoeol( menu ); bob->study(menu);  break; }
          default:
            break;
    } //print_selections( menu, highlight );
  }
  endwin();

  delete bob;
  return 0;
}
/*
WINDOW * new_window( int height, int width, int starty, int startx ) {

  WINDOW * menuwin = newwin( height, width, starty, startx );
  box( menuwin, 0, 0 );

  wrefresh( menuwin );
  keypad( menuwin, true );
  print_selections( menuwin, 0 );

  return menuwin;

}
*/
void close_window( WINDOW * menu_win ) {
  wrefresh( menu_win );
  delwin( menu_win );

}


void print_selections(WINDOW * menu, int highlight ) {
  start_color();
  init_pair( 1 , 0, COLOR_BLUE );

    for ( int i = 0; i < N; i++ ) {
      if ( i == highlight ) {
        //attron( COLOR_PAIR(1) );
        wattron( menu, COLOR_PAIR(1) );
        //wattron( menu, A_REVERSE );

      }
      mvwprintw( menu, i+1, 1, choices[i].c_str() );
      wattroff( menu, COLOR_PAIR(1) );
      wrefresh(menu);
  }
}
