#include<iostream>
using namespace std;

class Class{
    private:
    int a;
    int b;

    public:
    Class(int a, int b){
        this->a = a;
        this->b = b;
    }

    bool operator<(const Class &c){
        if(this->a < c.a && this->b < c.b){
            return true;
        }
        else
            return false;
    }
};
int main()
{
    Class c1(1,2);
    Class c2(3,4);
    if(c1<c2){
        cout << "c1 is less than c2" << endl;
    }
    return 0;
}