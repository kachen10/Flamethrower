CC=g++
LDFLAGS = -lncurses

all: visual menu

visual:
	$(CC) -o visual main.cpp c_visual.cpp creature.cpp $(LDFLAGS)

menu:
	$(CC) -o menuwin runMenu.cpp menu.cpp $(LDFLAGS)

clean:
	rm -f visual menuwin
