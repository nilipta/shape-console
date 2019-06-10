#include "Rectangle.h"

Square::Square(std::string strLine){
	shapeType = "square";
	std::vector<std::string> vectorSqrParams;
	std::string tempStr = strLine;
	std::string commaSeparatedVal;
	while(tempStr.size() > 0)
	{
		commaSeparatedVal = tempStr.substr(0,      tempStr.find(" ")   );
		if(tempStr.size() > (commaSeparatedVal.size()+1))
		{
			tempStr = tempStr.erase(  tempStr.find(commaSeparatedVal),    (commaSeparatedVal.size()+1)     );
		}
		else
		{
			tempStr.clear();
			//break;
		}
		vectorSqrParams.push_back(commaSeparatedVal);
	}

	if( !std::isnan(std::stod(vectorSqrParams[1])) )
		length =  std::stod(vectorSqrParams[1]);

	if( vectorSqrParams.size() > 2)
	{
		if(vectorSqrParams[2].size() > 1)
		{
			shapeName = vectorSqrParams[2];
			std::cout << "The name is " << vectorSqrParams[2].size() <<  shapeName << std::endl;
		}

		else
		{
			shapeName = "No_Name";
			std::cout << "The name is " << shapeName << std::endl;
		}
	}
	else
	{
		shapeName = "No_Name";
		std::cout << "The name is " << shapeName << std::endl;
	}
}

void Square::area()
{
	std::cout << "Square Area"<< std::endl;
}

void Square::perimeter(){
	std::cout << "Square perimeter"<< std::endl;
}

//bool Square::setParams(std::string str, Shape& rect){
bool Square::setParams(std::string str){
	//std::cout << "Square config = \n............>\n"<< str << "\n............."<< std::endl;
	std::vector<std::string> vectorSqrParams;

	std::string tempStr = str;
	std::string commaSeparatedVal;
	while(tempStr.size() > 0)
	{
		commaSeparatedVal = tempStr.substr(0,      tempStr.find(" ")   );
		if(tempStr.size() > (commaSeparatedVal.size()+1))
		{
			tempStr = tempStr.erase(  tempStr.find(commaSeparatedVal),    (commaSeparatedVal.size()+1)     );
		}
		else
		{
			tempStr.clear();
		}
		vectorSqrParams.push_back(commaSeparatedVal);
		std::cout << "Square perimeter = "<< commaSeparatedVal << std::endl;
	}

	try{
    	if( !std::isnan(std::stod(vectorSqrParams[1]))  )
		{
			std::cout <<"(OK) object is to be created (-..-)"<< std::endl;
			return true;
		}
	}
	catch(...){
    	return false;
	}

	return false;
}

std::string Square::getInfo(){
	std::cout<<"####################################" << std::endl;
	std::cout<<"The information of Square is  =     " << std::endl;
	std::cout<<"The length		of Square is  =     " << length <<std::endl;
	std::cout<<"The Name 		of Square is  =     " << shapeName <<std::endl;
	std::cout<<"-----------------------------------" << std::endl;
	std::string thisInfo = shapeType+ " " + std::to_string(length)+ " " + shapeName + "\n";
	return thisInfo;
}

void Square::getArea(){
	std::cout<<"The area of Square this = " << length * length << std::endl;
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
