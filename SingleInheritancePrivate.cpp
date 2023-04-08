#include<iostream>
using namespace std;

// Base class
class Base{
    int data1; // private by default and is not inheritable
    public:
        Base(){} // default constructor
        int data2;
        void setData();
        int getData1();
        int getData2();

};
void Base :: setData(){
    data1 = 10;
    data2 = 20;
}
int Base :: getData1(){
    return data1;
}
int Base :: getData2(){
    return data2;
}

// Derived class
class Derived : private Base{
    int data3;
    public:
        void process();
        void display();
};
void Derived :: process(){
    setData(); 
    data3 = data2 * getData1();
}
void Derived :: display(){
    cout << "Value of data1 is " << getData1() << endl;
    cout << "Value of data2 is " << data2 << endl;
    cout << "Value of data3 is " << data3 << endl;
}
int main()
{
    Derived der;
    //der.setData(); // Public member inherited as private data member
    der.process();
    der.display();
    return 0;
}