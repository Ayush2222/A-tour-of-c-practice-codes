#include <iostream>
#include <array>
#include <memory>
using namespace std;
template<class T>
class Matrix{
	array<int, 2> dim;
	T* elem;
public:
	Matrix(int d1, int d2) : dim{d1, d2}, elem { new T[d1*d2]} {}
	int size() const {return dim[0]*dim[1];}
	
	Matrix(const Matrix&); //copy constructor
	Matrix& operator=(const Matrix&); // copy assignment
	
	Matrix(Matrix&&);  //move constructor
	Matrix& operator=(Matrix&&); //move assignment

	~Matrix(){ delete[] elem;}
};
template<class T>
Matrix<T>:: Matrix(const Matrix& m) : dim{m.dim}, elem{new T[m.size()]}{
	uninitialized_copy(m.elem, m.elem+m.size(), elem);
}


int main(){
	Matrix<int>* m = new Matrix<int>{4,6};
	Matrix<int>n{*m};
	delete m;
	return 0;
}
