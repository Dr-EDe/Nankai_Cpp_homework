#include<iostream>
using namespace std;

#include<iostream>
using namespace std;
int main()
{
	int r, n, p, m;   //r为重复次数，n为输入的数，m记录n转为二进制数后的位数
	cin >> r;
	do
	{
		int s = 0, t = 0;     //s是转化后的二进制数，t是幂
		r -= 1;      //每重复一次，r减1
		cin >> n;
		if (n < 16)
			cout << "0000";      //n小于16时，5-8位均为零
		else
		{
			n %= 256;
			n /= 16;            //预处理，取有效的五到八位
			for (int i = 1; n > 0; i++)
			{
				t = n % 2;
				n /= 2;
				for (int k = i; k > 1; k--)
				{
					t *= 10;
				}
				s += t;                 //转为二进制数。第i次循环时，t为10^i次方，可以将对应数加到i位上
				m = i;      //导出位数m
			}
			for (int i = 4 - m; i > 0; i--)      //若位数m不够4位，则在前补4-m位
			{
				cout << "0";
			}
			cout << s << endl;
		}
	} while (r > 0);

}