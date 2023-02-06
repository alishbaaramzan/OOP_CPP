#include<iostream>
using namespace std;
// making structure for phone number
struct phone{
    int areacode;
    int exchange;
    int number;
};
int main(){
    // Initializing a structure variable
    phone myNum = {212, 676, 8900};

    // asking user for values
    phone userNum;
    cout << "Enter your phone number:\n";
    cout << "Enter area code: ";
    cin >> userNum.areacode;
    cout << "Enter exchange number: ";
    cin >> userNum.exchange;
    cout << "Enter your number: ";
    cin >> userNum.number;
    
    // Displaying the values
    cout << "My number is : " << " (" << myNum.areacode << ") " << myNum.exchange << "-" << myNum.number << endl;
    cout << "Your number is : " << " (" << userNum.areacode << ") " << userNum.exchange << "-" << userNum.number << endl;
    return 0;
 }