#include<iostream>
using namespace std;


int main() {
	float a = 0; float r = 0; float c = 0; float d = 0;
	cin >> a;
	if (a < 100) {
		c = a * r / 100; d = a - c;
		cout << "" << r << " " << c << " " << d << endl;
	}
	else if (a>=100&&a<200) { 
		r = 2;
		c = a * r / 100; d = a - c;
		cout << "" << r << " " << c << " " << d << endl;
	}
	else if (a>=200&&a<400) {
		r = 4;
		c = a * r / 100; d = a - c;
		cout << "" << r << " " << c << " " << d << endl;
	}
	else if (a>=400&&a<800) {
		r = 8;
		c = a * r / 100; d = a - c;
		cout << "" << r << " " << c << " " << d << endl;
	}
	else {
		r = 10;
		c = a * r / 100; d = a - c;
		cout << "" << r << " " << c << " " << d << endl;
	}










	system("pause");

	return 0;

}