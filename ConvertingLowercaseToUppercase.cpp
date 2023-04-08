#include<iostream>
#include<cctype>
#include<string.h>

using namespace std;

int main(){
    // getting string from user
    const int MAX = 100;
    char *user_string = new char[MAX+1];
    cout << "Enter a string of upto " << MAX << "characters: " << endl;
    cin.getline(user_string, MAX+1);
    
    // calculating length of the string
    int len = 0;
    for(int i = 0; i < MAX+1; i++){
        if(*(user_string+i) == '\0')
            break;
        len++;
    }

    // converting lowercase to uppercase
    for(int i = 0; i < len; i++){
        user_string[i] = toupper(user_string[i]);
    }

    // displaying the new string
    cout << user_string << endl;
    delete [] user_string;
    return 0;
}