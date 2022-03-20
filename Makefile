CC=g++
CFLAGS=-Wall -std=c++14
BINS=A1 A2
all: clean A1 A2

A1:
	$(CC) $(CFLAGS) -g -o prog1 A1.cpp
A2:
	$(CC) $(CFLAGS) -g -o prog2 A2.cpp

clean:
	@echo " [CLN] Removing binary files"
	@rm -f $(BINS)
