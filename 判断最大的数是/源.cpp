#include<iostream>
using namespace std;


int main() {
	int a = 0;
	int b = 0;
	int c = 0;
	cin >> a;
	cin >> b;
	cin >> c;
	if (a > b) {
		if (a > c) { cout << "a最大" << endl; }
		else { cout << "c最大" << endl; }
	
	}
	else {
		if (b > c)
		{
			cout << "b最大" << endl;
	}
		else { cout << "c最大" << endl; }
	
	
	}








	system("pause");

	return 0;

}