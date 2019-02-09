CC=g++
LDFLAGES = -lncurses


make:
	$(CC) $(LDFLAGES) -o flamethrower main.cpp
