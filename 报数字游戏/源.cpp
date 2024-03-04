//#include<iostream>
//using namespace std;
//int main() {
//	int count = 1; int n, m, i = 0;
//	cin >> n >> m;
//	int* arr = new int[n];
//	for (int i = 0; i < n; i++) {
//		arr[i] = i + 1;
//	}
//	while (1) {
//		if (count == m) {
//			count = 1;
//			cout << arr[i] << ' ';
//			for (int j = i + 1; j < n; j++) {
//				arr[j - 1] = arr[j];
//			}
//			n--;
//			if (n == 0)break;
//		}
//		else {
//			count++;
//			i = (i + 1) % n;
//		}
//	}
//}
//#include <iostream>
//using namespace std;
//int f(int n, int m) {
//	if (n == 1)
//		return 0;
//	return(f(n - 1, m) + m) % n;
//}
//int main() {
//	cout << f(10, 2) + 1;
//}
#include <iostream>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

}