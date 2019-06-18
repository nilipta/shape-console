#ifndef MY_MENUH
#define MY_MENUH

#include <string>
using namespace std;

class Menu {
	public:
		Menu(){};
		void start();
		bool startOp();
	private:
		void circleDialog(string &circleNameIn, double &radIn, double &centerIn);
		void rectangleDialog(string &circleNameIn, double &param1, double &param2);
		void SquareDialog(string &SquareNameIn, double &param1);
		void TrianleDialog(string &circleNameIn, double &param1, double &param2);
};

#endif


