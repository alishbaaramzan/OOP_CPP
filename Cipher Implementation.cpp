// This program implements ciphers i.e. every alphabet is give a code
#include<iostream>
#include<string>
using namespace std;
// Thi function converts integer to binary string
void binary(int num, string &answer){
	if(num==1 || num==0){
		if(num==1){
			answer.append("1");
			return;
		}
		else if(num==0){
			answer.append("0");
			return;
		}
	}
	binary(num/2,answer);
	if(num%2==1){
		answer.append("1");
	}
	if(num%2==0){
		answer.append("0");
	}
	
}
// This function returns the encoding for any alphabet
string look(char ch){
	string answer = "";
	string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	for(int i = 0; i < 26; i++){
		if(ch==alpha[i]){
			binary(i,answer);
		}
	}
	int l = 0;
	int i = 0;
	while(answer[i]!='\0'){
		l++;
		i++;
	}
	
	string temp = "";
	for(int j = 0; j < 5-l; j++){
		temp+="0";
	}
	temp+=answer;
	return temp;
}
//This functions returns encodings for a given text
string cipher(string user){
	string ciphered= "";
	string temp;
	int len = 0;
	for(int i = 0; i < 100; i++){
		if(user[i]=='\0')
			break;
		len++;
	}
	for(int i = 0; i < len; i++){
		temp = "";
		if(user[i]==' '){
			temp+=" ";
			ciphered+=temp;
		}
		else{
		 temp = look(user[i]);
		 ciphered+=temp;
	}
	}
	return ciphered;
}
// This function decodes and returns an alphabet
char decode(string code){
	int temp = 0;
	int m = 16;
	for(int i = 0; i < 5; i++){
		if(code[i]=='1'){
			temp+=m*1;
		}
		m/=2;
	}
	string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	return alpha[temp];	
}
//This function decodes and returns the entire text
string decodedtext(string codedtext){
	int len = 0;
	for(int i = 0; i < 100; i++){
		if(codedtext[i]=='\0')
			break;
		len++;
	}
	string decoded_text = "";
	string temp = "";
	int i = 0;
	while(i < len){
		int n= 0;
		temp = "";
		while(n<5){
			temp+=codedtext[i];
			n++;
			i++;
		}
		decoded_text+=decode(temp);
			
	}
	return decoded_text;
}
int main(){
	// Converting a character to code
	char user;
	cout << "Enter a character: ";
	cin >> user;
	string encode = look(user);
	cout << "The code for the input character is: ";
	cout << encode << endl;
	// Converting a string to code
	string users;
	cout << endl << "Now enter a text without space: ";
	cin >> users;
	string encode_text = cipher(users);
	cout << "The encoded text is " << encode_text << endl;
	// Converting a text to code
	string user_text;
	cout << "\nNow enter some real text: ";
	getline(cin,user_text);
	cout << user_text << endl;
	string cryptic_text = cipher(user_text);
	cout << "The encoded text is " << cryptic_text << endl;
	// Decoding a character
	string code;
	cout << "Enter a code to decode for a character: ";
	cin >> code;
	cout << "The decoded form of "<< code  << " is " << decode(code) << endl;
	// Decoding a text
	string codetext;
	cout << "Enter the code for a text to decode: ";
	cin >> codetext;
	cout << "The decoded form of " << codetext << " is " << decodedtext(codetext) << endl;
	return 0;
	
}
