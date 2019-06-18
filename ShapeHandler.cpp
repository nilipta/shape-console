#include "ShapeHandler.h"
#include <algorithm>
#include "Circle.h"
#include "Rectangle.h"
#include "Square.h"
#include "Triangle.h"
#include <fstream>
#include <sstream>
#include "Shapes.h"

ShapeHandler::ShapeHandler()
{
	configContent.erase();
	this->readFile();
}

void ShapeHandler::readFile()
{
	std::cout << "File reading Initializing.....(Loading).........."<<std::endl;
	std::ifstream config("D:\\Projects\\Induction\\drawFigures1\\data.txt", std::ifstream::in);
	if(config)
	{
		std::string shape;
		while (!(config>>shape).eof())
		{
			std::cout << "======================= NewConfig ======================" << std::endl;


			Shape* shapePtr = NULL;
			if(shape == "circle")
			{
				std::cout <<"Circle matched... " << std::endl;
				shapePtr = new Circle();
			}

			else if(shape == "rectangle")
			{
				std::cout <<"rectangle matched... " << std::endl;
				shapePtr = new Rectangle();
			}
			else if(shape == "square")
			{
				std::cout <<"square matched... " << std::endl;
				shapePtr = new Square();
			}
			else if(shape ==  "triangle")
			{
				std::cout <<"triangle matched... " << std::endl;
				shapePtr = new Triangle();
			}

			if(shapePtr != NULL)
			{
				//now read the attributes of the shape, make usuer to catch the exception
				try
				{
					config>>(*shapePtr);
				}
				catch(...)
				{
                 	continue;
				}
				shapesVector.push_back(shapePtr);
			}

			std::cout << "==========================   END   ===================== \n" << std::endl;
		}
		config.close();
		printObjectDetails();
	}
}


void ShapeHandler::createShape(E_ShapeID shapeId, std::string NameInArg, double param1Arg, double param2Arg)
{
	Shape* shapePtr = NULL;
	switch(shapeId)
		{
		case e_Circle :
				shapePtr = new Circle(NameInArg, param1Arg, param2Arg);
				break;
		case e_Rectangle :
				shapePtr = new Rectangle(NameInArg, param1Arg, param2Arg);
				break;
		case e_Square :
				shapePtr = new Square(NameInArg, param1Arg, param2Arg);
				break;
		case e_Triangle :
				shapePtr = new Triangle(NameInArg, param1Arg, param2Arg);
				break;
		}
       shapesVector.push_back(shapePtr);
}

int ShapeHandler::deleteShapeObj(E_ShapeID shapeId, std::string shapeNameIn, double param1, double param2 = 0)
{
	std::cout <<"IN ShapeHandler::DeleteShapeObj..." << std::endl;
	std::string stringShapeType;
   	switch(shapeId)
	{
		case e_Circle:	std::cout <<"Circle is going to be deleted....." << std::endl;
				{
					stringShapeType = "circle";
				}
			break;
		case e_Rectangle:  std::cout <<"Rectangle is going to be deleted....." << std::endl;
				{
					stringShapeType = "rectangle";
				}
			break;
		case e_Square:  std::cout <<"Square is going to be deleted....." << std::endl;
				{
					stringShapeType = "square";
				}
			break;
		case e_Triangle:  std::cout <<"Triangle is going to be deleted....." << std::endl;
				{
					stringShapeType = "triangle";
				}
			break;
	}

	for(std::vector<Shape*>::size_type i = 0; i< shapesVector.size() ; i++)
	{
		if(shapesVector[i]->getVerification(stringShapeType, param1, param2))
		{
			std::cout << "Erasing this entry " << std::endl;
			shapesVector.erase (shapesVector.begin()+i);
			break;
		}
	}
    printObjectDetails();
	return 0;
}


void ShapeHandler::printObjectDetails()
{

	std::cout << "\n**********   PRINTING ALL SHAPE DETAILS   **********  |\n" << std::endl;
	std::cout << "The vector sizeof this = " << shapesVector.size() << std::endl;

	for(std::vector<Shape*>::iterator it = shapesVector.begin(); it != shapesVector.end(); ++it)
	{
	   std::cout << *(*it);
	}

	std::cout << "------------------------------------------------------|" << std::endl;
	std::cout << "*********************     Finish      *************** |" << std::endl;

}

void ShapeHandler::saveLatestInfo()
{
	std::ofstream configOut("D:\\Projects\\Induction\\drawFigures1\\data.txt", std::ifstream::out, std::ifstream::app);
	if(configOut)
	for(std::vector<Shape*>::iterator it = shapesVector.begin(); it != shapesVector.end(); ++it)
	{
		(*it)->writeToFile(configOut);
	}
}


void ShapeHandler::printObjectDetailsAscending()
{
	std::vector<Shape*> sortingVectorAscending;
	sortingVectorAscending.assign(shapesVector.begin(), shapesVector.end());

	std::sort(sortingVectorAscending.begin(), sortingVectorAscending.end(), Shape::SortingClass(true));

	std::cout << "--------------------   Ascending    ---------------------------------"<< std::endl;
	std::for_each(sortingVectorAscending.begin(), sortingVectorAscending.end(), Shape::SortingClass(true));
	std::cout << "\n-----------------   Ascending END   ---------------------------------"<< std::endl;
}


void ShapeHandler::printObjectDetailsDescending()
{
	std::vector<Shape*> sortingVectorAscending;
	sortingVectorAscending.assign(shapesVector.begin(), shapesVector.end());

    std::sort(sortingVectorAscending.begin(), sortingVectorAscending.end(), Shape::SortingClass(false));

	std::cout << "--------------------   Descending    ---------------------------------"<< std::endl;
	std::for_each(sortingVectorAscending.begin(), sortingVectorAscending.end(), Shape::SortingClass(true));
	std::cout << "\n-----------------   Descending END   ---------------------------------"<< std::endl;
}


