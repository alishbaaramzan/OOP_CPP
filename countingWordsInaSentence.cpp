#include<iostream>
using namespace std;

// declaring enum to check if the words has ended
enum itisWord{NO, YES};

int main(){
    // setting enum  variable to NO
    itisWord isWord  = NO;
    string sentence;
    int wordcount = 0;
    int i = 0;
    cout << "Enter a sentence: ";
    getline(cin,sentence);

    // looping over characters and increasing by one when space is met
    while(sentence[i]!='\0'){
        if(sentence[i]==' '){
            if(isWord== YES){
                wordcount++;
                isWord = NO;
            }
        }
        // keeing isWord NO when in the middle of the word
        else{
            if(isWord== NO)
                 isWord = YES;
        }
        i++;
    }

    // increasing wordcount for the very last word
    wordcount++;
    cout << "The number of words in the typed sentence are " << wordcount << endl;
    return 0;
}