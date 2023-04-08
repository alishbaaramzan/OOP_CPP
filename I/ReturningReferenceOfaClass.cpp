#include<iostream>
using namespace std;

class Complex{
    int real;
    int imaginary;

    public:
    Complex(){
        real = 1;
        imaginary = 1;
    }
    Complex(int r, int i){
        real = r;
        imaginary = i;
    }
    void display(){
        cout << "The number is: "
        << real << "+" << imaginary << "i" << endl;
    }
    void operator++(){
        this->real++;
        this->imaginary++;
    }
    friend Complex& add_one(Complex&c);
};
Complex& add_one(Complex&c){
    c.real++;
    c.imaginary++;
    return c;
}
int main(){
    Complex c1;
    Complex& c2 = add_one(c1);
    ++c2; // increases c1 too beacuse of pointing to similar memory location
    c1.display();
    c2.display();
    return 0;
}