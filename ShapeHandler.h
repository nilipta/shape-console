#ifndef SHAPEHANDLER_H
#define SHAPEHANDLER_H

#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include "Circle.h"
#include "Circle.cpp"
#include "Rectangle.h"
#include "Rectangle.cpp"
#include "Square.h"
#include "Square.cpp"
#include "Triangle.h"
#include "Triangle.cpp"


enum E_ShapeID
{
  e_Circle = 0,
  e_Rectangle,
  e_Square,
  e_Triangle
};

class ShapeHandler{
	public:
		ShapeHandler();
		~ShapeHandler(){std::cout << "Destructing ShapeHandler Object " << std::endl;}
		Shape* createShape(std::string strLine, E_ShapeID shapeId);
		void addShape(E_ShapeID shapeId, std::string, double , double);
		int editShapeObj(E_ShapeID shapeId, std::string, double , double);
		void printObjectDetails();
		void saveLatestInfo();
	private:
      std::vector<Shape*> shapesVector;
	  void readFile();
	  std::string configContent;
	  int shapeNos;

};


class printingAllDetails{
	public:
	void operator() (Shape* ob){
		ob->getInfo();
		ob->getArea();
	}
} printDetail;


#endif
