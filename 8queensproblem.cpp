#include<iostream>
#include <cstdlib>
#include <ctime>
#define ROW 8
#define COLUMN 8
using namespace std;
char queen = 'Q';
int count = 0;
// function to mark the attacking positions
void IdentifyingAttackPoints(bool arr[][COLUMN], int row, int col){
    arr[row][col] = false;
    int r = row;
    int c = col;
    // making all the horizonatl positions unallowed
    while(r>=0){
        arr[r][col] = false;
        r--;
    }
    r = row;
    while(r<8){
        arr[r][col] = false;
        r++;
    }
    // making all vertical positions unallowed
    while(c>=0){
        arr[row][c] = false;
        c--;
    }
    c = col;
    while(c<8){
        arr[row][c] = false;
        c++;
    }
    // making the principal diagonal positions unallowed
    r = row;
    c = col;
    while(r>=0 && c>=0){
        arr[r][c] = false;
        r--;
        c--;
    }
    r = row;
    c = col;
    while(r<8 && c<8){
        arr[r][c] = false;
        r++;
        c++;
    }
    // making the secondary diagonal positions unallowed
    r = row;
    c = col;
    while(r>=0 && c<8){
        arr[r][c] = false;
        r--;
        c++;
    }
    r = row;
    c = col;
    while(r<8 && c>=0){
        arr[r][c] = false;
        r++;
        c--;
    }
}
bool traverseboard(char arr[][COLUMN], bool check[][COLUMN], int row, int col){
    if(count==8){
        cout << "8 done" << endl;
        return true;
    }
    if(col==8 || col==-1){
        cout << "cols done" << endl;
        return false;
    }
    if(row==8 || row==-1){
        cout << "rows done" << endl;
        return false;
    }
    if(check[row][col]){
        IdentifyingAttackPoints(check,row,col);
        arr[row][col] = queen;
        count++;
    }
    if((traverseboard(arr,check,row,col+1))){
        return true;
    }
    if((traverseboard(arr,check,row,col-1))){
        return true;
    }
    if((traverseboard(arr,check,row+1,col))){
        return true;
    }
    if((traverseboard(arr,check,row-1,col))){
        return true;
    }
    return false;

}
void driver_func(char arr[][COLUMN]){
    // a new array to keep track of allowed locations i.e boxes
    bool check[ROW][COLUMN];

    //making all boxes eligible to end up at
    for(int i= 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            check[i][j] = true;
        }
    }
    // sending our chessboard to traverse function for placing the queens
    cout << "driver runs" << endl;
    traverseboard(arr, check, 0, 0);
    cout << "driver came back" << endl;
}
int main(){
    char chess_board[ROW][COLUMN];
    srand(time(NULL));
    int x = rand()%8;
    
    // Initializing our chess board to zero
    for(int i = 0; i <8; i++){
        for(int j = 0; j < 8; j++){
            chess_board[i][j] = '0';
        }
    }
    driver_func(chess_board);

    // printing chessboard
    for(int i = 0; i < ROW; i++){
        for(int j = 0; j < COLUMN; j++){
            cout << chess_board[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}