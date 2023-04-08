#include<iostream>
using namespace std;

class Officer{
    private:
    string name;
    int ID;
    string rank;
    bool status;
    public:
    int returnID(){
        return ID;
    }
    bool returnstatus(){
        return status;
    }
    void getData(){
        cout << "Name: ";
        cin >> name;
        cout << "ID: ";
        cin >> ID;
        cout << "Rank: ";
        cin >> rank;
        int sum = 0;
        while(ID!=0){
            sum+=ID%10;
            ID/=10;
        }
        if((sum*sum)%2==0){
            status = true;
        }
        else 
            status = false;

    }
};

class Security{
    private:
    Officer *officers = new Officer[100];
    static int number_of_officers;
    public:
    void menu(){
        cout << "Welcome to Security Protocol" <<endl
        <<"Please select from the menu" << endl
        << "1. Enter an officer record" << endl
        << "2. Check number of officers"<<endl
        << "3. Check the status of an officer"<<endl
        << "4. Exit"<<endl;

    }
    void drivercode(){
        int x = 0;
        do{
            menu();
            cin>>x;
            if(x==1){
                officers[number_of_officers].getData();
                number_of_officers++;
            }
            if(x==2){
                cout << number_of_officers << endl;
            }
            if(x==3){
                int id;
                cout << "Enter ID: ";
                cin >> id;
                int index = 0;
                for(int i = 0; i < number_of_officers; i++){
                    if(id==officers[i].returnID()){
                        index = i;
                    }
                }
                if(officers[index].returnstatus()){
                    cout << "Allowed" << endl;
                }
                else
                    cout << "Not allowed" << endl;
            }
            if(x==4){
                delete [] officers;
            }
        }while(x!=4);
    }
};

int Security :: number_of_officers = 0;

int main()
{
    Security security;
    security.drivercode();
    return 0;
}