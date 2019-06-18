#include <shapes.h>


ifstream& operator>> ( ifstream& obj,Shape& shape)
{
	std::cout << "Inside of the operator overloading.............." << std::endl;
	shape.parseShapeAttributes(obj);

	obj >> std::noskipws;
	char checkNewLineChar;
	std::string tempNameObject ;

	do
	{
		obj >> checkNewLineChar;
	}
	while(checkNewLineChar == ' ');

	if(checkNewLineChar == '\n')
	{
    	//do something is newline is arrived
	}
	else
	{
		obj >> tempNameObject;
		shape.shapeObjName = checkNewLineChar+tempNameObject ;
		std::cout << "Finally shape Name = " << shape.shapeObjName << std::endl;
	}

	obj >> std::skipws;
}

std::string operator>>(std::string str, Shape& shape)
{
	std::cout << "Inside of the string Operator overloading.............." << std::endl;
}

ostream& operator<< (ostream& ob, Shape& shape)
{
	std::cout << "------------------------------------------------------|" << std::endl;
	//
	shape.printAttributes(ob);
	std::cout << "Object name = " << shape.shapeObjName << std::endl;
}
