// This code finds the maximum value in all subarrays of a given size
#include<iostream>
using namespace std;

int main(){
	int arr[] = {8,5,10,7,9,4,15,12,90,13};
	int s = sizeof(arr)/sizeof(arr[0]);
	int k;
	cout << "Enter size of sub-array: ";
	cin >> k;
	for(int i = 0; i <= s - k; i++){
		int n = 0;
		int max = 0;
		int j = i;
		while(n<k){
			if(arr[j]>max){
				max = arr[j];
			}
			j++;
			n++;
		}
		cout << max << " ";
	}
	return 0;
}
