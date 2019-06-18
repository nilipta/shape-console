#ifndef SQUAREH
#define SQUAREH

#include "Shapes.h"
#include <string>
#include <sstream>

class Square:public Shape{
	public:
		Square();
		double getArea();
		bool getVerification(std::string, double , double );
		void Square::writeToFile(std::ofstream& obj);
	private:
		ifstream& parseShapeAttributes(ifstream& obj);
		void printAttributes(ostream& coutObj);
        std::string getInfo();
		double length;
		std::string shapeType;
};

ifstream& Square::parseShapeAttributes(ifstream& obj)
{
	obj >> length;

	std::cout <<"Square = lenghth = " << length << std::endl;
	return obj;
}

void Square::printAttributes(ostream& ob)
{
	ob <<"Square Length is = " << length <<std::endl;
}

#endif

