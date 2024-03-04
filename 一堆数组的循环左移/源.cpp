#include<iostream>
using namespace std;


int main() {
	int  arr[] = { 1,2,3,4,5 },n;
	cin >> n;
	n = n % 5;
	if (n == 0)cout << "1 2 3 4 5";
	else if (n == 1)cout << "2 3 4 5 1";
	else if (n == 2)cout << "3 4 5 1 2";
	else if (n == 3)cout << "4 5 1 2 3";
	else if (n == 4)cout << "5 1 2 3 4" ;


	system("pause");

	return 0;

}