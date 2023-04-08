#include<iostream>
using namespace std;

int& increment(int &x){
    x++;
    return x;
}
int main(){
    int y = 9;
    int& res = increment(y);
    res++;
    cout << y << endl;  // increments y as well because of reference game
    return 0;
}