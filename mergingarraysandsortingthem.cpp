#include<iostream>
using namespace std;

// structure to store both the value and it's position (either from array 1 or 2)
struct array{
    int value;
    string position;
};
int main(){
    int n;

    // Allocating dynamic memory
    int *arr1 = new int[n];
    int *arr2 = new int[n];
    cout << "Enter size of arrays: ";
    cin >> n;
    array arr3[n+n];

    // Taking input in array 1
    cout << "Enter the elements of first array: " << endl;
    for(int i = 0; i < n; i++){
        cin >> arr1[i];
    }

    // Taking input in array 2
    cout << "Enter the elements of second array: " << endl;
    for(int i = 0; i < n; i++){
        cin >> arr2[i];
    }

    // Merging the two arrays in the structure arr3
    int s = 0;
    for(int i = 0; i < n ; i++){
        arr3[s].value=arr1[i];
        arr3[s].position=" array 1";
        s++;
        arr3[s].value=arr2[i];
        arr3[s].position=" array 2";
        s++;
    }

    // Bubble sorting the array
    for(int i = 0; i < s-1; i++){
        for(int j = 0; j < s-i; j++){
            if(arr3[j].value > arr3[j+1].value){
                array temp;
                temp.value = arr3[j].value;
                temp.position = arr3[j].position;

                arr3[j].value = arr3[j+1].value;
                arr3[j].position = arr3[j+1].position;

                arr3[j+1].value = temp.value;
                arr3[j+1].position = temp.position;
            }
        }
    }

    // Displaying the sorted array arr3
    cout << "Now the merged and sorted array is " << endl;
    for(int i = 0; i < s; i++){
        cout << arr3[i].value << " ";
    }
    cout << endl;

    // Displaying the position of each element
    cout << "Now the position of elements of the sorted array is " << endl;
    for(int i = 0; i < s; i++){
        cout << arr3[i].value << " -> " << arr3[i].position << endl;
    }

    // De allocating memory
    delete [] arr1;
    arr1 = NULL;
    delete [] arr2;
    arr2 = NULL;
    return 0;
}