#ifndef SHAPESH
#define SHAPESH

#include <string>
#include <fstream>
#include <iostream>

class Shape{
	public:
		Shape(){};
		Shape(std::string shapeNameArg){ shapeObjName = shapeNameArg ;}
		virtual void writeToFile(std::ofstream& obj) = 0;
		virtual double getArea()=0;
		virtual bool getVerification(std::string, double, double) = 0;
		std::string	getName(){ return shapeObjName; }

		friend ifstream& operator>>( ifstream& obj,Shape& shape);
		friend std::string operator>>(std::string str, Shape& shape);
		friend ostream& operator<< (ostream& ob, Shape& shape);

	protected:
		std::string  shapeObjName;

	private:
		virtual ifstream& parseShapeAttributes(ifstream& obj)=0;
		virtual void printAttributes(ostream& ob){};

	public:
		class SortingClass{
			public:
				SortingClass(bool flagArg = false) { flagSortingType =  flagArg;}
				bool operator() (Shape* shape1, Shape* shape2);
			private:
				bool flagSortingType;
		} SortingClassObject;
};
#endif

