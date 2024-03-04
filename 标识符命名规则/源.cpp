#include<iostream>
using namespace std;
//标识符命名规则
//1.标识符不能是关键字
//2.标识符由字母，数字，下划线组成
//3.标识符第一个字符只能是字母或下划线
//4.标识符是区分大小写的
int main() {

	//1.标识符不能是关键字
	//int int= 10;

	//标识符由字母，数字，下划线组成
	int abc = 10;
	int _abc = 10;
	int _abc123 = 30;
	//给变量取名的时候最好做到见名知意
	int number1 = 9382;
	int number2 = 32988;
	int sum = number1 + number2;
	cout << sum << endl;

	system("pause");

	return 0;

}