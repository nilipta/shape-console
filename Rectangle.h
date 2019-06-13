#ifndef RECTANGLEH
#define RECTANGLEH

#include "Shapes.h"
#include <string>

class Rectangle:public Shape{
	public:
		Rectangle();
		static bool setParams(std::string str);
		std::string getInfo();
		double getArea();
		bool getVerification(std::string, std::string, double, double);
	private:
		ifstream& parseShapeAttributes(ifstream& obj);
		void printAttributes(ostream& ob);
		double length;
		double height;
		std::string shapeType;
};

ifstream& Rectangle::parseShapeAttributes(ifstream& obj)
{
	obj >> length;
	obj >> height;

	std::cout<<"Rectangle = lenghth = " << length << " height = " << height << std::endl;
}


void Rectangle::printAttributes(ostream& ob)
{
	ob <<"Rectangle Length is = " << length <<std::endl;
	ob <<"Rectangle Height is = " << height <<std::endl;
}

#endif
