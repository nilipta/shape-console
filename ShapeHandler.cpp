#include "ShapeHandler.h"

ShapeHandler::ShapeHandler()
{
	configContent.erase();
	this->readFile();
}

Shape* ShapeHandler::createShape(std::string strLine, E_ShapeID shapeid)
{
	switch(shapeid)
	{
		case e_Circle:
				std::cout << "ShapeHandler -> CIRCLE()" << std::endl;
				{
					Shape* shapeObj = new Circle(strLine);
					//shapeObj->dynamic_cast().getInfo();
					bool isValidated = Circle::setParams(strLine, *shapeObj);
					if(isValidated){
						return shapeObj;
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
					bool isValidated = Rectangle::setParams(strLine, *shapeObj);
					if(isValidated){
						return shapeObj;
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
					bool isValidated = Square::setParams(strLine, *shapeObj);
					if(isValidated){
						return shapeObj;
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
			//file open is success so now read each line till eof
			//std::getline(config, tempFileString);
			std::cout << tempFileString << std::endl;

			//read line

			///line read is success now parse the line to check the shape type
			///shape type is found now create shape and call its set paramas
			//Shape* shapePtr = createShape(E_ShapeID);

			if(tempFileString.find("circle") < tempFileString.max_size())
			{
				std::cout<<"Circle configuration = " << std::endl;
				Shape* shapePtr = createShape(tempFileString, e_Circle);
				if(shapePtr != nullptr){
					shapesVector.push_back(shapePtr);
				}
			}

			else if(tempFileString.find("rectangle") < tempFileString.max_size())
			{
				std::cout<<"Rectangle configuration = " << std::endl;
				Shape* shapePtr = createShape(tempFileString, e_Rectangle);
				if(shapePtr != nullptr){
					shapesVector.push_back(shapePtr);
				}
			}

			else if(tempFileString.find("square") < tempFileString.max_size())
			{
				std::cout<<"square configuration = " << std::endl;
				Shape* shapePtr = createShape(tempFileString, e_Square);
				if(shapePtr != nullptr){
					shapesVector.push_back(shapePtr);
				}
			}

            std::cout << "===========================   END   ======================== \n" << std::endl;

			///store in vector and continue reading the next line
			//shapesVector.push_back(shapePtr);
		}
		 // get file size using buffer's members
		 //close file buffer
		 config.close();
	 }
}

bool ShapeHandler::checkValidConfig()
{
	if(configContent.size() > 0)
	{
		std::cout << "Buffer size : " << configContent.size() <<"\n";
		if(configContent.find("<config_begin>") >= 0)
		{
			std::cout << "Configuration exists : _/_/_/\n";
		}
		else{
			std::cout << "Buffer is empty \n" ;
			this->addConfigTemplate();
		}
	 return true;
	}
	else{
		return false;
	}
}

void ShapeHandler::addConfigTemplate()
{
std::string freshConfig = "circle 2.0 3.5 mycircle\n\
circle 3.0 5.2\n\
circle 1.5 9.2 Circle1\n\
reactangle 2.0 3.2 rectangle\n\
square 2.0 newSquare";

	this->writeFile(freshConfig);
}

void ShapeHandler::writeFile(std::string& str){
	std::cout << "-- str --\n" << str <<"-- str --\n";
	std::ofstream configOut;
	configOut.open ("data.txt", std::ofstream::out);
	configOut << str;
	configOut.close();
}

void ShapeHandler::printObjectDetails()
{
	//for_each(shapesVector.beign(), shapesVector.end(), printDetail);
	//for(int i = 0; i< shapesVector.size(); i++)
	//{
	//   shapesVector[i].getInfo();
	//}

	std::cout << "The vector sizeof this = " << shapesVector.size() << std::endl;
	shapesVector[0]->getname();
}

