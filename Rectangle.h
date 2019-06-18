#ifndef RECTANGLEH
#define RECTANGLEH

#include "Shapes.h"
#include <string>

class Rectangle:public Shape{
	public:
		Rectangle();
		static bool setParams(std::string str);
		double getArea();
		bool getVerification(std::string, double, double);
		void Rectangle::writeToFile(std::ofstream& obj);
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

