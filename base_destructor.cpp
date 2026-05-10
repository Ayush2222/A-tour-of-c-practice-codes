#include <iostream>
using namespace std;
class Base{
	public:
	virtual ~Base() = 0;
};
Base::~Base(){
	cout << "Base destructor called\n"; 

}
class Der : public Base{
	public:
		~Der(){
			cout << "Destructor of Der\n";
		}
};
int main(){
	Der *b = new Der();
	delete b;
	return 0;
}
