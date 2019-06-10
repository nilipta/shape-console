#include "Rectangle.h"

Triangle::Triangle(std::string strLine){
	shapeType = "triangle";

	std::vector<std::string> vectorTriParams;
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
		vectorTriParams.push_back(commaSeparatedVal);
	}

	if( !std::isnan(std::stod(vectorTriParams[1])) )
	{
		base =  std::stod(vectorTriParams[1]);
	}

	if( !std::isnan(std::stod(vectorTriParams[2])) )
	{
		height =  std::stod(vectorTriParams[2]);
	}

	if( vectorTriParams.size() > 3)
	{
		if(vectorTriParams[3].size() > 1)
		{
			shapeName = vectorTriParams[3];
			std::cout << "The name is " << vectorTriParams[3].size() <<  shapeName << std::endl;
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

void Triangle::area()
{
	std::cout << "Triangle Area"<< std::endl;
}

void Triangle::perimeter(){
	std::cout << "Triangle parameter"<< std::endl;
}

//bool Triangle::setParams(std::string str, Shape& rect){
bool Triangle::setParams(std::string str){
	//std::cout << "Triangle config = \n............>\n"<< str << "\n............."<< std::endl;
	std::vector<std::string> vectorTriParams;

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
		vectorTriParams.push_back(commaSeparatedVal);
		std::cout << "Triangle perameter = "<< commaSeparatedVal << std::endl;
	}

	try{
    	if( !std::isnan(std::stod(vectorTriParams[1]))  && !std::isnan(std::stod(vectorTriParams[2])) )
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

std::string Triangle::getInfo(){
	std::cout<<"####################################" << std::endl;
	std::cout<<"The information of Triangle is  =     " << std::endl;
	std::cout<<"The length		of Triangle is  =     " << base <<std::endl;
	std::cout<<"The height 		of Triangle is  =     " << height <<std::endl;
	std::cout<<"The Name 		of Triangle is  =     " << shapeName <<std::endl;
	std::cout<<"-----------------------------------" << std::endl;
	std::string thisInfo = shapeType + " " +std::to_string(base)+ " " + std::to_string(height) + " " + shapeName + "\n";
	return thisInfo;
}

void Triangle::getArea(){
	std::cout<<"The area of Triangle is = " << 0.5 * base * height << std::endl;
}

bool Triangle::getVerification(std::string type, std::string nameParam = "", double param1 = 0, double param2 = 0){
	if(param1 == base && param2 == height && type==shapeType)
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
