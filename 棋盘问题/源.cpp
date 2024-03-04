#include<iostream>
using namespace std;


int main() {
	int arr[5][5];
	for (int i = 0; i <= 4; i++) {
		for (int j = 0; j <= 4; j++) {
			cin >> arr[i][j];
		}
	}
	int m = 0;
	for (int i = 0; i <= 4; i++) {
		for (int j = 0; j <= 4; j++) {
			if (arr[2][2] == 1) {
				if (arr[0][0] == 1 && arr[1][1] == 1 && arr[3][3] == 1 && arr[4][4] == 1) {
					m = 1;
					break;
				}
				if (arr[0][4] == 1 && arr[1][3] == 1 && arr[3][1] == 1 && arr[4][0] == 1) {
					m = 1;
					break;
				}
			}
			 if (arr[i][j] == 1) {
				if (arr[i][0] == 1 && arr[i][1] == 1 && arr[i][2] == 1 && arr[i][3] == 1 && arr[i][4] == 1) {
					m = 1;
					break;
				}
				if (arr[0][j] == 1 && arr[1][j] == 1 && arr[2][j] == 1 && arr[3][j] == 1 && arr[4][j] == 1) {
					m = 1;
					break;
				}
			}
		}
	}
	if (m == 1) {
		cout << "yes";
	}
	else { cout << "no"; }
	system("pause");

	return 0;

}