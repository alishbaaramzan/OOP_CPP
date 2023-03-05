// This code finds the maximum sum of the subarrays using kadane's algorithm
/*Kadane's algorithm continues adding the elements of the array to get sum
  but when sum becomes negative, it makes the sum zero*/

#include<iostream>
#include<climits>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    // taking elements in the array
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int curr_sum = 0;
    int max_sum = INT_MIN;
    for(int i = 0; i < n; i++){
        // adding the number to sum
            curr_sum+=arr[i];
        // making sum zero when current sum becomes negative
        if(curr_sum<0){
            curr_sum=0;
        }
        if(max_sum<curr_sum)
            max_sum = curr_sum; // updating max sum
    }
    cout  << "Max sum is " << max_sum << endl;
    return 0;
}