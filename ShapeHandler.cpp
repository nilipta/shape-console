#include "ShapeHandler.h"
#include <algorithm>
#include "Circle.h"
#include "Circle.cpp"
#include "Rectangle.h"
#include "Rectangle.cpp"
#include "Square.h"
#include "Square.cpp"
#include "Triangle.h"
#include "Triangle.cpp"
#include <fstream>
#include <sstream>

ShapeHandler::ShapeHandler()
{
	{std::cout << "Constructing ShapeHandler Object " << std::endl;}
	configContent.erase();
	this->readFile();
}

void ShapeHandler::readFile()
{
	std::cout << "File reading Initializing.....(Loading).........."<<std::endl;
	std::ifstream config("D:\\Projects\\Induction\\drawFigures\\data.txt", std::ifstream::in);
	std::cout << "config  = "<< config <<std::endl;
	if(config)
	{
		std::string shape;
        std::cout <<"Inside in debug function ..... " << std::endl;
		while (!(config>>shape).eof())
		{
			std::cout << "=========================== NewLine ========================" << std::endl;
			

			Shape* shapePtr = NULL;
			if(shape == "circle")
			{
				std::cout <<"Circle matched/... " << std::endl;
				shapePtr = new Circle();
			}

			else if(shape == "rectangle")
			{
				std::cout <<"rectangle matched/... " << std::endl;
				shapePtr = new Rectangle();
			}
			else if(shape == "square")
			{
				std::cout <<"square matched/... " << std::endl;
				shapePtr = new Square();
			}
			else if(shape ==  "triangle")
			{
				std::cout <<"triangle matched/... " << std::endl;
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

			std::cout << "===========================   END   ======================== \n" << std::endl;
		}
		config.close();

		std::cout << "^^^^^^^^^^^^^^^^^^  PRINTING ALL SHAPE DETAILS  ^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << std::endl;
		for(std::vector<Shape*>::iterator it = shapesVector.begin(); it != shapesVector.end(); ++it)
		{
		   std::cout << *(*it);
		}
		std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << std::endl;
	}
}


/*Shape* ShapeHandler::createShape(std::string strLine, E_ShapeID shapeId , bool isToCreateObjDirectly = false)
{

	switch(shapeId)
	{
		case e_Circle:
				std::cout << "ShapeHandler -> CIRCLE()" << std::endl;
				{
					Shape* shapeObj = new Circle();
					strLine>>(*shapeObj);
					//strLine>>(*dynamic_cast<Circle*>shapeObj);



					//shapeObj->dynamic_cast().getInfo();
					bool isValidated = Circle::setParams(strLine);
					if(isValidated && !isToCreateObjDirectly){
						return shapeObj;
					}
					else if(isValidated && isToCreateObjDirectly)
					{
						shapesVector.push_back(shapeObj);
					}
					else
					{
                        delete shapeObj;
						shapeObj = NULL;
						return shapeObj;
					}
				}
			break;
		case e_Rectangle:
				std::cout << "ShapeHandler -> RECTANGLE()" << std::endl;
				{
					Shape* shapeObj = new Rectangle();
					bool isValidated = Rectangle::setParams(strLine);
					if(isValidated){
						return shapeObj;
					}
					else if(isValidated && isToCreateObjDirectly)
					{
						shapesVector.push_back(shapeObj);
					}
					else
					{
						delete shapeObj;
						shapeObj = NULL;
                     	return shapeObj;
					}
				}
				break;
		case e_Square:
				std::cout << "ShapeHandler -> SQUARE()" << std::endl;
				{
					Shape* shapeObj = new Square();
					bool isValidated = Square::setParams(strLine);
					if(isValidated){
						return shapeObj;
					}
					else if(isValidated && isToCreateObjDirectly)
					{
						shapesVector.push_back(shapeObj);
					}
					else
					{
						delete shapeObj;
						shapeObj = NULL;
                     	return shapeObj;
					}
				}
				break;
		case e_Triangle:
			   std::cout << "ShapeHandler -> TRIANGLE()" << std::endl;
				{
					Shape* shapeObj = new Triangle();
					bool isValidated = Triangle::setParams(strLine);
					if(isValidated){
						return shapeObj;
					}
					else if(isValidated && isToCreateObjDirectly)
					{
						shapesVector.push_back(shapeObj);
					}
					else
					{
						delete shapeObj;
						shapeObj = NULL;
						return shapeObj;
					}
				}
				break;
	}
	return NULL;
}*/

int ShapeHandler::deleteShapeObj(E_ShapeID shapeId, std::string shapeNameIn, double param1, double param2 = 0)
{
	std::cout <<"IN ShapeHandler::editShapeObj(...." << std::endl;
	std::string stringShapeType;
   	switch(shapeId)
	{
		case e_Circle:	std::cout <<"Circle is going to be deleted....." << std::endl;
				{
					/*for(std::vector<Shape*>::iterator it = shapesVector.begin(); it != shapesVector.end(); ++it )
					{
						if((*it)->getVerification("circle", shapeNameIn, param1, param2))
						{
							std::cout << "Erasing this entry " << std::endl;
							shapesVector.erase (it);
							break;
						}
					}*/

					for(std::vector<Shape*>::size_type i = 0; i< shapesVector.size() ; i++)
					{
						//if(shapesVector[i]->getVerification("circle", shapeNameIn, param1, param2))
						//{
							std::cout << "Erasing this entry " << std::endl;
							shapesVector.erase (shapesVector.begin()+i);
							break;
					   //	}
					}
					std::cout << "The vector sizeof this = " << shapesVector.size() << std::endl;
				}
			break;
		case e_Rectangle:  std::cout <<"Rectangle is going to be deleted....." << std::endl;
				{
					for(unsigned int i = 0; i< shapesVector.size() ; i++)
					{
						//if(shapesVector[i]->getVerification("rectangle", shapeNameIn, param1, param2))
						//{
							//shapesVector.erase (shapesVector.begin()+i);
							break;
						//}
					}
					std::cout << "The vector sizeof this = " << shapesVector.size() << std::endl;
				}
			break;
		case e_Square:  std::cout <<"Square is going to be deleted....." << std::endl;
				{
					//for(int i = 0; i< shapesVector.size() ; i++)
					//{
					//	if(shapesVector[i]->getVerification("square", shapeNameIn, param1))
					//	{
					//		shapesVector.erase (shapesVector.begin()+i);
					//		break;
					//	}
					//}
					std::cout << "The vector sizeof this = " << shapesVector.size() << std::endl;
				}
			break;
		case e_Triangle:  std::cout <<"Triangle is going to be deleted....." << std::endl;
				{
					//for(int i = 0; i< shapesVector.size() ; i++)
					//{
					//	if(shapesVector[i]->getVerification("triangle", shapeNameIn, param1, param2))
					//	{
					//		shapesVector.erase (shapesVector.begin()+i);
					//		break;
					//	}
					//}
					//std::cout << "The vector sizeof this = " << shapesVector.size() << std::endl;
				}
			break;
	}
	return 0;
}

void ShapeHandler::printObjectDetails()
{
	std::cout << "The vector sizeof this = " << shapesVector.size() << std::endl;
	std::vector<Shape*> sortingVector;
	sortingVector =  shapesVector;
	Shape *tempPtr;
	for(unsigned int count = 0; count < shapesVector.size() ;count++)
	{
		for(  std::vector<Shape*>::iterator it = sortingVector.begin(); it!=sortingVector.end();++it  )
		{
			//std::cout << (*it)->getArea() << std::endl;
			if(it != sortingVector.begin())
			{
				//std::cout << "________________________________________________________________" << std::endl;
				//std::cout << "first = "<< (*it)->getArea() << " second = " << (*(it-1))->getArea() << std::endl;
				if(  ( (*it)->getArea() ) < ( (*(it-1))->getArea() )   )
					{
						tempPtr = *it;
						*it = *(it-1);
						*(it-1) = tempPtr;
					}

				//std::cout << "first = "<< (*it)->getArea() << " second = " << (*(it-1))->getArea() << std::endl;
				//std::cout << "________________________________________________________________" << std::endl;
			}
		}
	}
	std::cout << "^^^^^^^^^^^^^^^^ AT END ^^^^^^^^^^^^^^^^^^^^^^^^^" << std::endl;
    for(  std::vector<Shape*>::iterator it = sortingVector.begin(); it!=sortingVector.end();++it  )
		{
        (*it)->getInfo();
		std::cout << "Area in Ascending order = "<< (*it)->getArea() << std::endl;
		}

}

void ShapeHandler::saveLatestInfo(){
	std::cout << "-- inside file writting --\n";
	std::ofstream configOut;
	std::string allRefreshedConfigs;
	configOut.open ("data.txt", std::ofstream::out);

     for(unsigned int i = 0; i< shapesVector.size(); i++)
	{
	   std::string tempSingleCOnfig = shapesVector[i]->getInfo();
	   allRefreshedConfigs.append(tempSingleCOnfig);
	}
	std::cout << "--------------- Here goes the latest config -------------------\n";
	std::cout << allRefreshedConfigs << std::endl;
	std::cout << "---------------------------------------------------------------\n";
	configOut << allRefreshedConfigs;
	configOut.close();
}


