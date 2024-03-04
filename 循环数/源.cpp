#include<iostream>
#include<cmath>
using namespace std;


int main() {
	int N;
	cin >> N;
	int* arr = new int[2*N];
	for (int i = 0; i <2* N; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < 2 * N; i = i + 2) {
		int A = arr[i];
		int B = arr[i + 1];
		int n = 0;
		for (int a = A; a <= B; a++) {
			int c = 0;
			for (int b = a; b != 0; c++) {
				b = b / 10;
			}//得到该数的位数
			int* str = new int[c];
			for (int d = 0; d < c; d++) {
				str[c - 1 - d] = A % 10;
				A = A / 10;
			}//得到该数的每位数字
			for (int g = 1; g < c; g++) {
				int f = A / pow(10, g);
				int k = 0;
				for (int h = c - g - 1; h < c; h++) {
					k += str[h] * pow(10, h);
				}
				int goal = f + k;
				if (goal>a&&goal<=B) {
					n++;

				}
			}
			cout << n << endl;
		}
	}

	system("pause");

	return 0;

}