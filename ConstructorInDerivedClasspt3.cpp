#include<iostream>
using namespace std;

class Base{
   // int a;
    protected:
    int b;
    public:
    Base(int i){
        b = i;
    }
};
class Derived : public Base{
    int c;
    public:
    Derived(int x, int y): Base(x){
        c = y;
    }
    void display(){
        cout << b << " " << c << endl;
    }
};
int main()
{
    Derived b(1,2);
    b.display();
    return 0;
}

