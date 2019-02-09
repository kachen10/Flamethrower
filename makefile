CC=g++
LDFLAGS = -lncurses

all: main.cpp c_visual.cpp creature.h menu.cpp
	$(CC) -o main main.cpp c_visual.cpp creature.h menu.cpp $(LDFLAGS)

visual: main.cpp c_visual.cpp creature.h
	$(CC) -o visual main.cpp c_visual.cpp creature.h $(LDFLAGS)

menu: runMenu.cpp menu.cpp
	$(CC) -o menuwin runMenu.cpp menu.cpp $(LDFLAGS)

bob: runMenu.cpp menu.cpp c_visual.cpp
	$(CC) -o bob runMenu.cpp menu.cpp c_visual.cpp $(LDFLAGS)


clean:
	rm -f visual menuwin bob
