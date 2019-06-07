#include "Menu.h"

void Menu::start(){
	std::cout << "Welcome to figure drawing dashboard " << std::endl;

	int choiceEnter;
	do {
		std::cout << "\
	  A) Press <1> to draw a circle\n\
	  B) Press <2> to draw a rectangle\n\
	  C) Press <3> to draw a Square\n\
	  D) Press <4> to draw a Triangle\n\
	  E) Press <5> to view all diagrams\n\
	  F) Press <6> to exit the dashboard\n\
	  " << std::endl;

		std::cin >> choiceEnter;
		switch(choiceEnter){
			case 1:
				std::cout << "A circle is going to draw.." << std::endl;
			   //	shapeHandler.createShape(0);
				break;
			case 2:
				std::cout << "A rectangle is going to draw.." << std::endl;
			   //	shapeHandler.createShape(1);
				break;
			case 3:
				std::cout << "A Square is going to draw.." << std::endl;
				//shapeHandler.createShape(2);
				break;
			case 4:
				std::cout << "A Triangle is going to draw.." << std::endl;
			   //	shapeHandler.createShape(3);
				break;
			case 5:
				std::cout << "Showing all Shapes and proporties" << std::endl;
				shapeHandler.printObjectDetails();
				break;
			case 6:
				std::cout << "Saving and exiting the dashboard" << std::endl;
				//shapeHandler.createShape(5);
				break;
			default:
				std::cout << "X-X-X-X Your option did not match X-X-X-X" << std::endl;
		}

	} while(choiceEnter > 0 && choiceEnter <=6);

}