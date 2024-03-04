#include<iostream>
using namespace std;
#include<algorithm>

int main() {
	int n; cin >> n;
	int* arr = new int[n];
	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i]; sum += arr[i];
	}
	int l, r; cin >> l >> r;
	if (float(sum / n) < l || float(sum / n) > r){ cout << "-1"; return 0; }
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) swap(arr[j], arr[j + 1]);
		}
	}
	int left, right; if (arr[n - 1] <= r && arr[0] >= l){ cout << '0'; return 0; }
	for (int i = 0; i < n; i++) {
		if (arr[i] <= l && arr[i + 1] >= l) { left = i; break; }
	}
	for (int i = n - 1; i >= 0; i--) {
		if (arr[i] >= r && arr[i - 1] <= r) { right = i; break; }
	}
	int s = 0; int x = 0;
	for (int i = right; i < n; i++) {
		s += arr[i] - r;
	}
	for (int i = left; i >= 0; i--) {
		x += l - arr[i];
	}
	cout << max(s, x);

	system("pause");

	

}