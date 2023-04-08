#include<iostream>
using namespace std;

class Coordinator;
class Person{
    private:
    string competition;
    string institute;

    public:
    void getData(){
        cout << "Enter competition and university name: ";
        cin >>competition >> institute;
    }
    friend class Coordinator;

};

class Coordinator{
    public:
    void roomnumber(Person &p, Person &q);
};

void Coordinator :: roomnumber(Person &p, Person &q){
    bool check = false;
    if(p.institute==q.institute){
        check = true;
        int nchar1 = 0;
        for(int i = 0; i < 100; i++){
            if(p.competition[i]=='\0')
                break;
            nchar1++;
        }
        int nchar2 = 0;
        for(int i = 0; i < 100; i++){
            if(q.competition[i]=='\0')
                break;
            nchar2++;
        }
        if(check){
            cout << "Person 1 and 2 are roomies in room ";
            if(nchar1>nchar2) cout << nchar1 << endl;
            else cout << nchar2 << endl;
        }
        else
         cout << "Person 1 and 2 are not roomies" << endl;
    }
}
int main()
{
    Person p1,p2;
    p1.getData();
    p2.getData();
    Coordinator c;
    c.roomnumber(p1,p2);
    return 0;
}