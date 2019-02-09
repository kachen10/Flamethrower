CC=g++
LDFLAGS = -lncurses

all: visual menu bob

visual:
	$(CC) -o visual main.cpp c_visual.cpp creature.cpp $(LDFLAGS)

menu:
	$(CC) -o menuwin runMenu.cpp menu.cpp $(LDFLAGS)

bob:
	$(CC) -o bob runMenu.cpp menu.cpp c_visual.cpp creature.cpp $(LDFLAGS)
  
clean:
	rm -f visual menuwin bob
