#ifndef CIRCLEH
#define CIRCLEH


#include "Shapes.h"

class Circle:public Shape
{
	public:
		Circle();
		Circle(std::string strLine);
		std::string getInfo();
		double getArea();
		bool getVerification(std::string type, std::string nameParam, double param1, double param2);
	private:

		ifstream& parseShapeAttributes(ifstream& obj);
		void printAttributes(ostream& ob);
		double center;
		double radius;
		std::string shapeType;
};

ifstream& Circle::parseShapeAttributes(ifstream& obj)
{

	//Circle would be stored in follwoing format
	//circle radius center name(optional)
	obj>>radius;
	//so read radius first
	obj>>center;

   std::cout <<"Circle = radius = " << radius << " center = " << center << std::endl;

	//read name which is optional
	return obj;
};

void Circle::printAttributes(ostream& ob)
{
	ob << "Circle radius = " << radius << std::endl;
	ob << "Circle center = " << center << std::endl;
}

#endif
