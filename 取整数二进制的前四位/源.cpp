#include<iostream>
using namespace std;

#include<iostream>
using namespace std;
int main()
{
	int r, n, p, m;   //rΪ�ظ�������nΪ���������m��¼nתΪ�����������λ��
	cin >> r;
	do
	{
		int s = 0, t = 0;     //s��ת����Ķ���������t����
		r -= 1;      //ÿ�ظ�һ�Σ�r��1
		cin >> n;
		if (n < 16)
			cout << "0000";      //nС��16ʱ��5-8λ��Ϊ��
		else
		{
			n %= 256;
			n /= 16;            //Ԥ����ȡ��Ч���嵽��λ
			for (int i = 1; n > 0; i++)
			{
				t = n % 2;
				n /= 2;
				for (int k = i; k > 1; k--)
				{
					t *= 10;
				}
				s += t;                 //תΪ������������i��ѭ��ʱ��tΪ10^i�η������Խ���Ӧ���ӵ�iλ��
				m = i;      //����λ��m
			}
			for (int i = 4 - m; i > 0; i--)      //��λ��m����4λ������ǰ��4-mλ
			{
				cout << "0";
			}
			cout << s << endl;
		}
	} while (r > 0);

}