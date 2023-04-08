#include<iostream>
using namespace std;

class String{
    char* string;
    int len;
    public:
    String(){
        string = new char[50];
    }
    String(char* s){
        string = s;
    }
    String(char* s, int l){
        string = s;
        len = l;
    }

    String operator+(const String &s){
        String temp;
        temp.string = string + s.string;
        return temp;
    }
    friend int string_size(const String &str);

    ~String(){
        delete [] string;
    }
};

int string_size(const String &string){
    int temp;
    for(int i = 0; i < 50; i++){
        if(string.string[i] == '\0')
            break;
        temp++;
    }
    return temp;
}
int main(){

}