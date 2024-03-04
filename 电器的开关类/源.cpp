#include    <iostream>
using    namespace    std;

class    IElectricalEquipment {
public:
    virtual    void    PowerOn() = 0;    //ÿ�ֵ������ܴ�
    virtual    void    PowerOff() = 0;    //ÿ�ֵ������ܹر�
    virtual    ~IElectricalEquipment() {
        cout << "This  is  Virtual  ~IElectricalEquipment()" << endl;
    }
};


class    Switch {
public:
    IElectricalEquipment* Elec;
    virtual    void    On() = 0;
    virtual    void    Off() = 0;
    virtual    ~Switch() {
        cout << "This  is  Virtual  ~Switch()" << endl;
    }
};
class Fan:public IElectricalEquipment {
    void PowerOn() { cout << "Fan open" << endl; }
    void PowerOff() { cout << "Fan close" << endl; }
};
class Light :public IElectricalEquipment {
    void PowerOn() { cout << "Light open" << endl; }
    void PowerOff() { cout << "Light close" << endl; }
};
class FancySwitch:public Switch {
public:
    void On() {
        cout << "Fancy Switch On" << endl;
        Elec->PowerOn();
    }
    void Off() {
        cout << "Fancy Switch Off" << endl;
        Elec->PowerOff();
    }
};
class NormalSwitch :public Switch {
    void On() {
        cout << "Normal Switch On" << endl;
        Elec->PowerOn();
    }
    void Off() {
        cout << "Normal Switch Off" << endl;
        Elec->PowerOff();
    }
};
int  main() {
    //��������豸:����,����
    IElectricalEquipment* fan = new  Fan();
    IElectricalEquipment* light = new  Light();
    //���쿪��
    Switch* fancySwitch = new  FancySwitch();
    Switch* normalSwitch = new  NormalSwitch();

    //�ѷ������ӵ�ʱ�п���
    fancySwitch->Elec = fan;

    //�������ӵ�����,��ô�����ش򿪻�ر�ʱ����Ӧ�ô�/�ر�
    fancySwitch->On();
    fancySwitch->Off();

    //�ѵ�����ӵ���ͨ����
    normalSwitch->Elec = light;
    normalSwitch->On();  //�򿪵��
    normalSwitch->Off();  //�رյ��

    //�ѵ�����ӵ�ʱ�п���
    fancySwitch->Elec = light;
    fancySwitch->On();
    fancySwitch->Off();

    delete  fan;
    delete  light;
    delete  fancySwitch;
    delete  normalSwitch;
    return  0;
}