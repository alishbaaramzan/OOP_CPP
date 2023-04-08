#include<iostream>
using namespace std;

class Class{
    static int x;
    int y;
    public:
    void getter(int y){
        this->y = y;
        x++;
    }
    static int play(Class arr[]){
        int i;
        cout << "Enter your index: ";
        cin >> i;
        if(i==0){
            cout << " Your value is " << arr[0].y;
        }
        else if(i==1){
            cout << "Your value is " << arr[1].y;
        }
        cout << endl;
    }
};

int Class :: x = 0;
int main(){
    Class *arr = new Class[2];
    arr[0].getter(1);
    arr[1].getter(2);
    // arr[0].play(arr);  -> possible
    Class :: play(arr);
    delete [] arr;
    return 0;
}