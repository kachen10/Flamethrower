CC=g++
LDFLAGS = -lncurses

all: visual menu bob

visual: main.cpp c_visual.cpp creature.cpp
	$(CC) -o visual main.cpp c_visual.cpp creature.cpp $(LDFLAGS)

menu: menuwin runMenu.cpp menu.cpp
	$(CC) -o menuwin runMenu.cpp menu.cpp $(LDFLAGS)

bob: runMenu.cpp menu.cpp c_visual.cpp creature.cpp
	$(CC) -o bob runMenu.cpp menu.cpp c_visual.cpp creature.cpp $(LDFLAGS)

clean:
	rm -f visual menuwin bob
