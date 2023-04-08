// Defining two macros in one line is not possible
#include<iostream>
//#define ROWS 5, COL 6 -> error
#define ROWS 5
#define COL 6

using namespace std;

int main(){
    cout << "Rows: " << ROWS << endl;
    cout << "Columns: " << COL << endl;
    return 0;
}