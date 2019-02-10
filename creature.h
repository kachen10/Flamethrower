#include <time.h>
#include <cmath>
#include <ncurses.h>

class Creature{
public:
  Creature();
  ~Creature();

  void feed(WINDOW* menu);
  void play(WINDOW* menu);
  void study(WINDOW* menu);
  void murder(WINDOW* menu);


private:
  int knowledge;
  int boredom;
  int hunger;
  int growth[3] = {1, 2, 3};
  int growthStatus;
  int numActions;
  int lives;
  bool alive;


  void checkValues(WINDOW* menu);
  void newLife();
};

Creature::Creature(){
  boredom = 100;
  hunger = 100;
  growthStatus = growth[0];
  numActions = 0;
  lives = 0;
  alive = true;
}

void Creature::feed(WINDOW* menu){
  hunger += 20;
  numActions++;
  mvwprintw( menu, 4, 1, "Bob was fed!" );
  wrefresh(menu);
  checkValues(menu);
}

void Creature::play(WINDOW* menu){
  boredom += 20;
  hunger -= 5;
  numActions++;
  mvwprintw( menu, 4, 1, "Bob had fun!" );
  wrefresh(menu);
  checkValues(menu);
}

void Creature::study(WINDOW* menu){
  knowledge += 20;
  boredom -= 10;
  hunger -= 5;
  numActions++;
  mvwprintw( menu, 4, 1, "Bob studied hard..." );
  wrefresh(menu);
  checkValues(menu);
}

void Creature::murder(WINDOW* menu){
  alive = false;
  mvwprintw( menu, 4, 1, "Bob has been murdered..." );
  flash();
  wrefresh(menu);
  return;
}

void Creature::checkValues(WINDOW* menu){
  if (numActions > 16) {
    alive = false;
    lives++;
    mvwprintw( menu, 4, 1, "Bob has lived a full life, and has died of old age..." );
	flash();
    wrefresh(menu);
    newLife();
    return;
  }

  if (numActions == 3) {
    growthStatus = growth[1];
    mvwprintw( menu, 4, 1, "Bob has grown up a little!" );
    wrefresh(menu);
  }

  if (numActions == 8) {
    growthStatus = growth[2];
    mvwprintw( menu, 4, 1, "Bob has grown up a little!" );
    wrefresh(menu);
  }

  hunger -= 5;
  boredom -= 5;

  if (hunger < 0) {
    alive = false;
    mvwprintw( menu, 4, 1, "Bob has starved to death..." );
    flash();
    wrefresh(menu);
    return;
  }

  if (hunger > 100){
    alive = false;
    mvwprintw( menu, 4, 1, "Bob ate too much and exploded..." );
    flash();
    wrefresh(menu);
    return;
  }

  if (boredom < 0) {
    alive = false;
    mvwprintw( menu, 4, 1, "Bob was so bored he died..." );
    flash();
    wrefresh(menu);
    return;
  }
}

void Creature::newLife(){
  boredom = 100;
  hunger = 100;
  growthStatus = growth[0];
}
