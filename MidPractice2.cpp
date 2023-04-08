#include<iostream>
using namespace std;

class Midq2{
    private:
    float * var;
    public:
    Midq2(float value){
        var = new float(value);
    }
    void increment(){
        (*var)++;
    }
    float getValue(){
        return *var;
    }
    ~Midq2(){
        delete var; // deallocating dynamically created variable
    }
};
int main(){
    Midq2 obj(1);
    obj.increment();
    cout << "The value is :" <<  obj.getValue() << endl;
    return 0;
}