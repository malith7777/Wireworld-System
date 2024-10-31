C = gcc
CFLAGS =-g -Wall -pedantic -ansi
OBJ = main.o map.o color.o newSleep.o

EXEC = Wireworld




$(EXEC) : $(OBJ)
	                         $(CC) $(OBJ) -o $(EXEC)

main.o : main.c map.h
				 $(CC) -c main.c $(CFLAGS)

map.o : map.c map.h color.h
				 $(CC) -c map.c $(CFLAGS)

color.o : color.c color.h
	                         $(CC) -c color.c $(CFLAGS)

newSleep.o : newSleep.c newSleep.h
				$(CC) -c newSleep.c $(CFLAGS)

clean:
	                        rm -f $(EXEC) $(OBJ)
