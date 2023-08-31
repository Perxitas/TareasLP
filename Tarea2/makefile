all: TreasureFinder

TreasureFinder: Bomba.o Tablero.o TreasureFinder.o
	gcc -o TreasureFinder Bomba.o Tablero.o TreasureFinder.o

Bomba.o: Bomba.c Bomba.h Tierra.h Tablero.h
	gcc -c Bomba.c Bomba.h Tierra.h Tablero.h

Tablero.o: Tablero.c Tablero.h Bomba.h 
	gcc -c Tablero.c Tablero.h Bomba.h 

TreasureFinder.o: TreasureFinder.c Tablero.h Bomba.h Tierra.h
	gcc -c TreasureFinder.c Tablero.h Bomba.h Tierra.h

clean:
	rm -f Bomba.o Tablero.o TreasureFinder.o TreasureFinder