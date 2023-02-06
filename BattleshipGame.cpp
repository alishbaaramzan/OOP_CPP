#include<iostream>
using namespace std;

// this structure stores indices where battleships are placed
struct battleship{
    int ships[5][2];
}S[5];

// This function checks if a battleship has been hit
bool check(int arr[5][2], int row, int col){
    int c = 0;
    for(int i = 0; i < 5; i++){
        if(arr[i][0]== row && arr[i][1]==col){
                c++;
        }
    }
    if(c!=0)
        return true;
    else
        return false;  
}

int main(){
    char maingrid[20][20];
    char battleground[20][20];
    int s = 0;
    int r;

    // initializing both the grides with '0' and displaying the maingrid 
    for(int i = 0; i < 20; i++){
        for(int j = 0; j < 20; j++){
            maingrid[i][j]='0';
            battleground[i][j]='0';
            cout << maingrid[i][j] << " ";
        }
        cout << endl;
    }

    // Now taking input for placing the battleships
    int n = 0;
    int row, col;
    char dir;
    cout << "Place the battleships: " << endl;
    while(n < 5){
        cout << "Battleship " << n+1 << ": " << endl;
        cout << "Vertical or horizontal (v/h)? "; 
        cin >> dir;
        if(dir=='v' || dir=='V'){
            cout << "Row: ";
            cin >> row;
            cout << "Column: ";
            cin >> col;
            int j = row;
            r = 0;
            for(int i = 0; i < 5; i++){
                battleground[j][col] = 'A';
                S[s].ships[r][0] = j;
                S[s].ships[r][1] = col;
                r++;
                j++;
             }
             s++;
        }
        else if(dir=='h' || dir=='H'){
            cout << "Row: ";
            cin >> row;
            cout << "Column: ";
            cin >> col;
            int j = col;
            r = 0;
            for(int i = 0; i < 5; i++){
                battleground[row][j] = 'A';
                S[s].ships[r][0] = row;
                S[s].ships[r][1] = j;
                r++;
                j++;
             }
             s++;
        }
        else{
            cout << "Invalid!" << endl;
            n--;
        }
        n++;
    }

    // Now displaying the main grid to begin the game
    cout << "The  battleground is yours to navigate!" << endl;
    for(int i = 0; i < 20; i++){
        for(int j = 0; j < 20; j++){
            cout << maingrid[i][j] << " ";
        }
        cout << endl;
    }

    // Now asking user to enter a row and a column
    // User gets 5 tries
    int tries = 0;
    int score = 0;
    int user_row;
    int user_col;
    while(tries<5){
        cout << "First missile!" << endl;
        cout << "Enter row: ";
        cin >> user_row;
        cout << "Enter column: ";
        cin >> user_col;
        if(check(S[0].ships, user_row, user_col)){
            cout << "Hit!" << endl;
            score++;
            for(int i = 0; i < 5; i++){
                battleground[S[0].ships[i][0]][S[0].ships[i][1]] = 'H';
            }
            for(int i = 0 ; i < 5; i++){
                S[0].ships[i][0] = 0;
                S[0].ships[i][1] = 0;
            }
        }
        else if(check(S[1].ships, user_row, user_col)){
            cout << "Hit!" << endl;
            score++;
            for(int i = 0; i < 5; i++){
                battleground[S[1].ships[i][0]][S[1].ships[i][1]] = 'H';
            }
            for(int i = 0 ; i < 5; i++){
                S[1].ships[i][0] = 0;
                S[1].ships[i][1] = 0;
            }
        }
        else if(check(S[2].ships, user_row, user_col)){
            cout << "Hit!" << endl;
            score++;
            for(int i = 0; i < 5; i++){
                battleground[S[2].ships[i][0]][S[2].ships[i][1]] = 'H';
            }
            for(int i = 0 ; i < 5; i++){
                S[2].ships[i][0] = 0;
                S[2].ships[i][1] = 0;
            }
        }
        else if(check(S[3].ships, user_row, user_col)){
            cout << "Hit!" << endl;
            score++;
            for(int i = 0; i < 5; i++){
                battleground[S[3].ships[i][0]][S[3].ships[i][1]] = 'H';
            }
            for(int i = 0 ; i < 5; i++){
                S[3].ships[i][0] = 0;
                S[3].ships[i][1] = 0;
            }
        }
        else if(check(S[4].ships, user_row, user_col)){
            cout << "Hit!" << endl;
            score++;
            for(int i = 0; i < 5; i++){
                battleground[S[4].ships[i][0]][S[4].ships[i][1]] = 'H';
            }
            for(int i = 0 ; i < 5; i++){
                S[4].ships[i][0] = 0;
                S[4].ships[i][1] = 0;
            }
        }
        else
            cout << "Miss" << endl;
        tries++;
    }

    // Now displaying the score along with hit and missed battleships
    for(int i = 0; i < 20; i++){
        for(int j = 0; j < 20; j++){
            cout << battleground[i][j] << " ";
        }
        cout << endl;
    }
    cout << "The score is " << score << endl;
    return 0;
}