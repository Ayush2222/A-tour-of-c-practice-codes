#include <iostream>
using namespace std;

class a{
	public:int m[10000];
};
class b{
	public: a A;int c[10000];
};

int main(){
	b M;
	b* B = &M;
	for(int i =0;i<10000;i++){
		if((B->c)[i] == 0) continue;
	cout << ((B->A).m)[i] << endl;
	cout << (B->c)[i] << endl;
	}
	return 0;
}
