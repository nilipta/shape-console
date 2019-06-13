#include "Circle.h"
#include <string>
#include <iostream>

Circle::Circle()
{
	shapeType = "circle";
}

Circle::Circle(std::string strLine)
{

}

std::string Circle::getInfo(){
	std::cout<<"####################################" << std::endl;
	std::cout<<"The information of Circle is  =     " << std::endl;
	std::cout<<"The Radius		of Circle is  =     " << radius <<std::endl;
	std::cout<<"The Center 		of Circle is  =     " << center <<std::endl;
	std::cout<<"-----------------------------------" << std::endl;
	std::string thisConfig = shapeType + " ";//std::to_string(radius)+ " " + std::to_string(center)+ " " + shapeName +"\n";
	return thisConfig;
}

double Circle::getArea(){
	//std::cout<<"The area of circle this = " << 3.14*radius*radius << std::endl;
	return (3.14*radius*radius);
}

bool Circle::getVerification(std::string type, std::string nameParam = "", double param1 = 0, double param2 = 0){
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


