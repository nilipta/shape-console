#include "Rectangle.h"

Square::Square(std::string strLine){
	std::vector<std::string> vectorSqrParams;
	std::string tempStr = strLine;
	std::string commaSeparatedVal;
	while(tempStr.size() > 0)
	{
		commaSeparatedVal = tempStr.substr(0,      tempStr.find(" ")   );
		tempStr = tempStr.erase(  tempStr.find(commaSeparatedVal),    (commaSeparatedVal.size()+1)     );
		vectorSqrParams.push_back(commaSeparatedVal);
	}
	std::cout << "End of loop = " << vectorSqrParams[1] << std::endl;
	std::cout << "End of loop = " << vectorSqrParams[2] << std::endl;

	if( !std::isnan(std::stod(vectorSqrParams[1])) )
		length =  std::stod(vectorSqrParams[1]);

	if( vectorSqrParams[2].size() > 0 )
	{
		shapeName =  vectorSqrParams[2];
	}
}

void Square::area()
{
	std::cout << "Square Area"<< std::endl;
}

void Square::perimeter(){
	std::cout << "Square perimeter"<< std::endl;
}

bool Square::setParams(std::string str, Shape& rect){
	std::cout << "Square config = \n............>\n"<< str << "\n............."<< std::endl;
	std::vector<std::string> vectorSqrParams;

	std::string tempStr = str;
	std::string commaSeparatedVal;
	while(tempStr.size() > 0)
	{
		commaSeparatedVal = tempStr.substr(0,      tempStr.find(" ")   );
		tempStr = tempStr.erase(  tempStr.find(commaSeparatedVal),    (commaSeparatedVal.size()+1)     );
		vectorSqrParams.push_back(commaSeparatedVal);
			std::cout << "Square perimeter = "<< commaSeparatedVal << std::endl;
	}

	if( !std::isnan(std::stod(vectorSqrParams[1]))  )
	{
   		std::cout << "(OK) object will be created ()()()()()"<< std::endl;
		return true;
	}
	return false;
}

void Square::getInfo(){
	std::cout<<"####################################" << std::endl;
	std::cout<<"The information of Square is  =     " << std::endl;
	std::cout<<"The length		of Square is  =     " << length <<std::endl;
	std::cout<<"The Name 		of Square is  =     " << shapeName <<std::endl;
	std::cout<<"####################################" << std::endl;
}