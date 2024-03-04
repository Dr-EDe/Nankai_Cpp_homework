#include<iostream>
using namespace std;


int main() {
	//整形：short 2    int   4     long  4    longlong    8
	//可以利用sizeof求出数据类型占用内存大小
	//语法：sizeof（数据类型/变量）
	short a = 10;
	int b= 10;	cout << "short占用空间是" << sizeof(a) << endl;
	cout << "short占用空间是" << sizeof(int) << endl;
	long c= 1232;
	cout << "long占用空间是" << sizeof(long) << endl;
	long long d = 1231;
	cout << "long long占用空间是" << sizeof(long long) << endl;
	//整形大小比较
	//short<int<=long<longlong
	system("pause");

	return 0;

}