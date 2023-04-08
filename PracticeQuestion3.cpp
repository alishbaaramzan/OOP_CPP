#include<iostream>
using namespace std;

class HugeInteger{
    private:
    int arr[40];
    public:
    HugeInteger(){}

    void input(){
        cout << "Enter 40 digits: ";
        for(int i = 0; i < 40; i++){
            cin >> arr[i];
        }
    }
    void output(){
        cout << "The 40 digits are: ";
        for(int i = 0; i < 40; i++){
            cout <<  arr[i];
        }
        cout << endl;
    }
    HugeInteger operator+(HugeInteger &h){
        HugeInteger temp;
        for(int i = 0; i < 40; i++){
            temp.arr[i]  = arr[i] + h.arr[i];
        }
        return temp;
    }
     HugeInteger operator-(HugeInteger &h){
        HugeInteger temp;
        for(int i = 0; i < 40; i++){
            temp.arr[i]  = arr[i] - h.arr[i];
        }
        return temp;
    }

    bool operator>=(HugeInteger &h){
        int check = true;
        for(int i = 0; i < 40; i++){
            if(arr[i]<h.arr[i]){
                check = false;
            }
        }
        return check;
    }
    bool operator<=(HugeInteger &h){
        int check = true;
        for(int i = 0; i < 40; i++){
            if(arr[i]>h.arr[i]){
                check = false;
            }
        }
        return check;
    }
    bool operator==(HugeInteger &h){
        int check = true;
        for(int i = 0; i < 40; i++){
            if(arr[i]!=h.arr[i]){
                check = false;
            }
        }
        return check;
    }

};
int main()
{
    HugeInteger h1, h2;
    h1.input();
    h2.input();
    HugeInteger h3 = h1+h2;
    h3.output();
    HugeInteger h4 = h1-h2;
    h4.output();
    if(h1>=h2){
        cout << "Greater than or equal to " << endl;
    }
    if(h1<=h2){
        cout << "Less than or equal to " << endl;
    }
    if(h1==h2){
        cout << "equal to " << endl;
    }
    return 0;
}