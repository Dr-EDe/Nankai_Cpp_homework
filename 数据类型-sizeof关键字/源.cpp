#include<iostream>
using namespace std;


int main() {
	//���Σ�short 2    int   4     long  4    longlong    8
	//��������sizeof�����������ռ���ڴ��С
	//�﷨��sizeof����������/������
	short a = 10;
	int b= 10;	cout << "shortռ�ÿռ���" << sizeof(a) << endl;
	cout << "shortռ�ÿռ���" << sizeof(int) << endl;
	long c= 1232;
	cout << "longռ�ÿռ���" << sizeof(long) << endl;
	long long d = 1231;
	cout << "long longռ�ÿռ���" << sizeof(long long) << endl;
	//���δ�С�Ƚ�
	//short<int<=long<longlong
	system("pause");

	return 0;

}