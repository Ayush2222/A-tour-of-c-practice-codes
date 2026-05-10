#include <iostream>
using namespace std;
class Base{
public:
	void regular_function(){
		cout << " BASE REGULAR " << endl;
	}
	void regular_function(int arg1){
		cout << " BASE REGULAR WITH ARG1 : " << arg1 << endl;
	}
	virtual void virtual_function(){
		cout << " BASE VIRTUAL " << endl;
	}
};
class Derived : public Base{
public:
//	using Base::regular_function;
	void regular_function(){
		cout << " DERIVED REGULAR " << endl;
	}
	void virtual_function() override {
		cout << " DERIVED VIRTUAL/REAL " << endl;
	}
};
int main(){
	Base* obj = new Derived();

	obj->regular_function();
	obj->regular_function(5);
	obj->virtual_function();
	
	Derived* dobj = new Derived();
	dobj->regular_function();
//	dobj->regular_function(5);
	dobj->virtual_function();

//	Derived* bobj = new Base();
//	bobj->regular_function();
//	bobj->regular_function(5);
//	bobj->virtual_function();

	Base* objb=  new Base();
	objb->regular_function();
	objb->regular_function(5);
	objb->virtual_function();

	return 0;
}
