#include <iostream>
using namespace std;

#define A 10+5
#define AREA(l, b) (l * b)
#define MIN(a,b) (((a)<(b)) ? a : b)

int main(){
    cout<<5*A; // order of precedence will be followed here-> 55 instead of 75
    cout<<"\nArea: "<< AREA(4, 5);
    cout<<"\nMIN: "<<MIN(5,-5);
    return 0;
}