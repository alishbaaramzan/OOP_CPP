#include<iostream>
#include "OOPpracticeheaderfile.h"
using namespace std;

int main(){
    PracticeClass p1(1,2);
    int sum = p1.getSum();
    cout << "The sum is " << sum << endl;
    PracticeClass p2;
    int a,b;
    cout << "Enter two values: " << endl;
    cin >> a >> b;
    p2.setter(a,b);
    cout << "Sum is " << p2.getter1() + p2.getter2() << endl;
    PracticeClass p3(p1);
    cout << "Sum is " << p3.getSum() << endl;
    return 0;
}