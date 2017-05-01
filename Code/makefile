# This is a makefile. I'm sure we'll need / want this at some point

stock_predictor: main.o ReadFile.o beta.o alpha.o Output.o
	gcc -Wall -o stock_predictor main.o ReadFile.o beta.o alpha.o Output.o

main.o: main.c ReadFile.h beta.h alpha.h Output.h
	gcc -Wall -c main.c

ReadFile.o: ReadFile.c ReadFile.h
	gcc -Wall -c ReadFile.c

beta.o: beta.c beta.h
	gcc -Wall -c beta.c

alpha.o: alpha.c alpha.h beta.h
	gcc -Wall -c alpha.c

Output.o: Output.c Output.h
	gcc -Wall -c Output.c

clean:
	rm -rf *.o stock_predictor
