CC=g++
LDFLAGS = -lncurses

all: visual menu

visual:
	$(CC) -o visual main.cpp c_visual.cpp creature.cpp $(LDFLAGS)

menu:
	$(CC) -o menuwin main.cpp menu.cpp $(LDFLAGS) 
