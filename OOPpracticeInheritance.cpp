#include<iostream>
using namespace std;

//Base class
class Base{
    protected:
    int a,b; 
    public:
    Base(){
        cout << "Default constructor of base class" << endl;
    }
    Base(int a, int b){
        cout << "Para constructor of base class" << endl;
        this->a = a;
        this->b = b;
    }
};

//Derived Class
class Derived : public Base{
    int c;
    public:
    Derived(){
        cout << "Default constructor of Derived class" << endl;
    }
    Derived(int a, int b, int c) : Base(a,b){ // parametized constructor of base class is explicitly invoked
        cout << "Para constructor of derived class" << endl;
        this->c = c;
    }
};
int main(){

    Derived d1;
    /*Here default constructors should be called in the following order:
    Base class
    Derived Class */

    Derived d2(1,2,3);
    /*Here parameterized constructors should be called in the following order:
    Base class
    Derived class*/

    return 0;
}