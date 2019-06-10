#include "Menu.h"

void Menu::start(){
	while(true)
	{
    	if(startOp()){break;}
	}
}

bool Menu::startOp(){
	std::cout << "******************  WELCOME TO *****************\n" << std::endl;

	ShapeHandler shapeHandler;
	int choiceEnter;
	do {
		std::cout << "****************** APPLICATION *****************\n\
	  A) Press <1> to draw a circle\n\
	  B) Press <2> to draw a rectangle\n\
	  C) Press <3> to draw a Square\n\
	  D) Press <4> to draw a Triangle\n\
	  E) Press <5> to view all diagrams\n\
	  F) Press <6> to delete a Shape\n\
	  G) Press <7> to Commit changes to file system\n\
	  H) Press <another number> to Quit from system = " << std::endl;
      	while(std::cin.fail()){std::cin.clear(); std::cin.ignore(100, '\n');}
		std::cin >> choiceEnter;
		switch(choiceEnter){
			case 1:
				std::cout << "A circle is going to draw.." << std::endl;
					{
						std::string circleNameIn;
						double radIn, centerIn;
						circleDialog(circleNameIn, radIn, centerIn);
						shapeHandler.addShape(e_Circle, circleNameIn, radIn, centerIn);
					}
				break;
			case 2:
				std::cout << "A rectangle is going to draw.." << std::endl;
					{
                    	std::string rectNameIn;
						double length, breadth;
						rectangleDialog(rectNameIn, length, breadth);
						shapeHandler.addShape(e_Rectangle, rectNameIn, length, breadth);
					}
				break;
			case 3:
				std::cout << "A Square is going to draw.." << std::endl;
					{
                    	std::string squareNameIn;
						double length;
						SquareDialog(squareNameIn, length);
						shapeHandler.addShape(e_Square, squareNameIn, length);
					}
				break;
			case 4:
				std::cout << "A Triangle is going to draw.." << std::endl;
					{
                    	std::string triangleNameIn;
						double base, height;
						TrianleDialog(triangleNameIn, base, height);
						shapeHandler.addShape(e_Triangle, triangleNameIn, base, height);
					}
				break;
			case 5:
				std::cout << "Showing all Shapes and proporties" << std::endl;
				shapeHandler.printObjectDetails();
				break;
			case 6:
				std::cout << "You choose to delete .... \nPress <1> to delete a circle\nPress <2> to delete a Rectangle\nPress <3> to delete a Square\nPress <4> to delete a Triangle\nPress <Other> throw SKIP----\n" << std::endl;
				{
					//int resp = shapeHandler.editShapeObj();
					int editChoice;
					std::cin >> editChoice;
					switch(editChoice)
					{
						case 1:	std::cout << "A circle is going to delete.." << std::endl;
								{
									std::string circleNameIn;
									double radIn, centerIn;
									circleDialog(circleNameIn, radIn, centerIn);
									shapeHandler.editShapeObj(e_Circle, circleNameIn, radIn, centerIn);
								}
							break;

						case 2:	std::cout << "A rectangle is going to delete.." << std::endl;
								{
									std::string rectNameIn;
									double length, breadth;
									rectangleDialog(rectNameIn, length, breadth);
									shapeHandler.editShapeObj(e_Rectangle, rectNameIn, length, breadth);
								}
							break;

						case 3:	std::cout << "A Square is going to delete.." << std::endl;
								{
									std::string squareNameIn;
									double length;
									SquareDialog(squareNameIn, length);
									shapeHandler.editShapeObj(e_Square, squareNameIn, length);
								}
							break;

						case 4: std::cout << "A Triangle is going to delete.." << std::endl;
								{
									std::string triangleNameIn;
									double base, height;
									TrianleDialog(triangleNameIn, base, height);
									shapeHandler.editShapeObj(e_Triangle, triangleNameIn, base, height);
								}
							break;
						default:	std::cout << "AInvalid options.." << std::endl;
					}
				}
				break;
			case 7:
				std::cout << "You choose to Commit all changes\n" << std::endl;
				{
					shapeHandler.saveLatestInfo();
				}
				break;
			default:
				std::cout << "Your entry meant quitting..Bye Bye" << std::endl;
				{
                	return 1;
				}
		}

	} while(choiceEnter > 0 && choiceEnter <=7);
}

void Menu::circleDialog(std::string &circleNameIn, double &param1, double &param2){
	std::cout <<"Enter name of the circle <!Without space + minimum 2 character> = " << std::endl;
	std::cin >> circleNameIn;

	std::cout <<"Enter Radius of the circle = " << std::endl;
	std::cin >> param1;
	while(std::cin.fail()){std::cin.clear(); std::cin.ignore(100, '\n'); param1 = 0;}

	std::cout <<"Enter Center of the circle = " << std::endl;
	std::cin >> param2;
	while(std::cin.fail()){std::cin.clear(); std::cin.ignore(100, '\n'); param2 = 0;}
}

void Menu::rectangleDialog(std::string &rectNameIn, double &param1, double &param2){
	std::cout <<"Enter name of the rectangle <!Without space + minimum 2 character> = " << std::endl;
	std::cin >> rectNameIn;

	std::cout <<"Enter length of the rectangle = " << std::endl;
	std::cin >> param1;
	while(std::cin.fail()){std::cin.clear(); std::cin.ignore(100, '\n'); param1 = 0;}

	std::cout <<"Enter bredth of the rectangle = " << std::endl;
	std::cin >> param2;
	while(std::cin.fail()){std::cin.clear(); std::cin.ignore(100, '\n'); param2 = 0;}
}

void Menu::SquareDialog(std::string &squareNameIn, double &param1){
	std::cout <<"Enter name of the Square <!Without space + minimum 2 character> = " << std::endl;
	std::cin >> squareNameIn;

	std::cout <<"Enter length of the Square = " << std::endl;
	std::cin >> param1;
	while(std::cin.fail()){std::cin.clear(); std::cin.ignore(100, '\n'); param1 = 0;}
}

void Menu::TrianleDialog(std::string &triNameIn, double &param1, double &param2){
	std::cout <<"Enter name of the Trianle <!Without space + minimum 2 character> = " << std::endl;
	std::cin >> triNameIn;

	std::cout <<"Enter base of the Trianle = " << std::endl;
	std::cin >> param1;
	while(std::cin.fail()){std::cin.clear(); std::cin.ignore(100, '\n'); param1 = 0;}

	std::cout <<"Enter height of the Trianle = " << std::endl;
	std::cin >> param2;
	while(std::cin.fail()){std::cin.clear(); std::cin.ignore(100, '\n'); param2 = 0;}
}
