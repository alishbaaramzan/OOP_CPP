#include<iostream>
using namespace std;

class SavingsAccount{
    private:
    static float annualInterestRate;
    float savingsBalance;
    public:
    SavingsAccount(){}
    SavingsAccount(int savingsBalance){
        this->savingsBalance = savingsBalance;
    }
    void calculateMonthlyInterest(){
        float monthlyInterest = (savingsBalance * annualInterestRate)/12;
        this->savingsBalance+=monthlyInterest;
    }
    static void modifyInterestRate(int newValue);
    void printBalance(){
        cout << "Balance in your acc is " << savingsBalance << endl;
    }
};

float SavingsAccount :: annualInterestRate = 0;
void SavingsAccount :: modifyInterestRate(int newValue){
    annualInterestRate = newValue;
}
int main()
{
    SavingsAccount saver1(2000), saver2(3000);

    SavingsAccount :: modifyInterestRate(3);

    saver1.calculateMonthlyInterest();
    saver1.printBalance();

    saver2.calculateMonthlyInterest();
    saver2.printBalance();

    SavingsAccount :: modifyInterestRate(4);

    saver1.calculateMonthlyInterest();
    saver1.printBalance();

    saver2.calculateMonthlyInterest();
    saver2.printBalance();

    return 0;
}