#include<iostream>
using namespace std;


int main() {
	int m = 100,n,a,b,c;
	for (m; m <= 999; m++) {
n = 0; a = m % 10; b = (m / 10) % 10; c = m / 100;
if (m == a * a * a + b * b * b + c * c * c)cout << m << endl;;
	}
		
	



	system("pause");

	return 0;

}