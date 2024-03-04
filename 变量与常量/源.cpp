#include<iostream>
using namespace std;

//常量的定义方法
//1.#define 宏常量
//2.const修饰变量

//1.#define宏常量
#define Day 7

int main() {
	cout << "how many days do aweek has" << Day << "day" << endl;
	//day是常量一旦修改就会报错

	//const修饰的变量
	int month = 12;
	cout << "how many months do a year has" << month << "months" << endl;




	system("pause");

	return 0;



}
