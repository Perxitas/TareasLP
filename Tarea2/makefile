all: TreasureFinder

TreasureFinder: Bomba.o Tablero.o TreasureFinder.o 
	gcc -o TreasureFinder Bomba.o Tablero.o TreasureFinder.o 

Bomba.o: Bomba.c Bomba.h Tierra.h Tablero.h Tablero.c
	gcc -c Bomba.c Bomba.h Tierra.h Tablero.h

Tablero.o: Tablero.c Tablero.h Bomba.h 
	gcc -c Tablero.c Tablero.h Bomba.h 

TreasureFinder.o: TreasureFinder.c Tablero.h Bomba.h Tierra.h
	gcc -c TreasureFinder.c Tablero.h Bomba.h Tierra.h

wall: Bomba.o Tablero.o TreasureFinder.o
	gcc -Wall -Werror -o out Bomba.o Tablero.o TreasureFinder.o

mmy: TreasureFinder
	valgrind --leak-check=full  --show-leak-kinds=all ./TreasureFinder

clean:
	rm -f Bomba.o Tablero.o TreasureFinder.o TreasureFinder