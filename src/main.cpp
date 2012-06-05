#include <SDL.h>
#include <SDL_opengl.h>
#include <SDL_ttf.h>

using namespace std;

static bool run = true;

int main(int argc, char** argv) {


	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_SetVideoMode(640, 480, 32, SDL_OPENGL);
	
	SDL_WM_SetCaption("GAME GUI!!!", 0);
	
	
	TTF_Init();
	
	
	glDisable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0f, 640.0f, 480.0f, 0.0f);
	glMatrixMode(GL_MODELVIEW);
	
	// Load My Stuff
	
	while(run) {
		SDL_Event ev;
		
		while(SDL_PollEvent(&ev)) {
			if(ev.type == SDL_QUIT) {
				run = false;
			}
		}
		
		glClear(GL_COLOR_BUFFER_BIT);
		glLoadIdentity();
		
		
		SDL_GL_SwapBuffers();
	}
	
	TTF_Quit();
	
	SDL_Quit();
	
	return 0;
}