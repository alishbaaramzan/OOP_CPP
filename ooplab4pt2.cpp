#include<iostream>
using namespace std;

enum units{meter=1, centimeter, inches, feet};

class D1{
    private:
        double meters;
        double centimeters;
    public:
        // This function is for getting values
        void getValues(){
            cout << "Meters: ";
            cin >> meters;
            cout << "Centimeters: ";
            cin >> centimeters;
        }

        // Making the other class friend so as to access the data members here
        friend class D2;
};
class D2{
    private:
        double inches;
        double feet;
    public:
        // This is a function which will add values from the two classes
        double addition(D1 &d1){
        int unit;
        cout << "Enter the unit for addition: " << endl;
        cout << "1.meter\n2.centimeter\n3.inches\n4.feet\n";
        cin >> unit;
        double temp = d1.meters + (float)d1.centimeters/100 + (float)inches/39.3701 + (float)feet/3.28084;
        if(unit==meter){
            return  temp;
        }
        else if (unit == centimeter){
            return temp*100;
        }
        else if (unit == inches){
            return temp*39.3701;
        }
        else if (unit == feet){
            return temp*3.28084;
        }
        else{
            cout << "Wrong unit selected!" << endl;
            return 0;
        }
        }
    
        // This function is for getting values
        void getValues(){
            cout << "Feet: ";
            cin >> feet;
            cout << "Inches: ";
            cin >> inches;
        }

};

int main(){
    D1 obj1;
    D2 obj2;
    cout << "Enter the following distances for addition: " << endl;
    obj1.getValues();
    obj2.getValues();
    double result = obj2.addition(obj1);
    cout << "The sum is " << result << endl;
    return 0;
}