#include<iostream>
using namespace std;


int main() {
	//�߼������-�ǣ�
	int a = 10;
	cout << !a << endl;
	//��C++�У�����0������
	cout << !!a << endl;
	//�߼������-��&&
	int c = 10;
	int d = 10;
	cout << (c && d) << endl;
	c = 10;
	d = 0;
	cout << (c && d) << endl;
	//�߼������-��||
	a = 10;
	c = 10;
	cout << (a || c) << endl;
	c = 10;
	d = 0;
	cout << (c || d) << endl;














	system("pause");

	return 0;

}