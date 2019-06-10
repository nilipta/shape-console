#ifndef MENU_H
#define MENU_H

#include "ShapeHandler.h"
#include "ShapeHandler.cpp"

class Menu {
	public:
		Menu(){};
		void start();
		bool startOp();
	private:
		void circleDialog		(std::string &circleNameIn, double &radIn, double &centerIn);
		void rectangleDialog	(std::string &circleNameIn, double &param1, double &param2);
		void SquareDialog		(std::string &SquareNameIn, double &param1);
		void TrianleDialog		(std::string &circleNameIn, double &param1, double &param2);

};
#endif

