#include<iostream>
using namespace std;

class SimpleCalculator{
    protected:
    int num1,num2;
    public:
    //SimpleCalculator(){}

    int sum(){
        return num1+num2;
    }

    int difference(){
        return num1-num2;
    }

    int product(){
        return num1*num2;
    }

    float division(){
        return (float)num1/num2;
    }
};

class ScientificCalculator{
    public:
    ScientificCalculator(){}

    int square(int num){
        return num*num;
    }

    int cube(int num){
        return num*num*num;
    }

    int squareRoot(int num){
        int sqrt = 0;
        for(int i = 1; i < num; i++){
            if(i*i==num){
                sqrt = i;
            }
        }
        return sqrt;
    }

    int cubeRoot(int num){
        int cbrt = 0;
        for(int i = 1; i < num; i++){
            if(i*i*i==num){
                cbrt = i;
            }
        }
        return cbrt;
    }
};

class HybridCalculator : protected SimpleCalculator, protected ScientificCalculator{
    private:
    int result;
    public:
    void driverCode(){
        cout << "Enter two numbers: ";
        cin >> num1 >> num2;
        cout << "Sum is " << sum() << endl;
        cout << "Difference is " << difference() << endl;
        cout << "Product is " << product() << endl;
        cout << "Division is " << division() << endl;
        cout << "Squares are " << square(num1) << " " << square(num2) << endl;
        cout << "Cubes are " << cube(num1) << " " << cube(num2) << endl;
        cout << "Squares are " << squareRoot(num1) << " " << squareRoot(num2) << endl;
        cout << "Squares are " << cubeRoot(num1) << " " << cubeRoot(num2) << endl;
    }
};

int main()
{
    HybridCalculator calc;
    calc.driverCode();
    return 0;
}