#include<iostream>
using namespace std;
void swap(int&a, int&b) {
	int temp = a;
	a = b;
	b = temp;
}
void sort(int a[]) {
	int m = sizeof(a);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m - 1 - i; j++) {
			if (a[j] > a[j + 1]) swap(a[j], a[j + 1]);
		}
	}
}


int main() {
	int m, n;
	cin >> m >> n;
	int* cake = new int[n];
	int* people = new int[m];
	for (int i = 0; i < m; i++) {
		cin >> people[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> cake[i];
	}
	sort(cake); sort(people);
	int count = 0;
	int i = 0;
	for (int j = 0; j < m; j++) {
		if (cake[i] >= people[j]) count++; i++;
		if (i == n) break;
	}
	
	cout << count + 1;
	



	system("pause");

	return 0;

}