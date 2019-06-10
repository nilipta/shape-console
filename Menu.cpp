#include "Menu.h"

void Menu::start(){
	while(true)
	{
    	if(startOp()){break;};
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
				   //shapeHandler.createShape(e_Circle);
				break;
			case 2:
				std::cout << "A rectangle is going to draw.." << std::endl;
					//shapeHandler.createShape(e_Rectangle);
				break;
			case 3:
				std::cout << "A Square is going to draw.." << std::endl;
					//shapeHandler.createShape(e_Square);
				break;
			case 4:
				std::cout << "A Square is going to draw.." << std::endl;
					//shapeHandler.createShape(e_Square);
				break;
			case 5:
				std::cout << "Showing all Shapes and proporties" << std::endl;
				shapeHandler.printObjectDetails();
				break;
			case 6:
				std::cout << "You choose to delete .... \nPress <1> to delete a circle\nPress <2> to delete a Rectangle\nPress <3> to delete a Square\nPress <4> to delete a Triangle\nPress <Other> throw SKIP----\n" << std::endl;
				{
					int resp = shapeHandler.editShapeObj();
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
