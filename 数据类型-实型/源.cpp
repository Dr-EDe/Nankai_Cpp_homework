#include<iostream>
using namespace std;


int main() {
	//������ float ռ���ֽ�4   7λ��Ч���ַ�Χ
	//˫���� double ռ���ֽ�8   15~16λ��Ч���ַ�Χ
	//Ĭ����������һ��С������ʾ��6λ��Ч����
	float f1 = 39.23f;
	double f2 = 3.13;
	cout << "f1=" << f1 << endl;
	cout << "f2=" << f2 << endl;
	cout << "floatռ���ֽ�Ϊ" << sizeof(float) << endl;
	cout << "doubleռ���ֽ�Ϊ" << sizeof(double) << endl;
	//��ѧ��������
	float a = 2e2;
	cout << "a=" << a << endl;






	system("pause");

	return 0;

}