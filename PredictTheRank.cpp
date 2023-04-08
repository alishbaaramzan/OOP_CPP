#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;

class Person{
    private:
    int ID;
    string name;
    float experience;
    static int count;

    public:
    Person(){}
    Person(const Person & p){
        this->name = p.name;
        this->ID = p.ID;
        this->experience = p.experience;
    }
    void getData(){
        cout << "Enter the ID: ";
        cin >> ID;
        cout << "Enter the name: ";
        cin >> name;
        cout << "Enter the experience in years :";
        cin >> experience;
        count++;
    }
    void display(){
        cout << ID;
        cout << setw(20) << name;
        cout << setw(20) << experience;
        cout << endl;
    }
    void rank(float m, float std){
        float v = m + (2 * std);
        if(experience>v){
            cout << "The rank of " << name << " with ID " << ID << " is Director"<< endl;
        }
        else if(experience<v){
            cout << "The rank of " << name << " with ID " << ID << " is Assistant Director"<< endl;
        }
    }

    float friend mean_calc(Person p[], int s);
    float friend std_calc(Person p[], int s, float m);
};

int Person :: count = 0 ; // static member initialization

float mean_calc(Person p[], int s){
    float sum = 0;
    for(int i = 0; i < s; i++){
        sum+=p[i].experience;
    }
    float mean = sum/s;
    return mean;
}

float std_calc(Person p[], int s, float m){
    float num = 0;
    for(int i = 0; i < s; i++){
        num += ((p[i].experience - m)*(p[i].experience - m));
    }
    num = sqrt(num);
    float std = num/s;
    return std;
}

int main()
{   int size = 2;
    Person *persons = new Person[100];
    cout << "Enter the data of first two employees: " << endl;
    for(int i = 0; i < size; i++){
        persons[i].getData();
    }
    char option;
    do{
        cout << "Do you want to add another empoyee(y/n): ";
        cin >> option;
        if(option=='y'){
            size++;
           persons[size-1].getData();
        }

    }while(option!='n');
    float mean = mean_calc(persons,size);
    float std = std_calc(persons,size,mean);

    //displaying data
    cout << "ID" << setw(20) << "NAME" << setw(20) << "EXPERIENCE"<< endl;
    for(int i = 0; i < size; i++){
        persons[i].display();
    }
    cout << "Total number of records are " << size << endl;
    cout << "Mean value is: " << mean << endl;
    cout << "Standard deviation is: " << std << endl;
    for(int i = 0; i < size; i++){
        persons[i].rank(mean,std);
    }
    delete [] persons;
    return 0;
}
