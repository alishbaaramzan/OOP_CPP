#include<iostream>
using namespace std;
class Class{
    private:
    int a;
    int b;

    public:
    friend istream &operator>>(istream &input, Class &c1){
        input >> c1.a >> c1.b;
        return input;
    }
    friend ostream &operator<<(ostream &output, Class &c1){
        output << "a: " << c1.a << "b :" << c1.b << endl;
        return output;
    }
};

int main()
{
    Class c1;
    //using overloaded input operator to set values
    cin >> c1;
    cout << c1;
    return 0;
}