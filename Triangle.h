#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shapes.h"

class Triangle:public Shape{
	public:
		Triangle();
		std::string getInfo();
		double getArea();
	    bool Triangle::getVerification(std::string type, std::string , double, double );

	private:
		ifstream& parseShapeAttributes(ifstream& obj);
		void  printAttributes(ostream& ob);
		double base;
		double height;
		std::string shapeName;
		std::string shapeType;
};

ifstream& Triangle::parseShapeAttributes(ifstream& obj)
{
	obj >> base;
	obj >> height;
	obj >> shapeName;

	return obj;
}

void Triangle::printAttributes(ostream& ob)
{
	ob << "Triangle base = " << base << std::endl;
	ob << "Triangle Height = " << base << std::endl;
}

#endif
