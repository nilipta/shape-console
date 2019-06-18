#ifndef CIRCLEH
#define CIRCLEH


#include "Shapes.h"

class Circle:public Shape
{
	public:
		Circle();
		Circle(std::string, double, double);
		double getArea();
		bool getVerification(std::string type, double param1, double param2);
		void writeToFile(std::ofstream& obj);
	private:
		ifstream& parseShapeAttributes(ifstream& obj);
	    void printAttributes(ostream& ob);
		double center;
		double radius;
		std::string shapeType;
};

ifstream& Circle::parseShapeAttributes(ifstream& obj)
{
	obj>>radius;
	obj>>center;
	std::cout <<"Circle = radius = " << radius << " center = " << center << std::endl;
	return obj;
}

void Circle::printAttributes(ostream& ob)
{
	ob << "Circle radius = " << radius << std::endl;
	ob << "Circle center = " << center << std::endl;
}

#endif
