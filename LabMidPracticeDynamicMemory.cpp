#include<iostream>
using namespace std;

int main(){
    int *arr = new int[6];
    cout << "Enter six values: " << endl;
    for(int i = 0; i < 6; i++){
        cin >> *(arr+i);
    }
    // Now we increase the size of the array to get four more values
    int *temp = new int[10];
    //cpying the arr to temp
    for(int i = 0; i < 6; i++){
        *(temp+i) = *(arr+i);
    }
    // deleting the arr pointer
    delete [] arr;
    // voila! we can now add four more values
    cout << "Enter four more values :" << endl;
    for(int i = 6; i <10; i++){
        cin >> *(temp+i);
    }
    arr = temp;
    delete [] temp;
    // displaying all ten values
    for(int i = 0; i < 10; i++){
        cout << *(arr+i) << " " ;
    }
    delete [] arr;
    return 0;

}