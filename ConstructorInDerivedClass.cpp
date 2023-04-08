#include<iostream>
using namespace std;

class Base1{
    int data1;
    public:
    Base1(){
        cout << "Base1 constructor called" << endl;
    }
    Base1(int i){
        data1 = i;
        cout << "Base1 class constructor called" << endl;
    }
    void printData1(){
        cout << "The value of data is " << data1 << endl;
    }
};

class Base2{
    int data2;
    public:
    Base2(){
        cout << "Base2 constructor called" << endl;
    }
    Base2(int i){
        data2 = i;
        cout << "Base2 class constructor called" << endl;
    }
    void printData2(){
        cout << "The value of data is " << data2 << endl;
    }
};

class Derived : public Base1, public Base2{
    int derived1, derived2;
    public:
    Derived( int c, int d){
        derived1 = c;
        derived2 = d;
        cout << "Derived class constructor is called" << endl;
    }
    void printDerived(){
        cout << "derived1 is " << derived1 << " derived2 is " << derived2 << endl;
    }
};
int main()
{
    Derived obj(1,2);
    obj.printDerived();
    return 0;
}