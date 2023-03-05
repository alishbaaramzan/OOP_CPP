// This code prints all the subarrays of a given array by brute force
#include<iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    // Printing all the subarrays of the array
    for(int i = 0; i < n; i++){
        int x = 0;
        for(int j = 0; j < n - i; j++){
            for(int k = i; k <= x+i; k++){
                cout << arr[k] << " ";
            }
            x++;
            cout << endl;
        }
    }
    return 0;
}