#include<iostream>
using namespace std;


int main() {
	int arr[3][4],i,j,max;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 4; j++) {
			cin >> arr[i][j];
		}
	}
	for (i = 0; i < 3; i++) {
		max = arr[i][0];
		for (j = 0; j< 4; j++) {
			if (max >= arr[i][j]) { max = max; }
			else { max = arr[i][j]; }
		}cout << max << ' ';
	}



	system("pause");

	return 0;

}