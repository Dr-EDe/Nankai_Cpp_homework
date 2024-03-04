#include <iostream>
#include<string.h>
#include<vector>
using namespace std;

class Hugelnt {
private:
    vector<int> num;
    int n;//Î»Êý
public:
    Hugelnt(int x) {
        n = 0;
        while (x > 0) {
            num.push_back(x % 10);
            n++;
            x = x / 10;
        }
    }
    Hugelnt(char* p) {
        int x = strlen(p);
        for (int i = x-1; i >=0; i--) {
            num.push_back(int(p[i] - 48));
            n++;
        }
    }
    Hugelnt& operator+(Hugelnt& a) {
        if (n >= a.n) {
            for (int i = 0; i < a.n-1; i++) {
                if (num[i] + a.num[i] >= 10) {
                    num[i + 1]++;          
                }
                num[i] = (num[i] + a.num[i]) % 10;
            }
            if (a.num[a.n - 1] + num[a.n - 1] > 10) {
                num[a.n]++;

            }
            for (int i = a.n-1; i < n-1; i++) {
               
            }
        }
    }
    friend ostream& operator<<(ostream& out, Hugelnt& x) {
        for (int i = x.n - 1; i >= 0; i--) {
            out << x.num[i];
        }
        return out;
    }
};
int  main()
{
    int  x1, x2;
    char  s1[40], s2[40], s3[40], s4[40];

    cin >> x1 >> x2;
    cin >> s1 >> s2 >> s3 >> s4;

    HugeInt  n1(x1);
    HugeInt  n2(x2);
    HugeInt  n3(s1);
    HugeInt  n4(s2);
    HugeInt  n5(s3);
    HugeInt  n6(s4);
    HugeInt  result;

    cout << "n1  is  " << n1 << "\nn2  is  " << n2
        << "\nn3  is  " << n3 << "\nn4  is  " << n4
        << "\nn5  is  " << n5 << "\nn6  is  " << n6
        << "\nresult  is  " << result << "\n\n";

    //  test  relational  and  equality  operators
    if (n1 == n2)
        cout << "n1  equals  n2" << endl;

    if (n1 != n2)
        cout << "n1  is  not  equal  to  n2" << endl;

    if (n1 < n2)
        cout << "n1  is  less  than  n2" << endl;

    if (n1 <= n2)
        cout << "n1  is  less  than  or  equal  to  n2" << endl;

    if (n1 > n2)
        cout << "n1  is  greater  than  n2" << endl;

    if (n1 >= n2)
        cout << "n1  is  greater  than  or  equal  to  n2" << endl;

    result = n1 + n2;
    cout << n1 << "  +  " << n2 << "  =  " << result << "\n\n";

    cout << n3 << "  +  " << n4 << "\n=  " << (n3 + n4) << "\n\n";

    result = n1 + 9;
    cout << n1 << "  +  " << 9 << "  =  " << result << endl;

    result = n2 + "10000";
    cout << n2 << "  +  " << "10000" << "  =  " << result << endl;

    result = n5 * n6;
    cout << n5 << "  *  " << n6 << "  =  " << result << endl;

    result = n5 - n6;
    cout << n5 << "  -  " << n6 << "  =  " << result << endl;

    result = n5 / n6;
    cout << n5 << "  /  " << n6 << "  =  " << result << endl;
    return  0;
}