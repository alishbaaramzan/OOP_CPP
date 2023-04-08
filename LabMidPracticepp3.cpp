#include<iostream>
using namespace std;

class Distance{
    private:
    int feet;
    int inches;
    public:
    void getDistance(){
        cout << "Enter feet: ";
        cin >> feet;
        cout << "Enter inches: ";
        cin >> inches;
    }
    void displayDistance(){
        cout << "The distance is "<< feet << "'-"<<inches << "\""<<endl;
    }
    Distance operator+(const Distance &d1){
        Distance temp;
        temp.feet = d1.feet + feet;
        temp.inches = d1.inches + inches;
        if(temp.inches>=12){
            while(temp.inches>=12){
                temp.feet++;
                temp.inches-=12;
            }
        }
        return temp;
    }
    bool operator<(const Distance &d){
        if(feet<=d.feet){
            return true;
        }
        if(feet==d.feet){
            if(inches<d.inches){
                return true;
            }
        }
        else
            return false;
    }
    void operator+=(const Distance &d){
        feet +=d.feet;
        inches +=d.inches;
        if(inches>=12){
            while(inches>=12){
                feet++;
                inches-=12;
            }
    }
    }

};

int main()
{
    Distance d1;
    d1.getDistance();
    Distance d2;
    d2.getDistance();
    Distance d3;
    d3 = d1+d2;
    cout << "Sum is";
    d3.displayDistance();
    if(d1<d2){
        cout<< "d1 is less than d2" << endl; 
    }
    d1+=d2;
    cout << "d1 after adding d2 to it is ";
    d1.displayDistance();
    return 0;
}