#include<iostream>
using namespace std;
 
class Base{
    protected:
    int var_b;

    public:
    Base() : var_b(1){}
    virtual void display(){ // now overridden display can also be invoked using pointer to derived class
        cout << "Base class" << endl;
        cout << var_b << endl;
    }
};

class Derived : public Base{
    int var_c;
    public:
    Derived() : var_c(1){}
    void display(){
        cout << "Derived class" << endl;
        cout <<var_b << " " <<  var_c << endl;
     }
};
int main(){
     Base* bptr = new Derived(); // pointer to derived class
    // bptr->display(); // displays base function if virtual keyword is not used->default behaviour
    bptr->display(); // Now it invokes display() of derived class
     return 0;
}