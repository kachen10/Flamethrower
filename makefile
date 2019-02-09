CC=g++
LDFLAGS = -lncurses

all: visual menu

visual:
	$(CC) -o flamethrower main.cpp c_visual.cpp $(LDFLAGS)

menu:
	$(CC) -o flamethrower main.cpp menu.cpp choices.cpp $(LDFLAGS)
