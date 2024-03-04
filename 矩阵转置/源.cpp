#include<iostream>
using namespace std;


int main() {
	int arr[3][3], i, j, b;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			cin >> arr[i][j];
		}
	}
	for (i = 0; i < 3; i++) {
		for (j = 0; j <= i; j++) {
			b = arr[i][j];
			arr[i][j] = arr[j][i];
			arr[j][i] = b;
		}
	}
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			cout << arr[i][j] << ' ';
			if (j ==2) { cout << endl; }
		}
	}

	
	



	system("pause");

	return 0;

}