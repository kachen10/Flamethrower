CC=g++
LDFLAGS = -lncurses


make:
	$(CC) -o flamethrower main.cpp c_visual.cpp creature.cpp $(LDFLAGS) 
