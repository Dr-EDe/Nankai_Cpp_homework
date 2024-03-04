#include<iostream>
using namespace std;


int main() {
	//单精度 float 占用字节4   7位有效数字范围
	//双精度 double 占用字节8   15~16位有效数字范围
	//默认情况下输出一个小数会显示出6位有效数字
	float f1 = 39.23f;
	double f2 = 3.13;
	cout << "f1=" << f1 << endl;
	cout << "f2=" << f2 << endl;
	cout << "float占用字节为" << sizeof(float) << endl;
	cout << "double占用字节为" << sizeof(double) << endl;
	//科学计数法：
	float a = 2e2;
	cout << "a=" << a << endl;






	system("pause");

	return 0;

}