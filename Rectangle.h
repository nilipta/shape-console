#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle:public Shape{
	public:
		Rectangle(std::string strLine);
		void area();
		void perimeter();
		static bool setParams(std::string str,Shape& rect);
		std::string getInfo();
		void getArea();
		bool getVerification(std::string type, std::string nameParam, double param1, double param2);
	private:
		double length;
		double height;
		std::string shapeName;
		std::string shapeType;
};

#endif
