// using a double pointer
#include<iostream>
using namespace std;

int main()
{
    int m,n,c;
    m = 3; // rows
    n = 4; // columns
    c = 0;
    int **a = new int*[m];
    // declaring memory space
    for(int i = 0; i < m; i++){
        a[i] = new int[n]; // every row has an array of size n
    }
    cout << "Enter " << m*n << " values: " << endl;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }

    cout << "Entered values are: " << endl;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    // deleting the rows
    for(int i = 0; i < m; i++){
        delete [] a[i];
    }
    delete [] a; // deleting the main array
    return 0;
}