#include "ui.h"

using namespace UI;

// Manager
void Manager::setRoot(Component* comp) {
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

// Comp

void Component::setCallback(Callback* ac) {
	this->callback = ac;
}

void Component::setSize(float w, float h) {
	this->w = w;
	this->h = h;
}

void Component::setPos(float x, float y) {
	this->x = x;
	this->y = y;
}

void Component::setVisable(bool vis) {
	this->visible = vis;
}

bool Component::isVisable() {
	return this->visible;
}
// Container

void Container::release() {
	for(unsigned int i = 0; i < _comps.size(); i++) {
		_comps[i]->release();
		delete _comps[i];
		_comps[i] = 0;
	}
	
	_comps.clear();
}

void Container::addComponent(Component* comp) {
	comp->init();
	_comps.push_back(comp);
}