
#include "Square.h"


Square::Square()
{
	shapeType = "square";
}

std::string Square::getInfo(){
	std::string thisInfo = " " ;// + std::to_string(length)+ " " + shapeName + "\n";
	return thisInfo;
}

double Square::getArea(){
	return (length * length);
}

bool Square::getVerification(std::string type, double param1 = 0, double param2 = 0){
	if(param1 > 0)
	{
		if(param1 == length && type == shapeType)
		{
			std::cout<<"The get verification MATCHED!!!!!!!" << std::endl;
			return true;
		}
		else
		{
			std::cout<<"The get verification NOT MATCHED!!!!!!!" << std::endl;
			return false;
		}
	}

}


void Square::writeToFile(std::ofstream& obj)
{
	std::cout <<"Square is comitting file..." << std::endl;
	obj<<"square ";
	obj << length;

	if(shapeObjName.size() > 0)
	{
		obj << " " + shapeObjName+"\n";
	}
	else
	{
		obj << " \n";
	}
}
