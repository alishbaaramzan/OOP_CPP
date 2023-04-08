#include<iostream>
using namespace std;

class Class1;

class Class2{
    private:
    int a2;

    public:
    Class2(int n2) : a2(n2) {}
    int addtoClass1(const Class1 &c1);

};

class Class1{
    private:
    int a1;

    public:
    Class1() : a1(0) {}
    Class1(int n2) : a1(n2) {}

    friend int Class2 :: addtoClass1(const Class1 &c1);
};

// This function adds its own private member and that of class one and returns the sum
    int Class2 :: addtoClass1(const Class1 &c1){
        return (c1.a1+a2);
    }
int main()
{
    Class1 c1(4);
    Class2 c2(4);
    
    cout << "Sum is " << c2.addtoClass1(c1) << endl;
    return 0;
}
