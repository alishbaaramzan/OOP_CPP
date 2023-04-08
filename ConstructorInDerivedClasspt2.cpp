#include<iostream>
using namespace std;

class Base{
    private:
    int a;
    protected:
    int b;
    public:
    Base(){
        cout << "Constructor called" << endl;
    }
    Base(int a, int b){
        this->a = a;
        this->b = b;
    }
};
class Derived : public Base{
    private:
    int c;
    protected:
    int d;
    public:
    Derived(int x, int y, int z){
        b = x;
        c = y;
        d = z;
    }
    void display(){
        cout << b << " " << c << " " << d << endl;
    }
};
int main()
{
    Derived d(1,2,3);
    d.display();
    return 0;
}