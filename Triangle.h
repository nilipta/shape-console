#ifndef TRIANGLEH
#define TRIANGLEH

#include "Shapes.h"

class Triangle:public Shape{
	public:
		Triangle();
		std::string getInfo();
		double getArea();
		bool getVerification(std::string type, double, double );
		void writeToFile(std::ofstream& obj);
	private:
		ifstream& parseShapeAttributes(ifstream& obj);
		void  printAttributes(ostream& ob);
		double base;
		double height;
		std::string shapeType;
};

ifstream& Triangle::parseShapeAttributes(ifstream& obj)
{
	obj >> base;
	obj >> height;

	std::cout <<"Traingle base = " << base << " Height = " << height<< std::endl;

	return obj;
}

void Triangle::printAttributes(ostream& ob)
{
	ob << "Triangle base = " << base << std::endl;
	ob << "Triangle Height = " << height << std::endl;
}

#endif

