#include<iostream>
using namespace std;


int main() {
	//ǰ�õ���
	int a = 10;
	++a;//�ñ�����1
	cout << "a=" << a << endl;

	//���õ���
	int a1 = 10;
	a1++;
	cout << "a1=" << a1 << endl;

	//ǰ�õ����ͺ��õ���������
	//ǰ�õ��� ���ñ���+1 �ڽ��б��ʽ����
	int a2 = 10;
	int b2 = ++a2 * 48;
	cout << "a2=" << a2 << endl;
	cout << "b2=" << b2 << endl;
	//���õ��� �Ƚ��б��ʽ���� ���ñ�����1
	int a3 = 32;
	int b3 = a3++ * 47;
	cout << "a3=" << a3 << endl;
	cout << "b3=" << b3 << endl;

	system("pause");

	return 0;

}