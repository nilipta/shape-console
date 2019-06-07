#include "Rectangle.h"

Rectangle::Rectangle(std::string strLine){
	std::vector<std::string> vectorRectParams;
	std::string tempStr = strLine;
	std::string commaSeparatedVal;
	while(tempStr.size() > 0)
	{
		commaSeparatedVal = tempStr.substr(0,      tempStr.find(" ")   );
		tempStr = tempStr.erase(  tempStr.find(commaSeparatedVal),    (commaSeparatedVal.size()+1)     );
		vectorRectParams.push_back(commaSeparatedVal);
	}
	std::cout << "End of loop = " << vectorRectParams[1] << std::endl;
	std::cout << "End of loop = " << vectorRectParams[2] << std::endl;

	if( !std::isnan(std::stod(vectorRectParams[1])) )
	{
		length =  std::stod(vectorRectParams[1]);
	}

	if( !std::isnan(std::stod(vectorRectParams[2])) )
	{
    	height =  std::stod(vectorRectParams[2]);
	}

	if( vectorRectParams[3].size() > 0 )
	{
    	shapeName =  vectorRectParams[2];
	}

}

void Rectangle::area()
{
	std::cout << "Rectangle Area"<< std::endl;
}

void Rectangle::perimeter(){
	std::cout << "Rectangle perimeter"<< std::endl;
}

bool Rectangle::setParams(std::string str, Shape& rect){
	std::cout << "Rectangle config = \n............>\n"<< str << "\n............."<< std::endl;
	std::vector<std::string> vectorRectParams;

	std::string tempStr = str;
	std::string commaSeparatedVal;
	while(tempStr.size() > 0)
	{
		commaSeparatedVal = tempStr.substr(0,      tempStr.find(" ")   );
		tempStr = tempStr.erase(  tempStr.find(commaSeparatedVal),    (commaSeparatedVal.size()+1)     );
		vectorRectParams.push_back(commaSeparatedVal);
	}

	if( !std::isnan(std::stod(vectorRectParams[1]))  && !std::isnan(std::stod(vectorRectParams[2])) )
	{
   		std::cout << "(OK) object will be created ()()()()()"<< std::endl;
		return true;
	}
	return false;
}

void Rectangle::getInfo(){
	std::cout<<"####################################" << std::endl;
	std::cout<<"The information of Rectangle is  =     " << std::endl;
	std::cout<<"The length		of Rectangle is  =     " << length <<std::endl;
	std::cout<<"The height 		of Rectangle is  =     " << height <<std::endl;
	std::cout<<"The Name 		of Rectangle is  =     " << shapeName <<std::endl;
	std::cout<<"####################################" << std::endl;
}