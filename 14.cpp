#include <iostream>
using namespace std;
class A{
	public :
		A(const A& a, const A b, A c){}
};
int main(){
	A a{a, a, a};
	return 0;
}
