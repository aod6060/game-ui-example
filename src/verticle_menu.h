/*
	This is a verticle menu implanmentation for this simple ui
	
	pretty much to use this you'll need to use the keyboard like so
	
	[new]<-
	[load]
	[exit]
	
	basically you'll be using the up and down arrow keys or s and w keys to 
	
	move around the menu...
	
	if you go all the way to the bottom then it will go back to the top of the
	menu
*/
#ifndef VERTICLE_MENU_H
#define VERTICLE_MENU_H

#include "ui.h"

namespace UI {
	class VerticleMenu : public Container {
	
		int num;
		
	public:
		
		VerticleMenu() : num(0) {}
		
		virtual void init();
		
		virtual void render();
		
		virtual void keyDown(SDLKey key);
		
		virtual void keyUp(SDLKey key);
		
	};
	
}
#endif