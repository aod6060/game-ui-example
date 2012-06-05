#include "ui.h"

using namespace UI;

// Manager
void Manager::setRoot(Comp* comp) {
	_root = comp;
	_root->init();
}

void Manager::render() {
	_root->render();
}

void Manager::keyDown(SDLKey key) {
	_root->keyDown(key);
}

void Manager::keyUp(SDLKey key) {
	_root->keyUp(key);
}

void Manager::release() {
	_root->release();
	delete _root;
	_root = 0;
}


// Container

void Container::release() {
	for(unsigned int i = 0; i < _comps.size(); i++) {
		_comps[i]->release();
		delete _comps[i];
		_comps[i] = 0;
	}
	
	_comps[i] = 0;
}

void Container::addComponent(Comp* comp) {
	comp->init();
	_comps.push_back(comp);
}