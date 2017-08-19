CC = gcc
SOURCES = src/node-function.c src/cgp-functions.c src/cgp.c
CFLAGS = -Wall -g
LFLAGS = -lpthread -lrt -lm
OPTFLAGS = -O2
OBJECTS=$(SOURCES:.cpp=.o)

main:$(OBJECTS)
	        $(CC) $(CFLAGS) $(OBJECTS) -o bin/cgp $(LFLAGS) $(OPTFLAGS)

all:main

.cpp.o:
	        $(CC) $(CFLAGS) -c $< -o $@ -w $(ISNAP) $(OPTFLAGS)

clean:
	        rm -f *.o bin/*

