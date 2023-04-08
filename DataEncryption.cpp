#include"mymaths.h"
#include<iostream>
using namespace std;
#define EvenOdd(age) ((age%2==0) ? 0:1)

struct Student{
    char name[100];
    int age;
    int marks[5];
};
int main()
{
    Student s1;
    int size = 0;
    int * enc = new int[size];

    cout << "Enter student's name: ";
    cin >> s1.name;
    size++;
    enc[size-1] = len_string(s1.name);

    cout << "Enter your age: ";
    cin >> s1.age;
    size++;
    enc[size-1] = EvenOdd(s1.age);

    cout << "Enter marks of five subjects: ";
    for(int i = 0; i < 5; i++){
        cin >> s1.marks[i];
    }
    int min_v = min(s1.marks);
    int max_v = max(s1.marks);

    size++;
    enc[size-1]=min_v/10;
    size++;
    enc[size-1]=min_v%10;

    size++;
    enc[size-1]=max_v/10;
    size++;
    enc[size-1]=max_v%10;

    cout << "Encrypted code for " << s1.name << " is ";
    for(int i = 0 ; i < size; i++){
        cout << *(enc+i);
    }
    cout << endl;
    delete [] enc;
    return 0;
}