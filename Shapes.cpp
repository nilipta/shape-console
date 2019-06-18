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

	std::cout << "Object name = " << shape.shapeObjName << std::endl;
	shape.printAttributes(ob);
	std::cout << "Area Name	  = " << shape.getArea() << std::endl;
}


bool Shape::SortingClass::operator() (Shape* shape1, Shape* shape2)
{
   return flagSortingType ?  (shape1->getArea() <  shape2->getArea())  :  (shape1->getArea() >  shape2->getArea());
}

void Shape::SortingClass::operator() (Shape* shape)
{
	std::cout << (*shape);
}
