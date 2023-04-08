#include<iostream>
using namespace std;

class A{
    private:
    int a;
    protected:
    int b;
    public:
    int c;
    A(){};
    void setValuebAndc(int b, int c){
        this->b = b;
        this->c = c;
    }
};

class B : public A{
    private:
    int d;
    protected:
    int e;
    // b
    public:
    int f;
    //c
    B(){}
    // setValuebAndc
    void setValueeAndf(int e, int f){
        this->e = e;
        this->f = f;
    }
};

class C : public B{
    //protected: b and e
    //public: f and c
    public:
    void showValues(){
        cout << b <<" " << c  <<" "<< e <<" "<< f << endl;
    }
};

int main()
{
    C object;
    object.setValuebAndc(1,2);
    object.setValueeAndf(3,4);
    object.showValues();
    return 0;
}