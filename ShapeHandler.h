#ifndef ShapeHandlerH
#define ShapeHandlerH

#include <iostream>
#include <vector>
class Shape;


enum E_ShapeID
{
  e_Circle = 0,
  e_Rectangle,
  e_Square,
  e_Triangle,
  eInvalid
};

class ShapeHandler{
	public:
		ShapeHandler();
		~ShapeHandler(){}
		void createShape(E_ShapeID, std::string, double, double);
		int deleteShapeObj(E_ShapeID shapeId, std::string, double , double);
		void printObjectDetails();
		void saveLatestInfo();
		void printObjectDetailsAscending();
		void printObjectDetailsDescending();
	private:
		std::vector<Shape*> shapesVector;
		void readFile();
		std::string configContent;
		int shapeNos;
};

/*class myclass {
	public:
		bool operator() (Shape* objFirstIndex, Shape* objSecondIndex)
		{

			std::cout<<"Inside operator overload"<<((objSecondIndex))->getArea(); //<<std::endl<< objSecondIndex;
			//std::cout << "Area in vector 0 index = "<< objFirstIndex->getArea();
		   //	if(	   (*objFirstIndex).getArea() < (*objSecondIndex).getArea()		)
		   //	return((*objFirstIndex).getArea() < (*objSecondIndex).getArea());
		}
} areaSortAscending;
*/

/*class myclassForEach {
	public:
		bool operator() (Shape* objFirstIndex)
		{
			std::cout<<"Inside Foreach "<<((objFirstIndex))->getArea();
		}
} displayAll;*/

#endif

