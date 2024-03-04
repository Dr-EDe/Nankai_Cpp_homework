#include<iostream>
#include<string.h>
#include<algorithm>
using  namespace  std;

int n;
class poker {
private:
	struct Poker {
		char pattern[10];
		char figure;
	};
	Poker* card = new Poker[n];

public:
	poker() {
		for (int i = 0; i < n; i++) {
			cin >> card[i].figure;
			cin >> card[i].pattern;
		}
	}


	bool check() {
		int j = 0;
		for (int i = 0; i < n; i++) {
			if (card[i].figure == '%') {
				return true;
				break;
			}
		}
		return false;
	}

	void sort() {
		int* C = new int[n];
		int* N = new int[n];
		for (int i = 0; i < n; i++) {
			if (card[i].figure == 'A') { N[i] = 0; }
			else if (card[i].figure == '1') { N[i] = 1; }
			else if (card[i].figure == '2') { N[i] = 2; }
			else if (card[i].figure == '3') { N[i] = 3; }
			else if (card[i].figure == '4') { N[i] = 4; }
			else if (card[i].figure == '5') { N[i] = 5; }
			else if (card[i].figure == '6') { N[i] = 6; }
			else if (card[i].figure == '7') { N[i] = 7; }
			else if (card[i].figure == '8') { N[i] = 8; }
			else if (card[i].figure == '9') { N[i] = 9; }
			else if (card[i].figure == '0') { N[i] = 10; }
			else if (card[i].figure == 'J') { N[i] = 11; }
			else if (card[i].figure == 'Q') { N[i] = 12; }
			else if (card[i].figure == 'K') { N[i] = 13; }
			else { N[i] = 14; }
		}
		for (int i = 0; i < n; i++) {
			if (strcmp(card[i].pattern ,"Spade")==0) { C[i] = 0; }
			else if (strcmp(card[i].pattern , "Heart")==0) { C[i] = 1; }
			else if (strcmp(card[i].pattern , "Diamond")==0) { C[i] = 2; }
			else if (strcmp(card[i].pattern , "Club")==0) { C[i] = 3; }
			else { C[i] = 4; }
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n - i-1; j++) {
				if (N[j] >=N[j + 1]) {
					if (N[j] == N[j + 1]&&C[j]>C[j+1]) {
						swap(C[j], C[j + 1]);
						swap(N[j], N[j + 1]);
						swap(card[j].figure, card[j + 1].figure);
						swap(card[j].pattern, card[j + 1].pattern);
					}
					else if (N[j] > N[j + 1]) {
						swap(C[j], C[j + 1]);
						swap(N[j], N[j + 1]);
						swap(card[j].figure, card[j + 1].figure);
						swap(card[j].pattern, card[j + 1].pattern);
					}
				}
				
			}
		}
	}
	
	void display() {
		for (int i = 0; i < n; i++) {
			cout << card[i].figure << ' ' << card[i].pattern << endl;
		}
	}
};
int  main() {

	cin >> n;
	poker s = poker();
	if (s.check()) { cout << "yes" << endl; }
	else { cout << "no" << endl; }
	s.sort();
	s.display();
	return 0;
}