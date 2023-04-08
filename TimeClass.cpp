#include<iostream>
using namespace std;

class Time{
    private:
    int hours;
    int minutes;
    int seconds;

    public:
    Time() : hours(0), minutes(0), seconds(0){}
    Time(int hours, int minutes, int seconds){
        this->hours = hours;
        this->minutes = minutes;
        this->seconds = seconds;
    }
    Time add(const Time &t)const{
        Time temp;
        temp.hours = this->hours + t.hours;
        temp.minutes = this->minutes + t.minutes;
        temp.seconds = this->seconds + t.seconds;
        if(temp.seconds>=60){
        while(temp.seconds>=60){
            temp.minutes++;
            temp.seconds-=60;
        }
        }
        if(temp.minutes>=60){
            while(temp.minutes>=60){
                temp.hours++;
                temp.minutes-=60;
            }
        }
        return temp;
    }
    void display()const{
        cout << hours<< ":" << minutes << ":" << seconds << endl;
    }
};
int main()
{
    const Time t1(1,20,30);
    const Time t2(2,40,34);
    Time t3 = t1.add(t2);
    t3.display();
    return 0;

}