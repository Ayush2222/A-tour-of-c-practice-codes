#include <iostream>
using namespace std;
class BB{
	public: const int c;
		BB(int c) : c{c} {}
};
class Animal: public BB{
	public:
	const int a;
	Animal(int a) : a{a}, BB(a+a){}
	Animal(int a, int b) : a{a+b+a}, BB(a+b+a){}
};
class Dog : public Animal{
	public:
		const long b;
		Dog(int a) : BB(a+a+a+a+a+a), Animal(a, a+1), b{a} {}
};
int main(){
	Animal a{4};
	cout << a.a;
	Dog d{5};
	cout << d.b << endl;
	cout << d.a << endl;

	return 0;
}
