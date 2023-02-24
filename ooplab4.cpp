#include<iostream>
using namespace std;

class Time{
    public:
        int hour;
        int minutes;
        string format;
};

class Date{
    public:
        int day;
        int month;
        int year;

};

class Event{
    public:
    string name;
    Time T;
    Date D;

    //This function gets the values of date by the user
    void get_date(){
        cout << "Enter the date:" << endl;
        cout << "Day: ";
        cin >> D.day;
        cout << "Month: ";
        cin >> D.month;
        cout << "Year: ";
        cin >> D.year;
        cout << endl;
    }

    // This function gets the values of time by the user
    void get_time(){
        cout << "Hour: ";
        cin >> T.hour;
        cout << "Minutes: ";
        cin >> T.minutes;
        cout << "am/pm: ";
        cin >> T.format;
        cout << endl;
    }

    // This function displays the proper time and date of the event
    void display(){
        cout << name << " is scheduled for: " << endl;
        cout << D.day << "/" << D.month << "/" << D.year << endl;
        cout << T.hour << ":" << T.minutes << " " <<T.format << endl;
    }
};
int main(){
    Event event;
    cout << "Enter the name of the event: ";
    getline(cin,event.name);
    cout << endl;

    // calling functions from the class event for further values
    event.get_date();
    event.get_time();

    // Now displaying the values in main
    // We can do that directly as all members all public, but I'll be using a function here
    event.display();

    return 0;
}