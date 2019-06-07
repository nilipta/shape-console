#ifndef SQUARE_H
#define SQUARE_H

class Square:public Shape{
	public:
		Square(std::string strLine);
		void area();
		void perimeter();
		static bool setParams(std::string str,Shape& sqr);
		void getInfo();
	private:
		double length;
		std::string shapeName;
};

#endif