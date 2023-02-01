// This code removes stop words from the text
#include<iostream>
using namespace std;

string removeStopWords(string text, string sw[], int s){
	int l = 0;
	for(int i = 0; i< 100; i++){
		if(text[i]=='\0')
			break;
		l++;
	}
	string w_swds = "";
	for(int i = 0; i < l; i++){
		string temp = "";
		while(text[i]!=' ' && text[i]!='\0'){
			temp+=text[i];
			i++;
		}
		int c = 0;
		for(int j = 0; j < s; j++){
			if(sw[j]==temp)
				c++;
		}
		if(c==0){
			w_swds+=temp;
			w_swds+=" ";
		}
	}
	return w_swds;
}
int main(){
	string text;
	int n;
	cout << "Enter text: ";
	getline(cin,text);
	cout << "How many stop words?";
	cin >> n;
	string stopwords[n];
	for(int i = 0; i < n; i++){
		cin >> stopwords[i];
	}
	string new_text = removeStopWords(text, stopwords, n);
	cout << "New text without the stopwords is: ";
	cout << new_text << endl;
	return 0;
	
}
