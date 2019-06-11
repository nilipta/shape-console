#include "Circle.h"

Circle::Circle(std::string strLine)
{
	shapeType = "circle";

	std::vector<std::string> vectorCircleParams;
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
		}
		vectorCircleParams.push_back(commaSeparatedVal);
		std::cout <<"Square perimeter = " << commaSeparatedVal<< std::endl;
	}

	if( !std::isnan(std::stod(vectorCircleParams[1])) )
	{
		radius =  std::stod(vectorCircleParams[1]);
	}

	if( !std::isnan(std::stod(vectorCircleParams[2])) )
	{
		center =  std::stod(vectorCircleParams[2]);
	}

	if( vectorCircleParams.size() > 3)
	{
		if(vectorCircleParams[3].size() > 1)
		{
			shapeName = vectorCircleParams[3];
			std::cout << "The name is " <<   shapeName << std::endl;
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


//bool Circle::setParams(std::string str, Shape& objCircle)
bool Circle::setParams(std::string str)
{
	//std::cout << "circle config = \n............>\n"<< str << "\n............."<< std::endl;
	std::vector<std::string> vectorCircleParams;

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
		vectorCircleParams.push_back(commaSeparatedVal);
	}
	try{
    	if(!std::isnan(std::stod(vectorCircleParams[1]))  && !std::isnan(std::stod(vectorCircleParams[2])))
		{
			std::cout <<"(OK) object is to be created (-..-)"<< std::endl;
			return true;
		}
	}
	catch(...)
	{
		return false;
	}

	return false;
}

std::string Circle::getInfo(){
	std::cout<<"####################################" << std::endl;
	std::cout<<"The information of Circle is  =     " << std::endl;
	std::cout<<"The Radius		of Circle is  =     " << radius <<std::endl;
	std::cout<<"The Center 		of Circle is  =     " << center <<std::endl;
	std::cout<<"The Name 		of Circle is  =     " << shapeName <<std::endl;
	std::cout<<"-----------------------------------" << std::endl;
	std::string thisConfig = shapeType + " "+ std::to_string(radius)+ " " + std::to_string(center)+ " " + shapeName +"\n";
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


