// Using a sinle pointer
#include<iostream>
using namespace std;

int main()
{
    int m,n;
    m = 3; // rows
    n = 4; // columns
    int * arr = new int[m*n]; // allocating memory for 3*4 integers
    cout << "Enter " << m*n << " values : " << endl;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> *(arr + i*n + j);
        }
    }

    cout << "Entered values are: " << endl;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cout << *(arr + i*n + j) << " ";
        }
        cout << endl;
    }

    delete [] arr;
    return 0;
}