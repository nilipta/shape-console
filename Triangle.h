#ifndef TRIANGLE_H
#define TRIANGLE_H

class Triangle{
	public:
	protected:
		virtual double area();
		virtual double perimeter();
	private:
		double base;
		double length;
		double height;
		double radius;
};

#endif
