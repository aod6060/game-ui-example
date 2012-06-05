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

// Drawing functions
void UI::drawRect(PointBuffer& vbuf, Point& pos, Point& size) {
	glPushMatrix();
	
	glTranslatef(pos.x, pos.y, 0.0f);
	
	glScalef(size.x, size.y, 0.0f);
	
	glVertexPointer(2, GL_FLOAT, 0, &vbuf[0]);
	
	glEnableClientState(GL_VERTEX_ARRAY);
	
	glDrawArrays(GL_QUADS, 0, vbuf.size());
	
	glDisableClientState(GL_VERTEX_ARRAY);
	
	glPopMatrix();
}

void UI::drawRect(PointBuffer& vbuf, ColorBuffer& cbuf, Point& pos, Point& size) {
	glPushMatrix();
	
	glTranslatef(pos.x, pos.y, 0.0f);
	
	glScalef(size.x, size.y, 0.0f);
	
	glVertexPointer(2, GL_FLOAT, 0, &vbuf[0]);
	glColorPointer(4, GL_FLOAT, 0, &cbuf[0]);
	
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	
	glDrawArrays(GL_QUADS, 0, vbuf.size());
	
	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);
	
	glPopMatrix();
}