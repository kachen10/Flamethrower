CC=g++
LDFLAGS = -lncurses

all: main.cpp c_visual.cpp creature.cpp menu.cpp 
	$(CC) -o main main.cpp c_visual.cpp creature.cpp menu.cpp $(LDFLAGS)
	

<<<<<<< HEAD
visual: main.cpp c_visual.cpp
	$(CC) -o visual main.cpp c_visual.cpp $(LDFLAGS)
=======
visual: main.cpp c_visual.cpp creature.cpp
	$(CC) -o visual main.cpp c_visual.cpp creature.cpp $(LDFLAGS)
>>>>>>> master

menu: menuwin runMenu.cpp menu.cpp
	$(CC) -o menuwin runMenu.cpp menu.cpp $(LDFLAGS)

<<<<<<< HEAD
bob: runMenu.cpp menu.cpp c_visual.cpp
	$(CC) -o bob runMenu.cpp menu.cpp c_visual.cpp $(LDFLAGS)
=======
bob: runMenu.cpp menu.cpp c_visual.cpp creature.cpp
	$(CC) -o bob runMenu.cpp menu.cpp c_visual.cpp creature.cpp $(LDFLAGS)
>>>>>>> master

clean:
	rm -f visual menuwin bob
