#include<iostream>
using namespace std;

class Employee{
    private:
    int number;
    float compensation;
    public:
    // default constructor
    Employee(){}
    // functipon to get values
    void getValues(){
        cout << "Enter the number of employee: ";
        cin >> number;
        cout << "Enter the compensation for the employee " << number << ": ";
        cin >> compensation;
    }
    // function to display values
    void display(){
        cout << "Number: " << number << endl;
        cout << "Compensation: " << compensation << endl;
    }

};
int main()
{
    Employee employees[3];
    for(int i = 0; i < 3; i++){
        employees[i].getValues();
    }
    cout << "The data of employees is: " << endl;
    for(int i = 0; i < 3; i++){
        employees[i].display();
    }
    return 0;
}