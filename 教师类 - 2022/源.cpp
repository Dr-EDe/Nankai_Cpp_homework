#include  <iostream>
#include  <string.h>
using  namespace  std;

class  Teacher
{
public:
    virtual  int  Salary() = 0;
    virtual  void  Print(int) = 0;
};
class Professor :public Teacher {
    int hour;
    char* name;
public:
    int Salary() {
        return 5000 + hour * 50;
    }
    void Print(int money) {
        cout << "Title: Pro. Name: " << name << ' ' << "Salary: " << money << endl;
    }
    Professor(char* N, int h) {
        name = N;
        hour = h;
    }
};
class AssociateProfessor :public Teacher {
    int hour;
    char* name;
public:
    int Salary() {
        return 3000 + hour * 30;
    }
    void Print(int money) {
        cout << "Title: A.P. Name: " << name << ' ' << "Salary: " << money << endl;
    }
    AssociateProfessor(char* N, int h) {
        hour = h;
        name = N;
    }
};





int  main()
{
    Teacher* t;
    int  money = 0;
    char  pro_name[128];
    char  ap_name[128];
    int  pro_lessons, ap_lessons;
    cin >> pro_name >> pro_lessons >> ap_name >> ap_lessons;

    Professor  p(pro_name, pro_lessons);
    t = &p;
    money = t->Salary();
    t->Print(money);

    AssociateProfessor  aprof(ap_name, ap_lessons);
    //  ¾²Ì¬Áª±à
    money = aprof.Salary();
    aprof.Print(money);
    //  ¶¯Ì¬Áª±à
    t = &aprof;
    money = t->Salary();
    t->Print(money);

    t = NULL;
    system("pause");
    return  0;
}