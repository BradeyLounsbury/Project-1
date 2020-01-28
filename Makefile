#Variables
CC = g++
CFLAGS = -g -Wall -std=c++11

a.exe: MyTime.o Runtime.o Runjournal.o main.o
	$(CC) $(CFLAGS) MyTime.o Runtime.o Runjournal.o main.o -o a.exe

Runjournal.o: Runjournal.cc Runjournal.h
	$(CC) -c $(CFLAGS) Runjournal.cc -o Runjournal.o

Runtime.o: Runtime.cc Runtime.h
	$(CC) -c $(CFLAGS) Runtime.cc -o Runtime.o

MyTime.o: MyTime.cc MyTime.h
	$(CC) -c $(CFLAGS) MyTime.cc -o MyTime.o

main.o: main.cc 
	$(CC) -c $(CFLAGS) main.cc -o main.o

clean:
	rm -rf MyTime.o Runtime.o Runjournal.o a.exe