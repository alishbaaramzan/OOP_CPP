#include<iostream>
using namespace std;

class Date{
    private:
    int day, month, year;
    public:
    void getDate(){
        cout << "Enter dateof joining (dd mm yyyy): " << endl;
        cin>> day >> month >> year;
    }
    void displayDate(){
        cout << day << "/" << month << "/" << year;
    }
    bool operator<(const Date &d){
        if(this->year < d.year){
            return true;
        }
        else if(this->year == d.year){
            if(this->month < d.month){
                return true;
            }
            else if(this->month == d.month){
                if(this->day < d.day){
                    return true;
                }
                else
                    return false;
            }
            else
                return false;
        }
        else 
            return false;
    }
};

class Person{
    private:
    string name;
    int reg_no;
    Date date;
    public:
    Person(){
        cout << "Enter your name: " << endl;
        cin >>name;
        cout << "Enter your registration number: " << endl;
        cin >> reg_no;
        date.getDate();
    }
    bool operator<(const Person &p){
        if(this->date < p.date){
            return true;
        }
        else
            return false;
    }
    string displayname(){
        return name;
    }
    void displayDate(){
        this->date.displayDate();
    }

};

int main()
{
    Person p1;
    Person p2;
    if(p1<p2){
        cout << p1.displayname() << " is smarter because ";
        p1.displayDate();
        cout << " is earlier than ";
        p2.displayDate();
        cout << endl;
    }
    else{
        cout << p2.displayname() << " is smarter because ";
        p2.displayDate();
        cout << " is earlier than ";
        p1.displayDate();
        cout << endl;
    }
    return 0;
}