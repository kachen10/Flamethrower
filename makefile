CC=gc
LDFLAGES = -lncurses


make:
	$(CC) $(LDFLAGES) -o flamethrower main.c
