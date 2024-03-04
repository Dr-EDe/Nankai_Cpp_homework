#include<iostream>
using namespace std;


int main() {
	int N; cin >> N;
	if (N % 2 != 0 || N > 10000) { cout << "ERROR"; }
	else {
		int b = 0;
		int c = 0;
		int d = 0;
		for (int i = N; i > 1; i--) {
			int a = 1;
			for (int j = i - 1; j > 1; j--) {
				if (i % j == 0) { a = 0; break; }
			}
			if (a == 1) { b++; }
		}

		int* arr = new int[b];
		for (int i = N; i > 1; i--) {
			int a = 1;
			for (int j = i - 1; j > 1; j--) {
				if (i % j == 0) { a = 0; break; }
			}
			if (a == 1) {
				arr[c] = i; c++;
			}
		}
		for (int i = 0; i < b - 1; i++) {
			for (int j = i + 1; j < b; j++) {
				if (arr[i] + arr[j] == N) { d++; }
			}
		}
		cout << d;
		system("pause");

		return 0;

	}
}