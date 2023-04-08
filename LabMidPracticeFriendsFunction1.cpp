#include<iostream>
using namespace std;

class Distance{
    private:
    int meter;
    public:
    Distance() : meter(0){}
    
    void printData(){
        cout << meter << endl;
    }
    // friend function declaration
    friend int addFive(Distance d);
};
int addFive(Distance d){
    d.meter+=5;
    return d.meter;
}
int main(){
    Distance d;
    d.printData();

    cout << "After adding five " << addFive(d) << endl;
    cout << "Now the value of the meter in d is: " ;
    d.printData();
    return 0;
}