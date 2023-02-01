//This code removes punctuation marks from text
#include<iostream>
#include<string.h>
using namespace std;

string removePunctuationMarks(string text){
	string temp = "";
	int l= 0;
	for(int i = 0; i < 100; i++){
		if(text[i]=='\0'){
			break;
		}
		l++;
	}
	for(int i = 0; i < l; i++){
		if((text[i]>='A' && text[i]<='Z') || (text[i]>='a' && text[i]<='z')){
			temp+=text[i];
		}
	}
	return temp;
}
int main(){
	string text;
	cout << "Enter some text with punctuations: ";
	getline(cin,text);
	text = removePunctuationMarks(text);
	cout << "Text without punctuations is :\n" << text << endl;
	
}
