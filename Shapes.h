#ifndef SHAPES_H
#define SHAPES_H

#include <string>
#include <fstream>
#include <iostream>

class Shape{
	public:
		Shape(){};
		Shape(const std::string shapeName){};

		void setName(){std::cout<<"Base class set name called"<<std::endl;}
		virtual std::string getInfo() {return "NULL";}
		virtual double getArea(){return 0;}
		friend ifstream& operator>>( ifstream& obj,Shape& shape);
		friend std::string operator>>(std::string str, Shape& shape);
		friend ostream& operator<< (ostream& ob, Shape& shape);
	protected:
	private:
		virtual ifstream& parseShapeAttributes(ifstream& obj){};
        virtual  void printAttributes(ostream& ob){};
	    std::string  shapeObjName;
};

ifstream& operator>> ( ifstream& obj,Shape& shape)
{
	std::cout << "Inside of the operator ovceroading.............." << std::endl;
	shape.parseShapeAttributes(obj);
	obj >> shape.shapeObjName;
}

std::string operator>>(std::string str, Shape& shape)
{
	std::cout << "Inside of the string Operator ovceroading.............." << std::endl;
}

ostream& operator<< (ostream& ob, Shape& shape)
{
	std::cout << "------------------------------------------------------" << std::endl;
	//
	shape.printAttributes(ob);
	std::cout << "Object name = " << shape.shapeObjName << std::endl;
}
#endif
