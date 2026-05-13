#include <iostream>
#include <vector>

using namespace std;
struct X{
	X(int) {};
};
struct Y : X{
	X m{0};
	Y(int a) : X{a}, m{a} {};
	Y() : X{0} {};
};
int main(){
	X* p1 = nullptr;
	X* p{nullptr};
	X a1[] = {1,2,3};
	X a[] {1,2,3};
	vector<X> v1 = {1,2,3,4};
	vector<X> v {1,2,3,4};
	return 0;
}
