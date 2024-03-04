#include<iostream>
using  namespace  std;

bool  isprime(int  x);

bool isprime(int x) {
    if (x > 2) {
        int m = 0;
        for (int i = 2; i < x; i++) {
            if (x % i == 0) { m = 0; break; }
            m = 1;
        }
        if (m == 0)return 0;
        else return 1;
    }
    if (x == 2)return 1;
    if (x == 1)return 0;
}
    




int  main() {
    int  x;
        cin >> x;
        cout << isprime(x);
        return  0;
}