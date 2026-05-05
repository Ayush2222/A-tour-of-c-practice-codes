#include <iostream>

using namespace std;

class complex{
	double re, im;
	public:
		complex(double r, double i): re{r}, im{i} {}
		complex(double r): re{r}, im{0} {}
		complex(): re{0}, im{0} {}
		complex(const complex& z): re{z.re}, im{z.im} {}
		
		double real() const {return re;}
		void real(double d) {re=d;}
		double imag() const {return im;}
		void imag(double d) {im=d;}

		complex& operator+=(complex z)
		{
			re+=z.re;
			im+=z.im;
			return *this;
		}
		
		complex& operator-=(complex z)
		{
			re-=z.re;
			im-=z.im;
			return *this;
		}

		//complex operator+(complex a, complex b)
		//{
		//	return a+=b;
		//}
		complex& operator*=(complex);
		complex& operator/=(complex);
};
complex& complex::operator*=(complex a){
	complex& x = *this;
	double temp = x.real() * a.real() - x.imag()*a.imag();
	x.im = x.real() * a.imag() + a.real()*x.imag();
	x.re = temp;
	return x;
}
complex& complex::operator/=(complex a){
	complex& m = (*this);
	double c = a.real()*a.real()+a.imag()*a.imag();
	complex t {a.real()/c, -a.imag()/c};
	m *= t;
	return m;
}
complex operator+(complex a,const complex b){
	return a+=b;
}
complex operator-(complex a, complex b){
	return a-=b;
}
complex operator-(complex a){
	return {-a.real(), -a.imag()};
}
complex operator*(complex a, complex b){
	return a*=b;
}
complex operator*(complex a){
	return a;
}
complex operator/(complex a, complex b){
	return a/=b;
}
bool operator==(complex a, complex b){ return a.real()==b.real() && a.imag() == b.imag(); }
bool operator!=(complex a, complex b){ return a.real()!=b.real() || a.imag() != b.imag(); }
void p(complex a){
	cout << "{ " << a.real() << " , " << a.imag() << " }\n";
	       	
}
int main(){
	complex c{1,2};
	complex* c2 = new complex();
	c2->real(5);
	c2->imag(6);
	cout << (c**c2).real() << endl;
	const complex c3{1,5};
	c = *c2;
	complex c4{1/c};
	p(c4);
	complex c5 {*c2+c4*complex{1, 2.3}};
	p(c5);
	if(c5!=c4)
		c5 = -(c/(*c2)) + 2*c4;
	p(c5);
	complex c6 = 2*c;
	p(c6);
	p(c6*c6*1);
	complex c7{*********c2};
	p(c7);
	return 0;
}
