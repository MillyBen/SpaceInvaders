all: AppState.o SpaceInvaders.o
	g++ -o SpaceInvaders SpaceInvaders.o AppState.o `pkg-config --libs --cflags sdl3`

SpaceInvaders.o: SpaceInvaders.cpp AppState.h
	g++ -c SpaceInvaders.cpp

AppState.o: AppState.cpp AppState.h
	g++ -c AppState.cpp 

clean:
	rm *.o SpaceInvaders