// This code sorts the arrays first and merges them
#include<iostream>
using namespace std;

bool check(int arr[9], int num){
	int c = 0;
	for(int i = 0; i < 9; i++){
		if(num==arr[i]){
			c++;
		}
	}
	if(c!=0){
		return false;
	}
	else
	return true;
}
int main(){
	int X[4]={1,3,5,6};
	int Y[3]={2,4,8};
	int Z[2]={10,0};
	int P[9] = {0};
	int max;
	for(int i = 0; i < 9; i++){
		max = 0;
		for(int k = 0; k < 4; k++){
			if(X[k]>=max && check(P,X[k])){
				max = X[k];
			}
		}
		for(int k = 0; k < 3; k++){
			if(Y[k]>=max && check(P,Y[k])){
				max = Y[k];
			}
		}
		for(int k = 0; k < 2; k++){
			if(Z[k]>=max && check(P,Z[k])){
				max = Z[k];
			}
		}
		P[i]=max;
	}
	cout << "The sorted and merged array is: " << endl;
	for(int i = 0; i < 9; i++){
		cout << P[i] << " ";
	}
	return 0;
}
