#include<iostream>
using namespace std;

class Shape{
    public:
    int sides;

    public:
    Shape() : sides(0){}//default initializer list

    Shape(int s) : sides(s){} // parameterized initializer list

    Shape(const Shape &s); // copy constructor

    void printSides(){
        cout << "This shape has " << sides << " sides " << endl;
    }

};

Shape :: Shape(const Shape &s){
    sides = s.sides;
}
int main()
{
    Shape s1;
    Shape s2(4);
// To check the input sides
    s1.printSides();
    s2.printSides();
// Copying second object to first without copy constructor/function
    s1 = s2;
    s1.printSides();
// Copying second object to third using copy constructor
    Shape s3(s2);
    s3.printSides();
// now checking if s1 = s2 is shallow copy
s2.sides-=1;
//s1.sides-=1;
cout << "Checking oif changing value of sides of s2 affects s1: " << endl;
s1.printSides();
return 0;

}