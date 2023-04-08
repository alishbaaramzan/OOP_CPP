#include<iostream>
using namespace std;

class A{
    private:
    int a;
    int b;
    public:
    A(){
        a = 0;
        b = 0;
    }
    void operator++(){
        this->a++;
        this->b++;
    }
    A operator++(int){
        A temp;
        temp.a = this->a;
        temp.b = this->b;
        this->a++;
        this->b++;
        return temp;
    }
    void display(){
        cout << a << " " << b << endl;
    }
};
int main()
{
    A obj1,obj2;
    ++obj1;
    obj1.display();
    obj2 = obj1++;
    obj2.display();
    obj1.display();
    return 0;

}