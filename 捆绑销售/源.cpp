#include<iostream>
using namespace std;
int main() {
	char a[6];
	int n; cin >> n;
	int b[26][26] = { 0 };
	for (int i = 0; i < n; i++) {
		cin >> a;
		for (int j = 0; j < 5; j++) {
			for (int k = j + 1; k < 5; k++) {
				if (a[j] != a[k]) {
					b[a[j] - 'A'][a[k] - 'A']++;
				}
			}
		}
	}
	int max = 0;
	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < 26; j++) {
			if (b[i][j] > max) {
				max = b[i][j];
			}
		}
	}
	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < 26; j++) {
			if (b[i][j] == max) {
				cout << char(i + 'A') << char(j + 'A'); return 0;
			}
		}
	}
}