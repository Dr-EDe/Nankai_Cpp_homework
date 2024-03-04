#include<iostream>
using namespace std;
//字符型变量只能用于单个字符
//语法:char  me ='a';



int main() {

	char love = 'i';
	cout << love<< endl;
	cout << "字符型变量所占内存为" << sizeof(char) << endl;
	//注意字符型变量只能用单引号且单引号内只有一个字符
	//字符型变量对应ASCII编码
	cout << (int)love << endl;
	//ASCII编码是指将一些字符换成10进制数存在电脑中
	//A-65
	//a-97以此类推


	system("pause");

	return 0;

}