#include<iostream>
using namespace std;


int main() {
	int m; cin >> m;
	if (m < 1 || m>9) cout << "WRONG";
    else if (m == 1) {
		int a, b; cin >> a >> b;
		cout << a * b; 
	}
	else {
		int** A = new int* [m];
		for (int i = 0; i < m; i++) {
			A[i] = new int[m];
		}
		int** B = new int* [m];
		for (int i = 0; i < m; i++) {
			B[i] = new int[m];
		}
		int** C = new int* [m];
		for (int i = 0; i < m; i++) {
			C[i] = new int[m];
		}
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < m; j++) {
				C[i][j] = 0;
			}
		}
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < m; j++) {
				cin >> A[i][j];
			}
		}
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < m; j++) {
				cin >> B[i][j];
			}
		}
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < m; j++) {
				for (int k = 0; k < m; k++) {
					C[i][j] += A[j+i][k] * B[k][j];
				}
			}
		}
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < m; j++) {
				cout << C[i][j] << ' '; if (j == m - 1) cout << endl;
			}
		}
	}



	system("pause");


}