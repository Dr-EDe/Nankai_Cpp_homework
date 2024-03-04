#include<iostream>
#include<cmath>
#include<string.h>
using namespace std;
int a(char number[]);
 int main(){
	 int n; cin >> n;
	char*number=new char[n];
	cin >> number;
	cout<<a(number);
}
 int a(char number[]) {
	 int n = strlen(number);
	 int m = 0;
	 for (int i = 0; i < n; i++) {
		 if (number[i] == 'A') { number[i] = 10; }
		 else if (number[i] == 'B') { number[i] = 11; }
		 else if (number[i] == 'C') { number[i] = 12; }
		 else if (number[i] == 'D') { number[i] = 13; }
		 else if (number[i] == 'E') { number[i] = 14; }
		 else if (number[i] == 'F') { number[i] = 15; }
		 else if (number[i] == '1') { number[i] = 1; }
		 else if (number[i] == '2') { number[i] = 2; }
		 else if (number[i] == '3') { number[i] = 3; }
		 else if (number[i] == '4') { number[i] = 4; }
		 else if (number[i] == '5') { number[i] = 5; }
		 else if (number[i] == '6') { number[i] = 6; }
		 else if (number[i] == '7') { number[i] = 7; }
		 else if (number[i] == '8') { number[i] = 8; }
		 else if (number[i] == '9') { number[i] = 9; }
		 else if (number[i] == '0') { number[i] = 0; }
		 m = m+number[i] * pow(16, n - 1 - i);
		 
	 }
	 return m;

 }