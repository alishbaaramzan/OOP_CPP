#include<iostream>
using namespace std;

class Base{
    int a,b;
    protected:
    int c,d;
    public:
    //Base(){}
    Base(int x, int y, int z){
        a = x;
        b = y;
        c = z;
        d = z;
    }
};
class Derived : public Base{
    int e,f;
    public:
    Derived(int l, int m, int n) : Base(l,m,n){
        e = l;
        f = l;
    }
    void show(){
        cout << c << " " << d << " " << e << " " << f << endl;
    }
};
int main()
{

}