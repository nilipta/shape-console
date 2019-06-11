#include "ShapeHandler.h"

ShapeHandler::ShapeHandler()
{
	{std::cout << "Constructing ShapeHandler Object " << std::endl;}
	configContent.erase();
	this->readFile();
}

void ShapeHandler::readFile()
{
	std::cout << "File reading Initializing.....(Loading).........."<<std::endl;
	std::string tempFileString;
	std::ifstream config("data.txt", std::ifstream::in);
	if(config)
	{
		while (std::getline(config, tempFileString))
		{
			std::cout << "=========================== NewLine ========================" << std::endl;

			if(tempFileString.find("circle") < tempFileString.find(" "))
			{
				//std::cout<<"Circle configuration = " << std::endl;
				Shape* shapePtr = createShape(tempFileString, e_Circle, false);
				if(shapePtr != nullptr){
					shapesVector.push_back(shapePtr);
				}
			}

			else if(tempFileString.find("rectangle") < tempFileString.find(" "))
			{
				//std::cout<<"Rectangle configuration = " << std::endl;
				Shape* shapePtr = createShape(tempFileString, e_Rectangle, false);
				if(shapePtr != nullptr){
					shapesVector.push_back(shapePtr);
				}
			}

			else if(tempFileString.find("square") < tempFileString.find(" "))
			{
				//std::cout<<"square configuration = " << std::endl;
				Shape* shapePtr = createShape(tempFileString, e_Square, false);
				if(shapePtr != nullptr){
					shapesVector.push_back(shapePtr);
				}
			}

			else if(tempFileString.find("triangle") < tempFileString.find(" "))
			{
				//std::cout<<"square configuration = " << std::endl;
				Shape* shapePtr = createShape(tempFileString, e_Triangle, false);
				if(shapePtr != nullptr){
					shapesVector.push_back(shapePtr);
				}
			}

            std::cout << "===========================   END   ======================== \n" << std::endl;

			///store in vector and continue reading the next line
			//shapesVector.push_back(shapePtr);
		}
		config.close();
	 }
}

Shape* ShapeHandler::createShape(std::string strLine, E_ShapeID shapeId , bool isToCreateObjDirectly = false)
{
	switch(shapeId)
	{
		case e_Circle:
				std::cout << "ShapeHandler -> CIRCLE()" << std::endl;
				{
					Shape* shapeObj = new Circle(strLine);
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
						shapeObj = nullptr;
						return shapeObj;
					}
				}
			break;
		case e_Rectangle:
				std::cout << "ShapeHandler -> RECTANGLE()" << std::endl;
				{
					Shape* shapeObj = new Rectangle(strLine);
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
						shapeObj = nullptr;
                     	return shapeObj;
					}
				}
				break;
		case e_Square:
				std::cout << "ShapeHandler -> SQUARE()" << std::endl;
				{
					Shape* shapeObj = new Square(strLine);
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
						shapeObj = nullptr;
                     	return shapeObj;
					}
				}
				break;
		case e_Triangle:
               std::cout << "ShapeHandler -> TRIANGLE()" << std::endl;
				{
					Shape* shapeObj = new Triangle(strLine);
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
						shapeObj = nullptr;
                     	return shapeObj;
					}
				}
				break;
	}
}

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

					for(int i = 0; i< shapesVector.size() ; i++)
					{
						if(shapesVector[i]->getVerification("circle", shapeNameIn, param1, param2))
						{
							std::cout << "Erasing this entry " << std::endl;
							shapesVector.erase (shapesVector.begin()+i);
							break;
						}
					}
					std::cout << "The vector sizeof this = " << shapesVector.size() << std::endl;
				}
			break;
		case e_Rectangle:  std::cout <<"Rectangle is going to be deleted....." << std::endl;
				{
					for(int i = 0; i< shapesVector.size() ; i++)
					{
						if(shapesVector[i]->getVerification("rectangle", shapeNameIn, param1, param2))
						{
							shapesVector.erase (shapesVector.begin()+i);
							break;
						}
					}
					std::cout << "The vector sizeof this = " << shapesVector.size() << std::endl;
				}
			break;
		case e_Square:  std::cout <<"Square is going to be deleted....." << std::endl;
				{
					for(int i = 0; i< shapesVector.size() ; i++)
					{
						if(shapesVector[i]->getVerification("square", shapeNameIn, param1))
						{
							shapesVector.erase (shapesVector.begin()+i);
							break;
						}
					}
					std::cout << "The vector sizeof this = " << shapesVector.size() << std::endl;
				}
			break;
		case e_Triangle:  std::cout <<"Triangle is going to be deleted....." << std::endl;
				{
                	for(int i = 0; i< shapesVector.size() ; i++)
					{
						if(shapesVector[i]->getVerification("triangle", shapeNameIn, param1, param2))
						{
							shapesVector.erase (shapesVector.begin()+i);
							break;
						}
					}
					std::cout << "The vector sizeof this = " << shapesVector.size() << std::endl;
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
	for(int count = 0; count < shapesVector.size() ;count++)
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

     for(int i = 0; i< shapesVector.size(); i++)
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


