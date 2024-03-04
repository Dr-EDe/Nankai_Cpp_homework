#include<iostream>
using  namespace  std;
class  Vehicle                                      //定义基类 
{
protected:
    int  MaxSpeed;                            //最大速度   
    int  Weight;                                          //重量 
public:
    Vehicle(int  m, int  w)            //初始化成员变量的值   
    {
        MaxSpeed = m < 0 ? 0 : m;
        Weight = w < 0 ? 0 : w;
        cout << "Constructing  Vehicle...\n";
    }
    ~Vehicle()
    {
        cout << "Destructing  Vehicle...\n";
    }
    void  Run()
    {
        cout << "The  vehicle  is  running!\n";
    }
    void  Stop()
    {
        cout << "Please  stop  running!\n";
    }
    void  Show()
    {
        cout << "It's  maxspeed  is:" << MaxSpeed << "  km/h" << endl;
        cout << "It's  weight  is:" << Weight << "  kg" << endl;
    }
};

class  Bicycle :public  Vehicle      //定义派生类，公有继承 
{
protected:
    int  Height;                                //高度，单位：厘米 
public:
    void Show() {
        Vehicle::Show();
        cout << "It's Height is:" << Height << " cm" << endl;
    }
    Bicycle(int a, int b, int c) :Vehicle(a, b) {
        Height = c < 0 ? 0 : c;
        cout << "Constructing Bicycle..." << endl;
    }
    ~Bicycle()
    {
        cout << "Destructing Bicycle..." << endl;
    }
};

int  main()
{
    int  max_speed, weight, height;
    cin >> max_speed >> weight >> height;
    Bicycle  b(max_speed, weight, height);                    //定义派生类对象  
    b.Run();                                          //观察构造、析构函数调用顺序  
    b.Stop();
    b.Show();
    //system("pause");
    return  0;
}