#include<iostream>
using namespace std;


int main() {
	int m, n;
	cin >> m >> n;
	char* a = new char[m];
	char* b = new char[n];
	cin >> a >> b; int c; int x=0;
	if (n == 1) {
		for (int i = 0; i < m; i++) {
			if (a[i] == b[0]) { cout << i + 1; break; }
		}
	}
	else {
		for(int i=0;i<m)
	}
	


	system("pause");

	return 0;

}