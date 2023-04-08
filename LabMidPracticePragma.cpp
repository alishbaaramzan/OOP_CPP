#include<iostream>
#include"LabMidPracticeheader1.h"

using namespace std;

int main(){
    // code to ignore the specific warning
   #pragma GCC diagnostic push
   #pragma GCC diagnostic ignored "-Wwrite-strings"

    Person p1 = {"alishba",19};
    Person p2 = {"warda",16};
    
    #pragma GCC diagnostic pop

    Person p3 = myfunc(p3,p1);
    cout << p3.name << " " << p3.age << endl;
    return 0;
}