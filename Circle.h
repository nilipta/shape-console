#ifndef CIRCLE_H
#define CIRCLE_H

#include <cmath>
#include "Shapes.h"

class Circle:public Shape
{
	public:
		Circle(std::string strLine);
		void area();
		double perimeter();
		static bool setParams(std::string str,Shape& circle);
		void getInfo();
	private:
		double center;
		double radius;
		std::string shapeName;
};

#endif
