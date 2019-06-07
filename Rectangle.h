#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle:public Shape{
	public:
		Rectangle(std::string strLine);
		void area();
		void perimeter();
		static bool setParams(std::string str,Shape& rect);
		void getInfo();
	private:
		double length;
		double height;
		std::string shapeName;
};

#endif
