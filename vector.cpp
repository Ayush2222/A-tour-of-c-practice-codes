module;
#include <iostream>
export module Vector;
export class Vector{
	public:
		Vector() : elem{nullptr}, sz{0} {}
		Vector(int s);
		Vector(std::initializer_list<double>);
		~Vector(){ delete[] elem;std::cout << "\ndeleted\n";}
		double& operator[](int i);
		double operator[](int i) const;
		int size() const;
		void push_back(double);
	private:
		double* elem;
		int sz;
};
Vector::Vector(int s)
	:elem{new double[s]}, sz{s}
{	
}

double& Vector::operator[](int i){
	return elem[i];
}
double Vector::operator[](int i) const{
	return elem[i];
}

int Vector::size() const {
	return sz;
}
Vector::Vector(std::initializer_list<double> lst):elem{new double[lst.size()]}, sz{static_cast<int>(lst.size())}{
	std::copy(lst.begin(), lst.end(), elem);
}
export Vector read(std::istream& is)
{
	//usage: Vector v = read(cin);
	Vector v;
	for(double d; is>>d;){}
		//v.push_back(d); to be implemented
	return v;
}
export bool operator==(const Vector& v1, const Vector& v2){
	if(v1.size()!=v2.size())
		return false;
	for(int i =0;i<v1.size();i++)
		if(v1[i]!=v2[i])
			return false;
	return true;
}
