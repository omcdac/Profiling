CC = gcc

CFLAGS = -O3 -march=native -fopenmp -g
LDFLAGS = -lm

OBJ = main.o nbody.o io.o

nbody: $(OBJ)
	$(CC) $(CFLAGS) -o nbody $(OBJ) $(LDFLAGS)

main.o: main.c nbody.h io.h
	$(CC) $(CFLAGS) -c main.c

nbody.o: nbody.c nbody.h
	$(CC) $(CFLAGS) -c nbody.c

io.o: io.c io.h nbody.h
	$(CC) $(CFLAGS) -c io.c

clean:
	rm -f *.o nbody frame_*.dat
