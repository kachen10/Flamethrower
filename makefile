CC=g++
LDFLAGS = -lncurses

all: main.cpp c_visual.cpp creature.cpp menu.cpp 
	$(CC) -o main main.cpp c_visual.cpp creature.cpp menu.cpp $(LDFLAGS)
	

visual: main.cpp c_visual.cpp creature.cpp
	$(CC) -o visual main.cpp c_visual.cpp creature.cpp $(LDFLAGS)

menu: menuwin runMenu.cpp menu.cpp
	$(CC) -o menuwin runMenu.cpp menu.cpp $(LDFLAGS)

bob: runMenu.cpp menu.cpp c_visual.cpp creature.cpp
	$(CC) -o bob runMenu.cpp menu.cpp c_visual.cpp creature.cpp $(LDFLAGS)

clean:
	rm -f visual menuwin bob
