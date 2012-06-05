#include "ui.h"

using namespace UI;

void VerticleMenu::init() {

}

void VerticleMenu::render() {

}

void VerticleMenu::keyDown(SDLKey key) {
	_comps[num]->keyDown(key);
}

void VerticleMenu::keyUp(SDLKey key) {
	if(key == SDLK_UP || key == SDLK_w) {
		if(num < 0) {
			num = _comps.size()-1;
		}
		
		num--;
	} else if(key == SDLK_DOWN || key == SDLK_s) {
		if(num > _comps.size()-1) {
			num = 0;
		}
		
		num++;
	} else {
		_comps[num]->keyUp(key);
	}
}