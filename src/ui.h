/*
	This is a simple keyboard gui.
*/
#ifndef UI_H
#define UI_H

#include <SDL.h>
#include <SDL_opengl.h>
#include <SDL_ttf.h>
#include <vector>

namespace UI {
	
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
	};
	
	class Container : public Component {
	protected:
		std::vector<Comp*> _comps;
	public:
	
		virtual void release();
		
		virtual void addComponent(Comp* comp);
	};
	
	class Manager {
		Comp* _root;
	public:

		void setRoot(Comp* comp);
		
		void render();
		
		void keyDown(SDLKey key);
		
		void keyUp(SDLKey key);
		
		void release();
	};
}
#endif