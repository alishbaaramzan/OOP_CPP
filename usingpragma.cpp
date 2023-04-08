#include<iostream>
using namespace std;

void sum(int a, int b){ //is not being used
    cout << a;
}
int main(){
    int a,b;
    cin >> a >> b;
    cout << "The sum is ";
    sum(a,b);
    return 0;
}