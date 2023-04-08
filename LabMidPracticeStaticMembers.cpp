#include<iostream>
using namespace std;

class Class1{
    private:
    static int count;

    public:
    Class1(){
        cout << "Object created " << endl;
        count++;
    }

    // making a static function to return static data member
    static int returnCount(){
        return count;
    }
};


// Static variable declaration
int Class1 :: count = 0;

int main()
{
    Class1 c1;
    Class1 c2;
    //cout << "Number of objects is :" Class1 :: count << endl; // not possible because static data member is visible only within the class
    cout << "Number of objects created is " << Class1 :: returnCount() << endl;
    return 0;
}