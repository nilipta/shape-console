#ifndef TRIANGLE_H
#define TRIANGLE_H

class Triangle:public Shape{
	public:
		Triangle(std::string strLine);
		static bool setParams(std::string str);
		std::string getInfo();
		double getArea();
		bool getVerification(std::string type, std::string nameParam, double param1, double param2);
	private:
		double base;
		double height;
		std::string shapeName;
		std::string shapeType;
};

#endif
