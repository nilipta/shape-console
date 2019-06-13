#include "Square.h"


Square::Square()
{
	shapeType = "circle";
}

std::string Square::getInfo(){
	std::string thisInfo = shapeType+ " ";// + std::to_string(length)+ " " + shapeName + "\n";
	return thisInfo;
}

double Square::getArea(){
	return (length * length);
}

bool Square::getVerification(std::string type, std::string nameParam = "", double param1 = 0, double param2 = 0){
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
