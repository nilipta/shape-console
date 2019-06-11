#ifndef SHAPES_H
#define SHAPES_H

class Shape{
	public:
		Shape(){};
		Shape(const std::string shapeName){};

		void setName(){std::cout<<"Base class set name called"<<std::endl;}
		std::string getname(){return objectName;}
		virtual std::string getInfo() = 0;
		virtual double getArea() = 0;
		virtual bool getVerification(std::string type, std::string nameParam, double param1, double param2){};
		virtual bool getVerification(std::string type, std::string nameParam, double param1){};
	protected:
	private:
		std::string objectName;
};

#endif
