
#include<iostream>
#include "factorial.h"
using namespace std;

int main(){
    int n;
    cin >> n;
    
    // Calling function from our custom header file
    cout << "The factorial of " << n << " is " << factorial(n) << endl;
    return 0;
}
