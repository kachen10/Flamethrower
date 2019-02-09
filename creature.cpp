#include <time.h>
#include <cmath>

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
  int growth[3] = {1, 2, 3};
  int growthStatus;
  time_t dayStart;
  time_t last;      //time of last command
  int lives;
  bool alive;

  void checkValues();
  void newLife();
};

Creature::Creature(){
  boredom = 100;
  hunger = 100;
  growthStatus = growth[0];
  time(&dayStart);
  time(&last);
  lives = 0;
  alive = true;
}

void Creature::feed(){
  hunger += 20;
  checkValues();
}

void Creature::play(){
  boredom += 20;
  hunger -= 5;
  checkValues();
}

void Creature::study(){
  knowledge += 20;
  boredom -= 10;
  hunger -= 5;
  checkValues();
}

void Creature::checkValues(){
  time_t currentTime;
  time(&currentTime);
  double sinceStartCycle = difftime(dayStart, currentTime);
  double sinceLastCommand = difftime(last, currentTime);
  int decrementBy = sinceLastCommand;

  if (sinceStartCycle >= 240) {
    alive = false;
    lives++;
    newLife();
    return;
  }

  if (sinceStartCycle > 40 && sinceStartCycle < 80) {
    growthStatus = growth[1];
  }

  if (sinceStartCycle > 80 && sinceStartCycle < 120) {
    growthStatus = growth[2];
  }

  if (fmod(sinceLastCommand, 2) == 1) {
    decrementBy++;
  }

  hunger -= (decrementBy/2);
  boredom -= (decrementBy/2);

  if (hunger < 0 || hunger > 100 || boredom < 0) {
    alive = false;
    return;
  }

  last = currentTime;
}

void Creature::newLife(){
  boredom = 100;
  hunger = 100;
  growthStatus = growth[0];
}
