// This code finds the max sum of the subarrrays of a given array by brute force approach
#include<iostream>
#include<climits>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int max_sum = INT_MIN;
    // Now converting the given array into subarrays
    for(int i = 0; i < n; i++){
        int x = 0;
        for(int j = 0; j < n - i; j++){
            int sum = 0;
            for(int k = i; k <=x+i; k++){
                sum+=arr[k];
            }
            if(sum>=max_sum) max_sum = sum;
            x++;
        }
    }
    cout << "Maximum sum of the subarrays is " << max_sum << endl;
    return 0;
}