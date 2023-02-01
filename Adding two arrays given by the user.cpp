#include<iostream>
using namespace std;

int main(){
	int arr1[100];
	int arr2[100];
	int a1 = 0, a2 = 0;
	int s = 0;
	char temp;
	
	//Taking input in array 1
	cout << "Enter elements of array 1 ( terminates when Q is pressed)\n";
	for(int i = 0; i < 100; i++){
		cin >> temp;
		if(temp=='Q' || temp=='q'){
			break;
		}
		else{
			arr1[i] = int(temp - '0');
			a1++;
		}
	}
	
	//Taking input in array 2
	cout << "Enter elements of array 2 ( terminates when Q is pressed)\n";
	for(int i = 0; i < 100; i++){
		cin >> temp;
		if(temp=='Q' || temp=='q'){
			break;
		}
		else{
			arr2[i] = int(temp - '0');
			a2++;
		}
	}
	
	// Filling the smaller array with zeroes
	if(a1=a2){
		s = a1;
	}
	if(a1>a2){
		s = a1;
		for(int i = a2; i < a1; i++){
			arr2[i]=0;
		}
	}
	else if(a2>a1){
		s = a2;
		for(int i = a1; i < a2; i++){
			arr1[i]=0;
		}
	}
	
	// Calculating sum of two arrays
	int sum[s];
	for(int i = 0; i < s; i++){
		sum[i] = arr1[i] + arr2[i];
	}
	
	// Displaying sum of two arrays
	cout << "The sum of the two arrays is: " << endl;
	for( int i = 0; i < s; i++){
		cout << sum[i] << " ";
	}
	return 0;
	
}
