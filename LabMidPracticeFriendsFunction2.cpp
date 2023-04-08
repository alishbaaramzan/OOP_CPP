#include<iostream>
using namespace std;

class Class2;

class Class1{
    private:
    int a;

    public:
    Class1(int n) : a(n){}

    friend int addClasses(Class1, Class2);
};

class Class2{
    private:
    int a;

    public:
    Class2(int n) : a(n){}

    friend int addClasses(Class1, Class2);

};
// function to add the private data members of the two classes
int addClasses(Class1 c1, Class2 c2){
    return (c1.a + c2.a);
}
int main()
{
    Class1 c1(3);
    Class2 c2(4);
    cout << "Adding the private data members of two classes we get " << addClasses(c1,c2) << endl;
    return 0;

}