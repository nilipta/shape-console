#ifndef SHAPEHANDLER_H
#define SHAPEHANDLER_H

#include <fstream>
#include <sstream>
#include <vector>
#include "Circle.h"
#include "Circle.cpp"
#include "Rectangle.h"
#include "Rectangle.cpp"
#include "Square.h"
#include "Square.cpp"


enum E_ShapeID
{
  e_Circle = 0,
  e_Rectangle,
  e_Square
};

class ShapeHandler{
	public:
        ShapeHandler();
		Shape* createShape(std::string strLine, E_ShapeID shapeid);
		void printObjectDetails();
	private:
      std::vector<Shape*> shapesVector;
	  void readFile();
	  std::string configContent;
	  bool checkValidConfig();
	  int shapeNos;
	  void addConfigTemplate();
	  void writeFile(std::string& str);
};

/*
class printingAllDetails{
	void operator() (Shape* ob){
		ob->getInfo();
	}
} printDetail;
*/

#endif