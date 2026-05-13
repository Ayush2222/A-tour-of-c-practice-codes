#include <iostream>
using namespace std;
class A{
	public:
		void destroy(){this->~A();}
	private:
		~A(){};


};
int main(){
	A* a = new A();
	
	return 0;
}
