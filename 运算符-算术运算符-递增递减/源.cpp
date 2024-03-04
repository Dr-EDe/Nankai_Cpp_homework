#include<iostream>
using namespace std;


int main() {
	//前置递增
	int a = 10;
	++a;//让变量加1
	cout << "a=" << a << endl;

	//后置递增
	int a1 = 10;
	a1++;
	cout << "a1=" << a1 << endl;

	//前置递增和后置递增的区别
	//前置递增 先让变量+1 在进行表达式运算
	int a2 = 10;
	int b2 = ++a2 * 48;
	cout << "a2=" << a2 << endl;
	cout << "b2=" << b2 << endl;
	//后置递增 先进行表达式运算 后让变量加1
	int a3 = 32;
	int b3 = a3++ * 47;
	cout << "a3=" << a3 << endl;
	cout << "b3=" << b3 << endl;

	system("pause");

	return 0;

}