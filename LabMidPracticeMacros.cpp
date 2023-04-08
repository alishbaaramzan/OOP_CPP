#include<iostream>
using namespace std;
#define AREA(l,b)(l*b)

int main()
{
    int n1,n2,area;
    n1 = 2;
    n2 = 3;
    area = AREA(n1,n2);
    cout << "Area is " << area << endl;
    return 0;
}