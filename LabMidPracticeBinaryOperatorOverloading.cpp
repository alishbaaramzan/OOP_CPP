#include <iostream>
using namespace std;

class Class{
    int a;
    int b;
    public:
    Class(){
        a = 0;
        b = 0;
    }
    Class(int a, int b){
        this->a = a;
        this->b = b;
    }
    Class operator+(const Class &c2){
        Class temp;
        temp.a = this->a + c2.a;
        temp.b = this->b + c2.b;
        return temp;
    }

    void printData(){
        cout << "a: " << a << endl;
        cout << "b: " << b << endl;
    }
};
int main()
{
    Class c1(1,2), c2(3,4);
    // Now if we wish to add them
    // We could use Class c3 = c1.add(c2)
    // However, via operator overloading we can use
    Class c3 = c1+c2; // c1 is calling the add function here
    c3.printData();
    return 0;
}