#ifndef SHAPEHANDLER_H
#define SHAPEHANDLER_H

#include <fstream>
#include "Circle.h"
#include "Circle.cpp"

class ShapeHandler{
	public:
		void setWorkShape(int shapeid);
	private:
		void readFile();
        Shape *shapeObj;
};

#endif
