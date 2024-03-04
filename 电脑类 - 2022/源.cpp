#include<iostream>
#include<string>
#include<vector>
using  namespace  std;
class  HardWare
{
public:
    void  virtual print() = 0;
};
class  CPU :public  HardWare
{
public:
    char* changshang;
    float w;
    void print() {
        cout << changshang << " CPU " << "Work with " << w << "GHz" << endl;
    }
};
class  MainBoard :public  HardWare
{
public:
    char* name;
    char* xinghao;
    void print() {
        cout << name << " MainBoard Work with " << xinghao << endl;
    }
};
class  HardDisk :public  HardWare
{
public:
    char* name;
    int data;
    void print() {
        cout << name << "HardDisk Work with " << data << 'G' << endl;
    }
};
class  PC
{
private:
    vector<HardWare>pc;
public:
    void AddToPC(HardWare x) {
        pc.push_back(x);
    }
    void Work() {
        for (int i = 0; i < pc.size(); i++) {
            pc[i].print();
        }
    }
};
class  Builder
{
public:
    MainBoard MB;
    CPU cpu;
    HardDisk HD;
};
class  DellBuilder :public  Builder
{
public:
    DellBuilder() {
        cin >> cpu.changshang >> cpu.w;
        cin >> HD.name >> HD.data;
        cin >> MB.name >> MB.xinghao;
    }
};
class  IBMBuilder :public  Builder
{
public:
    IBMBuilder() {
        cin >> cpu.changshang >> cpu.w;
        cin >> HD.name >> HD.data;
        cin >> MB.name >> MB.xinghao;
    }
};
class  Client
{
    Builder* pc;
public:
    Client(Builder*p) {
        pc = p;
    }
    PC*CreatePC() {
        PC* x;
        x->AddToPC(pc->cpu);
        x->AddToPC(pc->MB);
        x->AddToPC(pc->HD);
        return x;
    }
};

int  main()
{

    cout << "\nBuilding  Dell  Computer\n";

    Builder* pDell = new  DellBuilder();  //创建Dell厂商
    Client* pClient1 = new  Client(pDell);  //创建一个用户，并使用dell厂商
    PC* pPC1 = pClient1->CreatePC();    //  生产一台电脑
    pPC1->Work();    //显示电脑的工作状态

    cout << "\nBuilding  IBM  Computer\n";

    IBMBuilder* pIBM = new  IBMBuilder();
    Client* pClient2 = new  Client(pIBM);
    PC* pPC2 = pClient2->CreatePC();
    pPC2->Work();

    return  0;
}