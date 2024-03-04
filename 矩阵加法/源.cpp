#include<iostream>
using namespace std;


int main() {
	int a, b, c, d;
	cin >> a; cin >> b;
	int arr[100][100];
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			cin >> arr[i][j];
		}
	}
	cin >> c; cin >> d;
	int str[100][100];
	for (int i = 0; i <c; i++) {
		for (int j = 0; j < d; j++) {
			cin >> str[i][j];
		}
	}
	int goal[100][100];
	if (c >= a) { a=c; }
	if (d >= b) { b = d; }
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			goal[i][j] = arr[i][j] + str[i][j];
		}
	}
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			cout << goal[i][j] << ' ';
			if (j == b - 1) {
				cout << endl;
			}
		}
	}


	system("pause");

	return 0;

}