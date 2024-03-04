#include<iostream>
using namespace std;


int main() {
	int a = 20;
	int b = 40;
	int c = 0;
	c = a > b ? a : b;
	cout << "c=" << c << endl;
	(a > b ? a : b) = 90;
	cout << "b=" << b << endl;
	system("pause");

	return 0;

}