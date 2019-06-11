#include "Rectangle.h"

Rectangle::Rectangle(std::string strLine){
	shapeType = "rectangle";
	std::vector<std::string> vectorRectParams;
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
		vectorRectParams.push_back(commaSeparatedVal);
	}

	if( !std::isnan(std::stod(vectorRectParams[1])) )
	{
		length =  std::stod(vectorRectParams[1]);
	}

	if( !std::isnan(std::stod(vectorRectParams[2])) )
	{
    	height =  std::stod(vectorRectParams[2]);
	}

	if( vectorRectParams.size() > 3)
	{
		if(vectorRectParams[3].size() > 1)
		{
			shapeName = vectorRectParams[3];
			std::cout << "The name is " << vectorRectParams[3].size() <<  shapeName << std::endl;
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

//bool Rectangle::setParams(std::string str, Shape& rect){
bool Rectangle::setParams(std::string str){
	//std::cout << "Rectangle config = \n............>\n"<< str << "\n............."<< std::endl;
	std::vector<std::string> vectorRectParams;

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
		vectorRectParams.push_back(commaSeparatedVal);
		std::cout << "Rectangle parameter = "<< commaSeparatedVal << std::endl;
	}

	try{
    	if( !std::isnan(std::stod(vectorRectParams[1]))  && !std::isnan(std::stod(vectorRectParams[2])) )
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

std::string Rectangle::getInfo(){
	std::cout<<"####################################" << std::endl;
	std::cout<<"The information of Rectangle is  =     " << std::endl;
	std::cout<<"The length		of Rectangle is  =     " << length <<std::endl;
	std::cout<<"The height 		of Rectangle is  =     " << height <<std::endl;
	std::cout<<"The Name 		of Rectangle is  =     " << shapeName <<std::endl;
	std::cout<<"-----------------------------------" << std::endl;
	std::string thisInfo = shapeType + " " +std::to_string(length)+ " " + std::to_string(height) + " " + shapeName + "\n";
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
