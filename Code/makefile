# This is a makefile. I'm sure we'll need / want this at some point

.PHONY: clean

CC = gcc
LFLAGS = -Wall -O3
CFLAGS = -Wall -O3 -c

stock_predictor: main.o ReadFile.o beta.o alpha.o Output.o
	$(CC) $(LFLAGS) -o $@ $^ -fopenmp

main.o: main.c ReadFile.h beta.h alpha.h Output.h
	$(CC) $(CFLAGS) $< -fopenmp

ReadFile.o: ReadFile.c ReadFile.h
	$(CC) $(CFLAGS) $<

beta.o: beta.c beta.h
	$(CC) $(CFLAGS) $<

alpha.o: alpha.c alpha.h beta.h
	$(CC) $(CFLAGS) $<

Output.o: Output.c Output.h
	$(CC) $(CFLAGS) $<

clean:
	rm -rf *.o stock_predictor
