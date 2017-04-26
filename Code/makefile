# This is a makefile. I'm sure we'll need / want this at some point

stock_predictor: main.o ReadFile.o #and all other .o files involved
	gcc -Wall -o stock_predictor main.o

main.o: main.c ReadFile.h #and other header files
	gcc -Wall -c main.c

ReadFile.o: ReadFile.c ReadFile.h
	gcc -Wall -c ReadFile.c

clean:
	rm -rf *.o stock_predictor
