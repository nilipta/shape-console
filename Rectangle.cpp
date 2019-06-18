#include "Rectangle.h"
#include <string>
#include <iostream>
#include <vector>


Rectangle::Rectangle()
{
	shapeType = "rectangle";
}


Rectangle::Rectangle(std::string shapeNameArg, double param1 = 0, double param2 = 0): Shape(shapeNameArg)
{
	length = param1;
	height = param2;
}


double Rectangle::getArea(){
//	std::cout<<"The area of Rectangle is = " << length * height << std::endl;
	return (length * height);
}


bool Rectangle::getVerification(std::string type, double param1 = 0, double param2 = 0){
	if(param1 == length && param2 == height && type==shapeType)
	{
		std::cout<<"The get verification MATCHED!!!!!!!" << std::endl;
        return true;
	}
	else
	{
		std::cout<<"The get verification NOT  MATCHED!!!!!!!" << std::endl;
    	return false;
	}
}


void Rectangle::writeToFile(std::ofstream& obj)
{
	std::cout <<"Rectangle is comitting file..." << std::endl;
	obj<<"rectangle ";
	obj << length;
	obj << " ";
	obj << height;

	if(shapeObjName.size() > 0)
	{
		obj << " " + shapeObjName+"\n";
	}
	else
	{
		obj << " \n";
	}
}
