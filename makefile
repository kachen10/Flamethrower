CC=g++
LDFLAGS = -lncurses

all: visual menu bob

visual:
	$(CC) -o visual main.cpp c_visual.cpp creature.cpp $(LDFLAGS)

menu:
	$(CC) -o menuwin runMenu.cpp menu.cpp $(LDFLAGS)

bob:
	$(CC) -o bob runMenu.cpp menu.cpp c_visual.cpp creature.cpp $(LDFLAGS)
<<<<<<< HEAD

=======
  
>>>>>>> 8f795146b4567099a0c375a6d22944440ff4c3ca
clean:
	rm -f visual menuwin bob
