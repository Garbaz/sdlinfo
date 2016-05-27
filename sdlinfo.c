/*
TODO:
- Fix odd characters (memset? Wrong memcpy? Keep track of bytes read?)
                                            -------------------------
                                                    ^That one^

*/

#include <SDL2/SDL.h>
#include <unistd.h>

#define DEFAULT_TITLE ""
#define BUFFER_SIZE 1024

int main(int argc, char* argv[])
{
	if(argc < 2)
	{
		char buffer[BUFFER_SIZE];
		char * text = (char*) malloc(BUFFER_SIZE);
		unsigned int c = 1;
		while(read(0,&buffer,BUFFER_SIZE) > 0)
		{
			if(c > 1) text = realloc(text, BUFFER_SIZE * c);
			memcpy(text + (c-1) * BUFFER_SIZE, buffer, BUFFER_SIZE);
			c++;
		}
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, DEFAULT_TITLE, text, NULL);
	}
	else if(argc < 3)
	{
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, DEFAULT_TITLE, argv[1], NULL);
	}
	else
	{
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, argv[2], argv[1], NULL);
	}
	
	return 0;
}
