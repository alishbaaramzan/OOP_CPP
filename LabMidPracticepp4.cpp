#include<iostream>
using namespace std;

int compare(char* w1, char* w2){
    int len1 = 0;
    int len2 = 0;
    for(int i = 0; i < 100; i++){
        if(w1[i]=='\0')
            break;
        len1++;
    }
    for(int i = 0; i < 100; i++){
        if(w2[i]=='\0')
            break;
        len2++;
    }
    if(len1==len2){
        return 100;
    }
    else if(len1>len2){
        return 500;
    }
    else if(len1<len2){
        return 10;
    }
}
int main()
{
    char* word1 = new char[100];
    char* word2 = new char[100];
    cout << "Enter word 1 and 2: "<< endl;
    cin >> word1;
    cin >> word2;
    int res = compare(word1,word2);
    if(res==100){
        cout << "same" << endl;
    }
    else if(res==500){
        cout << "larger" << endl;
    }
    else if(res==10){
        cout << "smaller" << endl;
    }
    else
        cout << "smth is wrong"<< endl;
    delete [] word1;
    delete [] word2;
    return 0;
}