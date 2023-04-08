#include<iostream>
using namespace std;

class Midq1{
    private:
    float var1;
    float var2;
    public:
    Midq1(){
        var1 = 0;
        var2 = 0;
    }
    Midq1(float var1, float var2){
        this->var1 = var1;
        this->var2 = var2;
    }
    float getSum(){
        return var1 + var2;
    }
    friend bool compare(const Midq1 &obj1, const Midq1 &obj2);
};
// friend function for comparison
bool compare(const Midq1 &obj1, const Midq1 &obj2){
    if(obj1.var1 > obj2.var1 && obj1.var2 > obj2.var2){
        return true;
    }
    else
        return false;
}
int main(){
    Midq1 obj1(1,2), obj2(3,4);
    if(compare(obj1,obj2)){
        cout << "Object 1 is greater" << endl;
    }
    else
        cout << "Object 2 is greater" << endl;
    return 0;  
}