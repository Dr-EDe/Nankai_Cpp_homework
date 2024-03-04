#include<iostream>
using namespace std;


int main() {
	int a,b,c=0;
	cin >> a;
	for (b = 1; b <= a - 1; b++)
		if (a % b == 0)c = c + b;
	if (c == a)cout << "perfect" << endl;
	else cout << "not perfect" << endl;

	system("pause");

	return 0;

}