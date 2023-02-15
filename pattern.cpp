// This program prints a hollow pyramid and then an inverted hollow pyramid pattern
// The program uses a custom header file
// The program is generic
#include<iostream>
using namespace std;

int main(){
    int n;
    cin >>n;

// Loop for hollow pyramid
     for(int i = 0; i < n; i++){
        for(int j = 0; j< n-i-1 ;j++){
             cout << " ";
        }
        cout << "*";
        for(int j =1; j < 2*i; j++){
             cout << " ";
        }
        if(i!=0)
            cout << "*";
        for(int j = 0; j<n-i-1 ;j++){
            cout << " ";
        }
        cout << endl;
     }
     // Loop for inverted hollow pyramid
        for(int i = 0; i < n-1; i++){
            for(int j = 0; j <= i; j++){
                cout << " ";
            }
            cout << "*";
            for(int j = i; j< (2*(n-3)+1)-i ; j++){
                cout << " ";
            }
        if(i!=n-2)
            cout << "*";
        for(int j = 0; j <= i; j++){
                cout << " ";
            }
        cout << endl;   
     }
     return 0;
}