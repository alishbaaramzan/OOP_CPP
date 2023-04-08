#include<iostream>
using namespace std;

string ignoreSpaces(string a){
    int len = 0;
    for(int i = 0; i < 100; i++){
        if(a[i]=='\0'){
            break;
        }
        len++;
    }
    string temp;
    for(int i = 0; i < len; i++){
        if(a[i]==' '){
            continue;
        }
        if(!(a[i]>='a' && a[i]<='z') || !(a[i]>='A' && a[i]<='Z')){
            continue;
        }
        temp+=a[i];
    }
    return temp;
}
bool isPalindrome(string s, int start, int end){
    if(start==end){
        return true;
    }
    if(start>end){
        return true;
    }
    if(s[start]!=s[end]){
        return false;
    }
    return isPalindrome(s,start+1,end-1);
}
int main()
{
    string text;
    getline(cin,text);
    string new_s = ignoreSpaces(text);
    int len = 0;
    for(int i = 0; i < 100; i++){
        if(new_s[i]=='\0'){
            break;
        }
        len++;
    }
    //cout << new_s << " " << len << endl;
        if(isPalindrome(new_s,0,len-1)){
        cout << "yes"<< endl;
    }
    else
        cout << "no"<<endl;
    return 0;

}