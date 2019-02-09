CC=g++
LDFLAGS = -lncurses

all: main.cpp c_visual.cpp menu.cpp
	$(CC) -o main main.cpp c_visual.cpp menu.cpp $(LDFLAGS)

visual: main.cpp c_visual.cpp
	$(CC) -o visual main.cpp c_visual.cpp $(LDFLAGS)

menu: runMenu.cpp menu.cpp
	$(CC) -o menuwin runMenu.cpp menu.cpp $(LDFLAGS)

bob: runMenu.cpp menu.cpp c_visual.cpp
	$(CC) -o bob runMenu.cpp menu.cpp c_visual.cpp $(LDFLAGS)

clean:
	rm -f visual menuwin bob
