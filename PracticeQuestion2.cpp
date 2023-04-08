#include<iostream>
using namespace std;

class Rational{
    private:
    int numerator;
    int denominator;

    public:
    Rational(){
        cout << "Enter numerator: ";
        cin >> numerator;
        cout << "Enter denominator: ";
        cin >> denominator;
        reduced_form();
    }
    
    void reduced_form(){
        int m = 0;
        if(numerator>denominator){
            for(int i = 1; i < denominator; i++){
                if(numerator%i==0 && denominator%i==0){
                    m = i;
                }
            }
            numerator/=m;
            denominator/=m;
        }
        if(denominator>numerator){
            for(int i = 1; i < numerator; i++){
                if(numerator%i==0 && denominator%i==0){
                    m = i;
                }
            }
            numerator/=m;
            denominator/=m;
        }
    }
    Rational operator+(const Rational &r){
        Rational temp;
        int lcm = LCM(r);
        temp.numerator = ((lcm/denominator)*numerator + (lcm/r.denominator)*r.numerator);
        temp.denominator = lcm;
        temp.reduced_form();
        return temp;
    }
    Rational operator-(const Rational &r){
        Rational temp;
        int lcm = LCM(r);
        temp.numerator = ((lcm/denominator)*numerator - (lcm/r.denominator)*r.numerator);
        temp.denominator = lcm;
        temp.reduced_form();
        return temp;
    }
    Rational operator*(const Rational &r){
        Rational temp;
        temp.numerator = numerator*r.numerator;
        temp.denominator = denominator*r.denominator;
        temp.reduced_form();
        return temp;
    }
    Rational operator/(const Rational &r){
        Rational temp;
        temp.numerator = numerator*r.denominator;
        temp.denominator = denominator*r.numerator;
        temp.reduced_form();
        return temp;
    }
     int LCM(const Rational &obj2);
    
    void display(){
        cout << numerator << "/" << denominator << endl;
    }
    float displayInFloatingPoint(){
        float temp = (float)numerator/denominator;
        return temp;
    }
};

int Rational :: LCM(const Rational &obj2){
    int lcm = 0;
    for(int i = 1; i <= denominator * obj2.denominator; i++){
        if(i%denominator==0 && i%obj2.denominator==0){
            lcm = i;
            break;
        }
    }
    return lcm;
}
int main()
{
    Rational r1;
    r1.display();
    Rational r2;
    r2.display();
    Rational r3 = r1 + r2;
    r3.display();
    Rational r4 = r1 - r2;
    r4.display();
    Rational r5 = r1 * r2;
    r5.display();
    Rational r6 = r1 / r2;
    r6.display();
    cout << r1.displayInFloatingPoint() << endl;
    return 0;
}