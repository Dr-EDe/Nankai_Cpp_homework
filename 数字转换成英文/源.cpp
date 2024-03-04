#include<iostream>
using namespace std;


int main() {
	int n;
	cin >> n;
	int arr[6] = { 0 };
	int m = 0;
	for (int i = 0;; i++) {
		arr[i] = n % 10;
		n = n / 10;
		m++;
		if (n == 0) { break; }
	}
	for (int i = m-1;i>=0; i--) {
		if (arr[i] == 0) { cout << "zero"; }
		else if (arr[i] == 1) { cout << "one"; }
		else if (arr[i] == 2) { cout << "two"; }
		else if (arr[i] == 3) { cout << "three"; }
		else if (arr[i] == 4) { cout << "four"; }
		else if (arr[i] == 5) { cout << "five"; }
		else if (arr[i] == 6) { cout << "six"; }
		else if (arr[i] == 7) { cout << "seven"; }
		else if (arr[i] == 8) { cout << "eight"; }
		else { cout << "nine"; }
		cout << ' ';
	}

	system("pause");

	return 0;

}