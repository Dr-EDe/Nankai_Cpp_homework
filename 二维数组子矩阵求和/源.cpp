#include<iostream>
using namespace std;


int main() {
	int m, n; cin >> m >> n;
	int** arr = new int*[m];
	for (int i = 0; i < m; i++) {
		arr[i] = new int[n];
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	int q; cin >> q;
	int a, b, c, d, sum = 0, max = 0;
	for (int i = 0; i < q; i++) {
		cin >> a >> b >> c >> d;
		for (int i = a - 1; i < c; i++) {
			for (int j = b - 1; j < d; j++) {
				sum += arr[i][j];
			}
		}
		for (int i = 0;i<m; i++) {
			for (int j = 0;j<n; j++) {
				if (i >= a - 1 && i <= c - 1 && j >= b - 1 && j <= d - 1) { continue; }
				if (arr[i][j] > max) { max = arr[i][j]; }
			}
		}
		cout << sum << max;
	}



	system("pause");

	return 0;

}