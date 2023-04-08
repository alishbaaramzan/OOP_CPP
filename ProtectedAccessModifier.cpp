//Protected are the private-like variables that can be inherited
//Private variables can not be inherited but protected can
#include<iostream>
using namespace std;

class Base{
    private:
    int a;
    protected:
    int b;
    public:
    int c;
    Base(){
        a = 0;
        b = 0;
        c = 0;
    }
};

class Derived : protected Base{
    public:
    int returnProtectedMember(){
        return c; // public member became protected in a protected derived class
    }
};

int main()
{
    Base base;
    cout << base.c << endl; // public data member can be called
   // cout << base.b << endl; can not be called since it is protecetd
    Derived der;
    cout << der.returnProtectedMember() << endl;
    return 0;

}