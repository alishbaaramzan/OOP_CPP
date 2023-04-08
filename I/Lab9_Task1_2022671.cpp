#include<iostream>
using namespace std;

class Base{
    protected:
    int ba;
    public:
    void input_base(){
        cout << "Enter value of base: ";
        cin >> ba;
    }
    void show_base(){
        cout << "The value of base is: " << ba << endl;
    }
};
class Exponent{
    protected:
    int exp;
    public:
    void input_exp(){
        cout << "Enter value of exponent: ";
        cin >> exp;
    }
    void show_exp(){
        cout << "The value of exponent is : " << exp << endl;
    }
};
class Derived : public Base, public Exponent{
    int po;
    public:
    Derived() : po(1){}
    void in1(){
        input_base();
        input_exp();
    }
    void show1(){
        show_base();
        show_exp();

        // calculating the base raised to exponent usinf for loop
        for(int i = 0; i < exp; i++){
            po *= ba;
        }
        cout << ba << " raised to the power " << exp << " is: " << po << endl;
    }
    
};
int main(){
    Derived obj;
    obj.in1();
    obj.show1();
    return 0;
}