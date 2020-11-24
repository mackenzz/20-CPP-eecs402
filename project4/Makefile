all: proj4.exe

LinkedNodeClass.o: LinkedNodeClass.h LinkedNodeClass.cpp
	g++ -std=c++98 -Wall -c LinkedNodeClass.cpp -o LinkedNodeClass.o

SortedListClass.o: SortedListClass.h SortedListClass.cpp LinkedNodeClass.h
	g++ -std=c++98 -Wall -c SortedListClass.cpp -o SortedListClass.o

FIFOQueueClass.o: FIFOQueueClass.h FIFOQueueClass.cpp LinkedNodeClass.h
	g++ -std=c++98 -Wall -c FIFOQueueClass.cpp -o FIFOQueueClass.o

LIFOStackClass.o: LIFOStackClass.h LIFOStackClass.cpp LinkedNodeClass.h
	g++ -std=c++98 -Wall -c LIFOStackClass.cpp -o LIFOStackClass.o

main.o: main.cpp LinkedNodeClass.h SortedListClass.h FIFOQueueClass.h LIFOStackClass.h
	g++ -std=c++98 -Wall -c main.cpp -o main.o

proj4.exe: main.o LinkedNodeClass.o SortedListClass.o FIFOQueueClass.o LIFOStackClass.o
	g++ main.o LinkedNodeClass.o SortedListClass.o FIFOQueueClass.o LIFOStackClass.o -o proj4.exe

clean:
	rm -f *.o *.exe
