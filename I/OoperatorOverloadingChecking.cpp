#include<iostream>
using namespace std;

class Complex{
    private:
    int real;
    int imaginary;

    public:
    Complex(){
       } 
    

    ostream& operator <<(ostream& os)const{
        os << real << "+" << imaginary << "i" << endl;
        return os;
  }
    
    istream& operator >>(istream& is){
        is >> real >> imaginary;
        return is;
    }

};
ostream& operator <<(ostream& os, const Complex& c){
    return c << os;
}
istream& operator >>(istream &in, Complex &c){
    return c >> in;
}
int main(){
    Complex c1, c2;
    cin >> c1 >> c2; // we can input in the same line because of input chaining i.e. using references
    cout << c1 << c2; // as aove but for output
    return 0;
}