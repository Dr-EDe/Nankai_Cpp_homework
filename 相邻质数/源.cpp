#include<iostream>
using namespace std;
bool prime(long x);
bool prime(long x) {
	int a = 1;
	for (int i = x - 1; i >= 2; i--) {
		if (x % i == 0) {
			int a = 0;
			return 0;
			break;
		}
	}
	if (a == 1) { return 1; }
}
long abs(long x, long y);
long abs(long x, long y) {
	if (x >= y) { return x - y; }
	else { return y - x; }
}
int main() {
	int N;
	cin >> N;
	long* M = new long[N];
	int* T = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> M[i] >> T[i];
	}
	for (int i = 0; i < N; i++) {
		long m = M[i];
		int t = T[i];
		int arr[100];
		int a = 0;
		if (prime(m)) { arr[a] = m; a++; }
			for (int i = 1;; i++) {
				if (prime(m - i)) { 
					if(m-i>1){ arr[a] = m - i; a++; }
					 }
				if (a == t) { break; }
				if (prime(m + i)) { arr[a] = m + i; a++; }
			}
			for (int i = 0; i < t; i++) {
				for (int j = t - 1; j > i; j--) {
					if (arr[j] < arr[j - 1]) {
						int temp = arr[j];
						arr[j] = arr[j - 1];
						arr[j - 1] = temp;
					}
				}
			}
			for (int i = 0; i < t; i++) {
				cout << arr[i] << ' ' << abs(arr[i], m) << ' ';
				if (i == t - 1) { cout << endl; }
			}
		
	}
	system("pause");

	return 0;
	
}




