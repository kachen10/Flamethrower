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
  time_t dayStart;
  int lives;
  bool alive;

  void checkTime();
};

Creature::Creature(){
  boredom = 0;
  hunger = 100;
  growth = 0;
  time(&dayStart);
  lives = 0;
  alive = true;
}

void Creature::feed(){
  hunger += 20;
  if (hunger > 100) {
    alive = false;
  }
  checkTime();
}

void Creature::play(){
  boredom += 20;
  checkTime();
}

void Creature::study(){
  knowledge += 20;
  checkTime();
}

void Creature::checkTime(){
  time_t currentTime;
  time(&currentTime);
  double seconds;
  seconds = difftime(dayStart, currentTime);
  if (seconds >= 60) {
    alive = false;
  }
}
