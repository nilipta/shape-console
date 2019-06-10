#ifndef SQUARE_H
#define SQUARE_H

class Square:public Shape{
	public:
		Square(std::string strLine);
		void area();
		void perimeter();
		static bool setParams(std::string str,Shape& sqr);
		void getInfo();
        void getArea();
        bool getVerification(std::string nameParam, double param1, double param2);
	private:
		double length;
		std::string shapeName;
};

#endif
