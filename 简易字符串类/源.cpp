#include<iostream>
#include<cstring>
using  namespace  std;

class  stringUser
{
public:
    stringUser(const  char* str = NULL);
    stringUser(const  stringUser& other);
    ~stringUser(void);
private:
    char* m_String;
};

int  main() {
    char  str_input[10];
    cin.getline(str_input, 10);
    stringUser  a(str_input);
    stringUser  b(a);
    cout << "test\n";
    return  0;
}
stringUser::stringUser(const stringUser& other) {
    m_String = new char[strlen(other.m_String) + 1];
    for (int i = 0; i < strlen(other.m_String)+1; i++) {
        m_String[i] = other.m_String[i];
   }
}
stringUser::stringUser(const  char* str) {
    m_String = new char[strlen(str) + 1];
    for (int i = 0; i < strlen(str)+1; i++) {
        m_String[i]= str[i];
    }
}
stringUser:: ~stringUser(void) {
    cout << m_String<< endl;
}