#include<iostream>
using namespace std;

class Complex{
    private:
    float real;
    float imaginary;

    public:
    Complex(){}
    Complex(int r, int i) : real(r),imaginary(i){}

    Complex operator+(const Complex &c){
        Complex temp;
        temp.real = this->real + c.real;
        temp.imaginary = this->imaginary + c.imaginary;
        return temp;
    }
    Complex operator-(const Complex &c){
        Complex temp;
        temp.real = this->real - c.real;
        temp.imaginary = this->imaginary - c.imaginary;
        return temp;
    }
    Complex operator*(const Complex &c){
        Complex temp;
        temp.real = real*c.real + (-1)*imaginary*c.imaginary;
        temp.imaginary = real*c.imaginary + imaginary*c.real;
        return temp;
        
    }
    Complex operator/(const Complex &c){
        Complex temp;
        temp.real = (real*c.real + imaginary*c.imaginary)/(c.real*c.real + c.imaginary*c.imaginary);
        temp.imaginary = ((-1)*real*c.imaginary + imaginary*c.real)/(c.real*c.real + c.imaginary*c.imaginary);
        return temp;
        
    }
    void display(){
        cout << "Result is " << real << "+" << imaginary << "i" << endl;
    }
};

int main()
{
    int r1, r2;
    int i1, i2;
    cout << "Enter real part of first number: ";
    cin >> r1;
    cout << "Enter imaginary part of first number: ";
    cin >> i1;
    cout << "Enter real part of second number: ";
    cin >> r2;
    cout << "Enter imaginary part of second number: ";
    cin >> i2;
    Complex c1(r1,i1);
    Complex c2(r2,i2);
    Complex c3 = c1+c2;
    c3.display();
    Complex c4 = c1-c2;
    c4.display();
    Complex c5 = c1*c2;
    c5.display();
    Complex c6 = c1/c2;
    c6.display();
    return 0;
}