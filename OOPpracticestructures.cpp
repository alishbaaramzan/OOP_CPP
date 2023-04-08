#include<iostream>
using namespace std;

struct Person{
    string name;
    int age;
};
struct Officer{
    Person p;
    Person *ptr = &p;
    void getData(){
        cout << "Enter name of officer: ";
        cin>>ptr->name;
        cout << "Enter age of officer: ";
        cin >> ptr->age;
    }
    void showData(){
        cout << "Officer's Data: " << endl;
        cout << "Name: " <<ptr->name << endl;
        cout << "Age: " <<ptr->age << endl;
    }
};
int main(){
    Officer off;
    off.getData();
    off.showData();
    delete off.ptr;
    return 0;
}