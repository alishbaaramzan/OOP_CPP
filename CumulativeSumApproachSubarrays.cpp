#include<iostream>
#include<climits>
using namespace std;

int main()
{
    int n;
    int max_sum = INT_MIN;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    // making a cumulative array
    int cumarray[n+1];
    cumarray[0] = 0;
    for(int i = 1; i < n+1; i++){
        cumarray[i] = cumarray[i-1] + arr[i-1]; // adding all previuos elements to a prefix
    }
    for(int i = 1; i <=n; i++){
        for(int j = 1; j <= i; j++){
            // checkhing which part of the array has max sum
            if(cumarray[i]-cumarray[j] > max_sum){
                max_sum = cumarray[i]-cumarray[j];
            }
        }
    }
    cout << "Maximum sum is " << max_sum << endl;
    return 0;
}