#include<iostream>
using namespace std;


int main() {
	//.短整型short(-32768~32767)
	short a = 32768.2;
	//整形int
	int b = 10;/*(-2147483648~2147483647)*/
	//长整型long
	long c = 10;
	//长长整形longlong
	long long d= 10;

	//整形的区别在于占用的空间不同,整形用于整数类型的
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	cout << "c=" << c<< endl;
	cout << "d=" << d << endl;

		



	system("pause");

	return 0;

}