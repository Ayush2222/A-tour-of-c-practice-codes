#include <iostream>

using namespace std;

class Shape{
	public:
		virtual void calculate(){
			cout << "Area of your shape\n";
		}
		virtual ~Shape(){
			cout << "Shape destructor called\n"; 
		}
};
class Rect : public Shape{
	public:
		int width, height, area;
		void calculate() override {
			width = 5;
			height= 10;
			area = height * width;
			cout << "Area of rectangle : " << area << endl;
		}
		~Rect(){
			cout << "Rect destructor called\n";
		}
};

int main(){
	/*Shape* S;
	Rect r;
	S = &r;
	S->calculate();
	Rect r2;
	S = &r2;
	S->calculate();*/
	Rect r3;
	return 0;
}
