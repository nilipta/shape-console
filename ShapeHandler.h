#ifndef ShapeHandlerH
#define ShapeHandlerH


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
		//void createShape(std::string);
		int deleteShapeObj(E_ShapeID shapeId, std::string, double , double);
		void printObjectDetails();
		void saveLatestInfo();
	private:
      std::vector<Shape*> shapesVector;
	  void readFile();
	  std::string configContent;
	  int shapeNos;

};

#endif
