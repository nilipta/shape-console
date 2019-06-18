#include <vector>
#include "Triangle.h"

Triangle::Triangle()
{
	shapeType = "triangle";
}

Triangle::Triangle(std::string shapeNameArg, double param1 = 0, double param2 = 0): Shape(shapeNameArg)
{
	base = param1;
	height = param2;
}


std::string Triangle::getInfo(){
	std::cout<<"------------------------------------" << std::endl;
	std::cout<<"The information of Triangle is  =     " << std::endl;
	std::cout<<"The length		of Triangle is  =     " << base <<std::endl;
	std::cout<<"The height 		of Triangle is  =     " << height <<std::endl;
	std::cout<<"-----------------------------------" << std::endl;
	std::string thisInfo("tEST");// +std::to_string(base)+ " " + std::to_string(height) + " " + shapeName + "\n";
	return thisInfo;
}

double Triangle::getArea(){
	//std::cout<<"Base = " << base << " Height = " << height <<  std::endl;
	return (0.5 * base * height);
}

bool Triangle::getVerification(std::string type, double param1 = 0, double param2 = 0){
	if(param1 == base && param2 == height && type == shapeType)
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


void Triangle::writeToFile(std::ofstream& obj)
{
	std::cout <<"Triangle is comitting file..." << std::endl;
	obj<<"triangle ";
	obj << base;
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
