#include<iostream>
using namespace std;

class Human;
class TicTacToe{
    private:
    int arr[3][3];
    public:
    TicTacToe(){
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                arr[i][j] = 0;
            }
        }
    }
    void printBoard(){
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }
    bool checkgame(){
        if((arr[0][0]==1 && arr[0][1]==1 && arr[0][2]==1) || (arr[0][0]==2 && arr[0][1]==2 && arr[0][2]==2)){
            return true;
        }
        else if((arr[1][0]==1 && arr[1][1]==1 && arr[1][2]==1) || (arr[1][0]==2 && arr[1][1]==2 && arr[1][2]==2)){
            return true;
        }
        else if((arr[2][0]==1 && arr[2][1]==1 && arr[2][2]==1) || (arr[2][0]==2 && arr[2][1]==2 && arr[2][2]==2)){
            return true;
        }
        else if((arr[0][0]==1 && arr[1][1]==1 && arr[2][2]==1) || (arr[0][0]==2 && arr[1][1]==2 && arr[2][2]==2)){
            return true;
        }
        else if((arr[0][2]==1 && arr[1][1]==1 && arr[2][0]==1) || (arr[0][2]==2 && arr[1][1]==2 && arr[2][0]==2)){
            return true;
        }
        else if((arr[0][0]==1 && arr[1][0]==1 && arr[2][0]==1) || (arr[0][0]==2 && arr[1][0]==2 && arr[2][0]==2)){
            return true;
        }
        if((arr[0][1]==1 && arr[1][1]==1 && arr[2][1]==1) || (arr[0][1]==2 && arr[1][1]==2 && arr[2][1]==2)){
            return true;
        }
        if((arr[0][2]==1 && arr[1][2]==1 && arr[2][2]==1) || (arr[0][2]==2 && arr[1][2]==2 && arr[2][2]==2)){
            return true;
        }
        else{
            return false;
        }

    }
    friend class Human;
};

class Human{
    public:
    void move(TicTacToe &board, int no){
        bool check = true;
        while(check){
        int r,c;
        cout << "Enter row: ";
        cin>> r;
        cout << "Enter column: ";
        cin >> c;
        if(board.arr[r-1][c-1]==0){
            board.arr[r-1][c-1]= no;
            check = false;
        }
        else
            cout << "Invalid move"<< endl;
        }
    }

};
int main()
{
    TicTacToe board1;
    Human p1,p2;
    bool check = true;
    board1.printBoard();
    cout << endl << endl;
    do{
        cout << "Player1 :"<< endl;
        p1.move(board1,1);
        board1.printBoard();
        if(board1.checkgame()){
            cout << "Player 1 wins" << endl;
            check = false;
            break;
        } 
        cout << "Player2 :"<< endl;
        p2.move(board1,2);
        board1.printBoard();
        if(board1.checkgame()){
            cout << "Player 2 wins" << endl;
            check = false;
            break;
        }
    }
    while(check);
}