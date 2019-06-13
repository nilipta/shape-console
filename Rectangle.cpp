#include "Rectangle.h"
#include <string>
#include <iostream>
#include <vector>


Rectangle::Rectangle()
{
}

std::string Rectangle::getInfo(){
	std::cout<<"####################################" << std::endl;
	std::cout<<"The information of Rectangle is  =     " << std::endl;
	std::cout<<"The length		of Rectangle is  =     " << length <<std::endl;
	std::cout<<"The height 		of Rectangle is  =     " << height <<std::endl;
	std::cout<<"-----------------------------------" << std::endl;
	std::string thisInfo = shapeType + " ";// +std::to_string(length)+ " " + std::to_string(height) + " " + shapeName + "\n";
	return thisInfo;
}

double Rectangle::getArea(){
//	std::cout<<"The area of Rectangle is = " << length * height << std::endl;
	return (length * height);
}

bool Rectangle::getVerification(std::string type, std::string nameParam = "", double param1 = 0, double param2 = 0){
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
