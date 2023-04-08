#include <iostream>
using namespace std;

class Class1{
    private:
    int value1;
    int value2;

    public:
    Class1() : value1(0), value2(0) {}

    // overloading prefix operator
    void operator++(){
        this->value1+=1;
        this->value2+=1;
    }
    // overloading postfix operator
    Class1 operator++(int){
       Class1 temp;
       temp.value1 = this->value1;
       temp.value2 = this->value1;
       this->value1+=1;
       this->value2+=1;
       return temp;

    }
    void printData(){
        cout << value1 << " " << value2 << endl;
    }
};
int main()
{
    Class1 c1, c2;
    ++c1;
    cout << "Prefix operator in action is: ";
    c1.printData(); 
    c2 = c1++;
    cout << "Postfix operator in action is : ";
    c2.printData();
    cout << "Whereas c1 was increased: ";
    c1.printData();
    return 0;
}