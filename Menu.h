#ifndef MENU_H
#define MENU_H

#include "ShapeHandler.h"
#include "ShapeHandler.cpp"

class Menu {
	public:
		Menu(){};
		void start();
	private:
		ShapeHandler shapeHandler;
};
#endif

