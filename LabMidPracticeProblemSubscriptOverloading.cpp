#include<iostream>
# define SIZE 5
using namespace std;

class ClassofArrays{
    int arr[SIZE];
    public:
    void getValues(){
        cout << "Enter " << SIZE << " values: "  << endl;
        for(int i = 0; i < SIZE ; i++){
            cin >> arr[i];
        }
    }
    int &operator[](int i){
        if(i<SIZE){
            return arr[i];
        }
        else{
            cout << "Out of bounds";
            return arr[0];
        }
    }

};
int main()
{
    ClassofArrays c1;
    c1.getValues();
    cout << "second index location: " << c1[2] << endl;
    cout << "tenth index location: " << c1[10] << endl;
    return 0;
}