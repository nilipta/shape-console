#include "Circle.h"
#include <string>
#include <iostream>

Circle::Circle()
{
	shapeType = "circle";
}


Circle::Circle(std::string circleObjName, double radiusArg, double centerArg) : Shape(circleObjName)
{
	radius = radiusArg ;
	center = centerArg;
}


double Circle::getArea(){
	//std::cout<<"The area of circle this = " << 3.14*radius*radius << std::endl;
	return (3.14*radius*radius);
}

bool Circle::getVerification(std::string type, double param1 = 0, double param2 = 0){
	if(param1 == radius && param2 == center && type == shapeType)
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


/**  creating config string for circle   ***/
void Circle::writeToFile(std::ofstream& obj)
{
	std::cout <<"Circle is comitting file..." << std::endl;
	obj<<"circle ";
	obj << radius;
	obj << " ";
	obj << center;

	if(shapeObjName.size() > 0)
	{
		obj << " " + shapeObjName+"\n";
	}
	else
	{
		obj << " \n";
	}
}

