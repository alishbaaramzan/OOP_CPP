#include<iostream>
using namespace std;
// class for a complex number
class ImaginaryNumber{
    private:
        int real;
        int imaginary;
    public:
        //Default constructor
        ImaginaryNumber(){
            real = 0;
            imaginary = 0;
        }
        // parameterized constructor
        ImaginaryNumber(int r, int i){
            real = r;
            imaginary = i;
        }
        // function to store values as sum
        void add(ImaginaryNumber &num1, ImaginaryNumber &num2){
            this -> real = num1.real + num2.real;
            this -> imaginary = num1.imaginary + num2.imaginary;
        }
        // this function returns the value of real part
        int getReal(){
            return real;
        }
        // this function returns the value of imaginary part
        int getImaginary(){
            return imaginary;
        }

};

int main(){
    int real1, real2;
    int imaginary1, imaginary2;

    // For first complex number
    cout << "Enter real part of first complex number: ";
    cin >> real1;
    cout << "Enter imaginary part of first complex number: ";
    cin >> imaginary1;
    // making object 
    ImaginaryNumber n1(real1, imaginary1);

    // For second complex number
    cout << "Enter real part of second complex number: ";
    cin >> real2;
    cout << "Enter imaginary part of second complex number: ";
    cin >> imaginary2;
    // making object 
    ImaginaryNumber n2(real2, imaginary2);

    // Making a third object for sum
    ImaginaryNumber sum;
    sum.add(n1,n2);
    cout << "The sum is " << sum.getReal() << "+" << sum.getImaginary() << "i" << endl;

    return 0;

}