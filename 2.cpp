#include <iostream>
#include <complex>
using namespace std;

int main(){
	complex<double> z = {1,2};
	auto [re, im] = z+2;
	cout << re << im << endl;
	return 0;
}
