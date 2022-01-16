clear:
	del *.o
	del *.exe
all: clear
	g++ -c src/Asset/*.cpp -std=c++14 -m64 -g -Wall -I include
	g++ -c src/Animation/*.cpp -std=c++14 -m64 -g -Wall -I include	
	g++ -c src/*.cpp -std=c++14 -m64 -g -Wall -I include
	g++ *.o -o main -lmingw32 -lSDL2main -lSDL2 -lSDL2_image

run:
	main.exe

build_and_run: all run
