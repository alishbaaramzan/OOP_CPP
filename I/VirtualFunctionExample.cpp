#include<iostream>
#include<cstring>
using namespace std;

class CWH{
    protected:
        string title;
        float rating;
    public:
    CWH(string s, float r){
        //strcpy(title,s);
        title = s;
        rating = r;
    }
    virtual void display(){}
};

class Video : public CWH{
    float vid_len;
    public:
    Video(string s, float r, float l) : CWH(s,r){
        vid_len = l;
    }
    void display(){
        cout << "Title: " << title << endl;
        cout << "Rating: " << rating << endl;
        cout << "Video length: " << vid_len <<" minutes " <<  endl;
    }
};

class Website : public CWH{
    int words;
    public:
    Website(string s, float r, int l) : CWH(s,r){
        words = l;
    }
     void display(){
        cout << "Title: " << title << endl;
        cout << "Rating: " << rating << endl;
        cout << "Word count: " << words <<" words " <<  endl;
    }
};

int main(){
    string title;
    float rating, v_length;
    int words;
    
    // for video
    title = "CPP Tutorial";
    v_length = 15;
    rating = 4.5;
    Video cpp_v(title, rating, v_length);
    //cpp_v.display();
    

    // for text
    title = "CPP Tutorial Text";
    rating = 4.5;
    words = 250;
    Website cpp_t(title, rating, words);
    //cpp_t.display();

    CWH * tuts[2];
    tuts[0] = &cpp_v;
    tuts[1] = &cpp_t;

    tuts[0]->display();
    tuts[1]->display();

    return 0;
}