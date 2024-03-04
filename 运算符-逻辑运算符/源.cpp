#include<iostream>
using namespace std;


int main() {
	//逻辑运算符-非！
	int a = 10;
	cout << !a << endl;
	//在C++中，除了0都是真
	cout << !!a << endl;
	//逻辑运算符-与&&
	int c = 10;
	int d = 10;
	cout << (c && d) << endl;
	c = 10;
	d = 0;
	cout << (c && d) << endl;
	//逻辑运算符-或||
	a = 10;
	c = 10;
	cout << (a || c) << endl;
	c = 10;
	d = 0;
	cout << (c || d) << endl;














	system("pause");

	return 0;

}