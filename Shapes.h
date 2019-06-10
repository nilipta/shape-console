#ifndef SHAPES_H
#define SHAPES_H

class Shape{
	public:
		Shape(){};
		Shape(const std::string shapeName){};

		void setName(){std::cout<<"Base class set name called"<<std::endl;}
		std::string getname(){return objectName;}
		virtual void getInfo() = 0;
		virtual void getArea() = 0;
		virtual bool getVerification(std::string nameParam, double param1, double param2) = 0;
	protected:
	private:
		std::string objectName;
		//struct Dimensions{double lenS, double HeightS, double radS};

};

#endif
