#include<iostream>
using namespace std;
class Address{
    private:
    int houseno;
    int streetno;
    string city;

    public:
    Address(){
        this->houseno = 0;
        this->streetno = 0;
        this->city = "";
    }
    Address(int houseno, int streetno, string city){
        this->houseno = houseno;
        this->streetno = streetno;
        this->city = city;
    }

    void printAddress(){
        cout << "House no# " << houseno << endl;
        cout << "Street no# " << streetno << endl;
        cout << "City: " << city << endl;
    }
};

class Person{
    private:
    string name;
    long int CNIC;
    Address add;// creating strong association i.e. composition

    public:
    Person(string name, long int CNIC, Address add){
        this->name = name;
        this->CNIC = CNIC;
        this->add = add; 
    }

    void printData(){
        cout << "Name: " << name << endl;
        cout << "CNIC: " << CNIC << endl;
        add.printAddress();
     }

};
int main(){
    Address address(1,2,"Abbottabad");
    Person p1("Alishba",13101, address);

    cout << "The details are: " <<endl;
    p1.printData();
    return 0;
}