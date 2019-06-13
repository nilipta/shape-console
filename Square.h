#ifndef SQUAREH
#define SQUAREH

#include "Shapes.h"
#include <string>

class Square:public Shape{
	public:
		Square();
		std::string getInfo();
		double getArea();
		bool getVerification(std::string , std::string , double , double );
	private:
		ifstream& parseShapeAttributes(ifstream& obj);
		void printAttributes(ostream& coutObj);

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
