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
		std::string getInfo();
		void getArea();
		bool getVerification(std::string type, std::string nameParam, double param1, double param2);
	private:
		double center;
		double radius;
		std::string shapeName;
		std::string shapeType;
};

#endif
