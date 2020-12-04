all: proj5.exe

EventClass.o: EventClass.h EventClass.cpp constants.h
	g++ -std=c++98 -Wall -c EventClass.cpp -o EventClass.o

IntersectionSimulationClass.o: IntersectionSimulationClass.h IntersectionSimulationClass.cpp constants.h SortedListClass.h EventClass.h FIFOQueueClass.h CarClass.h random.h
	g++ -std=c++98 -Wall -c IntersectionSimulationClass.cpp -o IntersectionSimulationClass.o

CarClass.o: CarClass.h CarClass.cpp constants.h
	g++ -std=c++98 -Wall -c CarClass.cpp -o CarClass.o

random.o: random.h random.cpp
	g++ -std=c++98 -Wall -c random.cpp -o random.o

project5.o: project5.cpp constants.h EventClass.h IntersectionSimulationClass.h CarClass.h random.h LinkedNodeClass.h SortedListClass.h FIFOQueueClass.h
	g++ -std=c++98 -Wall -c project5.cpp -o project5.o

proj5.exe: project5.o constants.h EventClass.o IntersectionSimulationClass.o CarClass.o random.o LinkedNodeClass.h SortedListClass.h FIFOQueueClass.h LinkedNodeClass.inl SortedListClass.inl FIFOQueueClass.inl
	g++ project5.o EventClass.o IntersectionSimulationClass.o CarClass.o random.o -o proj5.exe

clean:
	rm -f *.o *.exe
