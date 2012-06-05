/*
	This is the core file that contains generic stuff for 
	this library.  Every compoent in this simple UI Example
	is need inorder to do stuff and to show stuff to the screen
*/

#ifndef CORE_H
#define CORE_H

#include <SDL.h>
#include <SDL_opengl.h>
#include <SDL_ttf.h>
#include <vector>

namespace UI {
	
	// Drawing
	// Point primitive
	struct Point {
		float x, y;
		
		Point() : x(0), y(0) {}
		Point(float x, float y) : x(x), y(y) {}
	};
	
	// Point Buffer
	typedef std::vector<Point> PointBuffer;
	
	// Color primitive
	struct Color {
		float r, g, b, a;
		
		Color() : r(1), g(1), b(1), a(1) {}
		
		Color(float r, float g, float b, float a) : r(r), g(g), b(b), a(a) {}
	};
	
	// Color Buffer
	typedef std::vector<Color> ColorBuffer;
	
	void drawRect(PointBuffer& vbuf, Point& pos, Point& size);
	
	void drawRect(PointBuffer& vbuf, ColorBuffer& cbuf, Point& pos, Point& size);
	
	
	class Callback {
	public:
		virtual void fun();
	};
	
	class Component {
	protected:
		float x, y, w, h; // SetSize
		bool visible;
		Callback* callback;
	public:
		
		virtual void init() = 0;
		
		virtual void render() = 0;
		
		virtual void keyDown(SDLKey key) = 0;
		
		virtual void keyUp(SDLKey key) = 0;
		
		virtual void release() = 0;
		
		void setCallback(Callback* ac);
		
		void setSize(float w, float h);
		
		void setPos(float x, float y);
		
		void setVisable(bool vis);
		
		bool isVisable();
	};
	
	class Container : public Component {
	protected:
		std::vector<Component*> _comps;
	public:
	
		virtual void release();
		
		virtual void addComponent(Component* comp);
	};
	
	class Manager {
		Component* _root;
	public:

		void setRoot(Component* comp);
		
		void render();
		
		void keyDown(SDLKey key);
		
		void keyUp(SDLKey key);
		
		void release();
	};
}

#endif