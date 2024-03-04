#include  <iostream>
#include  <iomanip>

using  namespace  std;
class  Time
{
public:
    Time(int  year1 = 0, int  month1 = 0, int  day1 = 0, int  hour1 = 0, int  minute1 = 0, int  second1 = 0);
    void  setTime(int  year1, int  month1, int  day1, int  hour1, int  minute1, int  second1);
    void  printTime();

    friend  Time  operator+(int  n, Time  t);
    int  operator-(Time  t);
    Time& operator++();
    Time  operator++(int);
    Time& operator--();
    Time  operator--(int);

private:
    int  year, month, day, hour, minute, second;
};
Time operator+(int n, Time t) {
    n = n % 100000;
    t.day += (n / (24*3600));
    t.hour += ((n - t.day * 24 * 3600) / 3600);
    t.minute += ((n - t.day * 24 * 3600 - t.hour * 3600) / 60);
    t.second += ((n - t.day * 24 * 3600 - t.hour * 3600 - t.minute * 60));
    t.minute += (t.second / 60); t.second %= 60;
    t.hour += (t.minute / 60); t.minute %= 60;
    t.day += (t.hour / 24); t.hour %= 24;
        if (t.month == 1 || t.month == 3 || t.month == 5 || t.month == 7 || t.month == 8 || t.month == 10 ) {
            if (t.day > 31) { t.day -= 31; t.month++; }
        }
        else if (t.month == 2) {
            if ((t.year % 4 == 0 && t.year % 100 != 0) || t.year % 400 == 0) {
                if (t.day > 29) { t.day -= 29; t.month++; }
            }
            else { if (t.day > 28) { t.day -= 28; t.month++; } }
        }
        else if (t.month == 12) {
            if (t.day > 31) { t.day -= 31; t.month = 0; t.year++; }
        }
        else { if (t.day > 30) { t.day -= 30; t.month++; } }
        return t;
}
int Time:: operator-(Time  t) {
   //相减
}
Time& Time::operator++() {

}//前缀
Time Time::operator++(int) {

}//后缀
Time& Time::operator--() {

}//前缀
Time Time::operator--(int) {

}//后缀
Time::Time(int  year1 = 0, int  month1 = 0, int  day1 = 0, int  hour1 = 0, int  minute1 = 0, int  second1 = 0) {
    year = 0; month = 0; day = 0; hour = 0; minute = 0; second = 0;
}
void Time::setTime(int  year1, int  month1, int  day1, int  hour1, int  minute1, int  second1) {
    year = year1; month = month1; day = day1; hour = hour1; minute = minute1; second = second1;
}
void Time::printTime() {
    cout << year << '/' << month << '/' << day << ' ' << hour << ':' << minute << ':' << second << endl;
}














int  main()
{

    int  year, month, day;
    int  hour, minute, second;
    int  number;

    Time  t1, t2, t3, t4;
    cin >> year >> month >> day >> hour >> minute >> second;
    t1.setTime(year, month, day, hour, minute, second);
    cin >> year >> month >> day >> hour >> minute >> second;
    t2.setTime(year, month, day, hour, minute, second);


    t3 = t1--;
    t3.printTime();
    t1.printTime();

    t3 = --t2;
    t3.printTime();
    t2.printTime();

    t4 = t1++;
    t4.printTime();
    t1.printTime();

    t4 = ++t2;
    t4.printTime();
    t2.printTime();

    cin >> number;
    t4 = number + t1;
    t4.printTime();

    int  capacity;
    capacity = t2 - t1;
    cout << capacity << endl;

    return  0;
}