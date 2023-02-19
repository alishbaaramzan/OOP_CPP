#include<iostream>
using namespace std;

class Piece{
    public:
    int player;
    int locationX;
    int locationY;
    bool isKing;

    void takeMove(){

    }

};

class Player{
    private:
    Piece pieces[12];

    void giveAttributes(int pl, int lx, int ly, bool kingno, int pieceno ){
        // giving attributes to individual pieces
        pieces[pieceno].player = pl;
        pieces[pieceno].locationX = lx;
        pieces[pieceno].locationY = ly;
        pieces[pieceno].isKing = kingno;
    }

    public:
    void setPieces(int x,char arr[8][8], int player){
        int pieceno = 0;
        char piececolour;
        if(player==1)
            piececolour = 'O';
        else if(player==2)
            piececolour = '0';
        // setting the twelve pieces on the checker board
        for(int i = x; i < x+3; i++){
            for(int j = 0; j < 8; j++){
                if(arr[i][j]=='D'){
                    if(x==0 || x==7){
                        arr[i][j] = piececolour;
                        giveAttributes(player,i,j,true,pieceno);
                    }
                    else{
                        arr[i][j] = piececolour;
                        giveAttributes(player,i,j,false, pieceno);
                    }
                    pieceno++;
                }
            }
        }
    } 

    
};
int main(){
    char checkerboard[8][8];
    int x = 0;

    // setting the light and dark squares
    for(int i = 0; i < 8; i++){
        if(i%2==0)
            x = 0;
        if(i%2==1)
            x = 1;
        for(int j = 0; j < 8; j++){
            if(j%2==x)
                checkerboard[i][j] = ' ';
            if(j%2!=x)
                checkerboard[i][j] = 'D';
        }
    }

    // Making two objects of the Player class as PLayer 1 and Player 2
    Player player1, player2;

    // setting pieces for player 1
    player1.setPieces(0,checkerboard,1);

    // setting pieces for player 2
    player2.setPieces(5,checkerboard,2);

    // Now displaying the ready checkerboard
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            cout << checkerboard[i][j] << " ";
        }
        cout << endl;
    }
    
}