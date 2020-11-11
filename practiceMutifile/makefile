all: proj3.exe

ImgLoadClass.o: ImgLoadClass.cpp ImgLoadClass.h constants.h
	g++ -std=c++98 -Wall -c ImgLoadClass.cpp -o ImgLoadClass.o

ImgModifyClass.o: ImgModifyClass.cpp ImgModifyClass.h ImgLoadClass.h ImgOutputClass.h ReadPatternClass.h constants.h
	g++ -std=c++98 -Wall -c ImgModifyClass.cpp -o ImgModifyClass.o

ImgOutputClass.o: ImgOutputClass.cpp ImgOutputClass.h ImgOutputClass.h
	g++ -std=c++98 -Wall -c ImgOutputClass.cpp -o ImgOutputClass.o

ReadPatternClass.o: ReadPatternClass.cpp ReadPatternClass.h constants.h
	g++ -std=c++98 -Wall -c ReadPatternClass.cpp -o ReadPatternClass.o

RectangleClass.o: RectangleClass.cpp RectangleClass.h constants.h
	g++ -std=c++98 -Wall -c RectangleClass.cpp -o RectangleClass.o

mainProj3.o: mainProj3.cpp ImgLoadClass.h ImgOutputClass.h ReadPatternClass.h ImgModifyClass.h ImgModifyClass.h constants.h
	g++ -std=c++98 -Wall -c mainProj3.cpp -o mainProj3.o

proj3.exe: ImgLoadClass.o ImgModifyClass.o ImgOutputClass.o ReadPatternClass.o RectangleClass.o
	g++ -std=c++98 -Wall -c mainProj3.o ImgLoadClass.o ImgModifyClass.o ImgOutputClass.o ReadPatternClass.o RectangleClass.o -o proj3.exe

clean:
	rm -f *.o *.exe
