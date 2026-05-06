class Robot{
	public:
	int x = 0, y=0;
	public:
		Robot& moveup(){
			//delete this;
			this->y++;
			return (*this);
		}
		Robot& moveright(){
			this->x++;
			return (*this);
		}
};
#include <iostream>
using namespace std;

int main(){
	Robot* r = new Robot();
	(*r).moveup().moveright().moveup();
	cout << (*r).x << " " << (*r).y << endl; 	
	return 0;
}
