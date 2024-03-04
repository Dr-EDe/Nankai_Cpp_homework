#include<iostream>
using namespace std;


int main() {
	int h1, m1, s1, h2, m2, s2, h3,m3,s3;
	cin >> h1 >> m1 >> s1;
	cin>>h2 >> m2 >> s2;
	int a = s1 + m1 * 60 + h1 * 3600;
	int b = s2 + m2 * 60 + h2 * 3600;
	int c = b - a;
	if (c >0) {
		if (c > 12 * 3600) {
			c = 24 * 3600 - c;
			s3 = c % 60;
			m3 = ((c - s3) / 60) % 60;
			h3 = c / 3600;
			cout << h3 << ' ' << m3 << ' ' << s3;
		}
		else {
			s3 = c % 60;
			m3 = ((c - s3) / 60) % 60;
			h3 = c / 3600;
			cout << h3 << ' ' << m3 << ' ' << s3;
		}
	}
	else if (c < 0) {
		c = -c;
		if (c > 12 * 3600) {
				c = 24 * 3600 - c;
				s3 = c % 60;
				m3 = ((c - s3) / 60) % 60;
				h3 = c / 3600;
				cout << h3 << ' ' << m3 << ' ' << s3;
		}
		else {
			s3 = c % 60;
			m3 = ((c - s3) / 60) % 60;
			h3 = c / 3600;
			cout << h3 << ' ' << m3 << ' ' << s3;
		}
	}
	



	system("pause");

	return 0;

}