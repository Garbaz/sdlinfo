all:
	gcc -lSDL2 -o sdlinfo sdlinfo.c
install:
	sudo cp sdlinfo /usr/bin/sdlinfo
