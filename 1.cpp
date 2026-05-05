#include <iostream>
using namespace std;

struct Entry{
	string name;
	int value;
};
struct Entry read_entry(istream& is){
	string s;
	int i;
	is >> s >> i;
	return {s,i};
}
int main(){
	auto [n, v] = read_entry(cin);
	cout << "{" << n << "," << v << "}\n";
	return 0;
}
