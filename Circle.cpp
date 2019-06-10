#include "Circle.h"

Circle::Circle(std::string strLine)
{
	//<space>config<space>
	std::string firstConfigStr = strLine;
	firstConfigStr = firstConfigStr.erase((firstConfigStr.find(" ",((firstConfigStr.find(" "))+1))));
	firstConfigStr  = firstConfigStr.substr((firstConfigStr.find(" "))+1);

	double tempRadius;
	tempRadius = std::stod(firstConfigStr);
	if(!std::isnan(tempRadius))
		radius = tempRadius;
	else
		radius = 0.0;

	//<space>config<space>
	std::string secondConfigStr = strLine;
	secondConfigStr =  secondConfigStr.substr((secondConfigStr.find(" ",((secondConfigStr.find(firstConfigStr))+1)))+1);
	secondConfigStr  = secondConfigStr.substr(0,(secondConfigStr.find(" "))+1);

	double tempCenter;
	tempCenter = std::stod(secondConfigStr);
	if(!std::isnan(tempCenter))
		center = tempCenter;
	else
		center = 0.0;

	//<space>config<space>
    std::string thirdConfigStr = strLine;
	thirdConfigStr =  thirdConfigStr.substr((thirdConfigStr.find(" ",((thirdConfigStr.find(secondConfigStr))+1)))+1);
	thirdConfigStr  = thirdConfigStr.substr(0,(thirdConfigStr.find("\n")));
	if(thirdConfigStr.size() > 1)
	{
		shapeName = thirdConfigStr;
		std::cout << "The name is " << thirdConfigStr.size() <<  shapeName << std::endl;
	}

	else
	{
		shapeName = "No Name";
		std::cout << "The name is " << shapeName << std::endl;
	}
}

void Circle::area(){
	std::cout << "The Area of circle is to be printed" << std::endl;
	double area = 3.14 * radius * radius;
}

double Circle::perimeter(){
    std::cout << "The perimeter of circle is to be printed" << std::endl;
	return 100;
}

bool Circle::setParams(std::string str, Shape& objCircle)
{
	//std::cout << "circle config = \n............>\n"<< str << "\n............."<< std::endl;

	//<space>config<space>
	std::string firstConfigStr = str;
	firstConfigStr = firstConfigStr.erase((firstConfigStr.find(" ",((firstConfigStr.find(" "))+1))));
	firstConfigStr  = firstConfigStr.substr((firstConfigStr.find(" "))+1);

	double tempRadius;
	tempRadius = std::stod(firstConfigStr);
	std::cout << "1st argument(float)  =" << tempRadius << std::endl;

	//<space>config<space>
	std::string secondConfigStr = str;
	secondConfigStr =  secondConfigStr.substr((secondConfigStr.find(" ",((secondConfigStr.find(firstConfigStr))+1)))+1);
	secondConfigStr  = secondConfigStr.substr(0,(secondConfigStr.find(" "))+1);

	double tempCenter;
	tempCenter = std::stod(secondConfigStr);
	std::cout << "2nd argument(float)  =" << tempCenter << std::endl;



	if(tempRadius > 0 && !std::isnan(tempCenter))
	{
		std::cout << "(OK) object will be created ()()()()()"<< std::endl;
		return true;
	}
	return false;
}

void Circle::getInfo(){
	std::cout<<"####################################" << std::endl;
	std::cout<<"The information of Circle is  =     " << std::endl;
	std::cout<<"The Radius		of Circle is  =     " << radius <<std::endl;
	std::cout<<"The Center 		of Circle is  =     " << center <<std::endl;
	std::cout<<"The Name 		of Circle is  =     " << shapeName <<std::endl;
	std::cout<<"-----------------------------------" << std::endl;
}

void Circle::getArea(){
	std::cout<<"The area of circle this = " << 3.14*radius*radius << std::endl;
}

bool Circle::getVerification(std::string nameParam = "", double param1 = 0, double param2 = 0){
	if(param1 == radius && param2 == center)
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


