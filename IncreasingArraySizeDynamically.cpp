#include<iostream>
using namespace std;

int main(){
    // Taking minimum and maximum size for the array
    int min_size;
    int max_size;
    cout << "Enter minimum size of the array: ";
    cin >> min_size;
    cout << "Enter maximum size of the array: ";
    cin >> max_size;

    // Making a dynamic array of minimum size
    int* arr1 = new int[min_size];
    //Taking values in the array
    cout << "Enter " << min_size << " values:\n";
    for(int i = 0; i < min_size; i++){
        cin >> *(arr1+i);
    }

    // Making a dynamic array of maximum size
    int* arr2 = new int[max_size];

    // copying members of minimum array in the max array
    for(int i = 0; i < min_size; i++){
        *(arr2+i) = *(arr1+i);
    }
    // deallocating memory of the first array
    delete [] arr1;
 
    // Now asking the user for remaining values
    cout << "Enter " << max_size - min_size << " more values:\n";
    for(int i = min_size; i < max_size; i++){
        cin >> *(arr2 + i);
    }

    //Printing all the elements of the new array
    for(int i = 0; i < max_size; i++){
        cout << *(arr2+i) << " ";
    }

    //deallocating memory of the second array
    delete [] arr2;
    return 0;
}