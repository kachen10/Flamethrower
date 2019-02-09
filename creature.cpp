#include <time.h>

class Creature{
public:
  Creature();
  ~Creature();

  void feed();
  void play();
  void study();

private:
  int knowledge;
  int boredom;
  int hunger;
  int growth;
  time_t time;
  int lives;
  bool alive;
}

Creature::Creature(){
  boredom = 0;
  hunger = 100;
  growth = 0;
  time(&time);
  lives = 0;
  alive = true;
}

void Creature::feed(){
  hunger += 20;
  if (hunger > 100) {
    alive = false;
  }
}

void Creature::play(){
  boredom += 20;
}

void Creature::study(){
  knowledge += 20;
}

void Creature::checkTime(){
  if (/* condition */) {
    /* code */
  }
}
