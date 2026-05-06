#include <list>
#include <iostream>
import Vector;
using namespace std;
class Container{
public:
	virtual double& operator[](int) = 0;
	virtual int size() const = 0;
	virtual ~Container() {}
};

class Vector_container : public Container {
public:
	Vector_container(int s) : v(s) {}
	~Vector_container() {}
	double& operator[](int i) override {return v[i];}
	int size() const override {return v.size();}
private:
	Vector v;
};

class List_container : public Container{
public:
	List_container(){}
	List_container(initializer_list<double> il): ld{il} {}
	~List_container(){}

	double& operator[](int i) override;
	int size() const override {return ld.size();}
private:
	std::list<double> ld;
};


double& List_container::operator[](int i){
	for(auto& x: ld){
		if(i==0)
			return x;
		--i;
	}
	throw out_of_range{"List container"};
}
void use(Container& c){
	const int sz = c.size();
	for(int i =0;i!=sz; ++i)
		cout << c[i] << '\n'; 
}
void g(){
	Vector_container vc(10);
	use(vc);
}
void h(){
	List_container lc = {1,2,3,4,5,6,7,8,9};
	use(lc);
}

int main(){
//	Container c;
	Container* p = new Vector_container(10);
	h();
	g();	
	return 0;
}
