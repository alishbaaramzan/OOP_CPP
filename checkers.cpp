#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

// This function displays the checkerboard when called
void displayBoard(char arr[8][8]){
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
class Piece{
    public:
    char type;
   // int player;
    int locationX;
    int locationY;
    bool isKing;

    void setAttributes(char colour,int i,int j,bool check){
         type = colour;
         locationX = i;
         locationY = j;
         isKing = check;
    }
    bool checkmoveisvalidhuman(char arr[8][8]){
        if(isKing){
            if(arr[locationX-1][locationY-1]=='D' || arr[locationX-1][locationY+1]=='D' || arr[locationX+1][locationY-1]=='D' || arr[locationX+1][locationY+1]=='D' )
                return true;
        }
        else if(arr[locationX-1][locationY-1]=='D' || arr[locationX-1][locationY+1]=='D' || (arr[locationX-1][locationY-1]!=type && arr[locationX-1][locationY-1]!=' ') || (arr[locationX-1][locationY+1]!=type && arr[locationX-1][locationY+1]!=' ')){
                return true;
            }
        else 
            return false;
    }
     bool checkmoveisvalidcomp(char arr[8][8]){
        if(isKing){
            if(arr[locationX-1][locationY-1]=='D' || arr[locationX-1][locationY+1]=='D' || arr[locationX+1][locationY-1]=='D' || arr[locationX+1][locationY+1]=='D' )
                return true;
        }
        else if(arr[locationX+1][locationY-1]=='D' || arr[locationX+1][locationY+1]=='D' || (arr[locationX+1][locationY-1]!=type && arr[locationX+1][locationY-1]!=' ') || (arr[locationX+1][locationY+1]!=type && arr[locationX+1][locationY-1]!=' ')){
                return true;
            }
        else
         return false;
    }
    bool checkForJump(char arr[8][8],int x, int y, char option, char dir){
        if(option=='h' && dir =='r'){
        if(arr[x][y]!='D' && arr[x][y]!=type && arr[x-1][y+1]=='D'){
            return true;
        }
        else
            return false;
        }
        else if(option=='h' && dir =='l'){
        if(arr[x][y]!='D' && arr[x][y]!=type && arr[x-1][y-1]=='D'){
            return true;
        }
        else
            return false;
        }
        else if(option=='c' && dir =='l'){
        if(arr[x][y]!='D' && arr[x][y]!=type && arr[x+1][y-1]=='D'){
            return true;
        }
        else
            return false;
        }
        else if(option=='c' && dir =='r'){
        if(arr[x][y]!='D' && arr[x][y]!=type && arr[x+1][y+1]=='D'){
            return true;
        }
        else
            return false;
        }       
}    
};

class Players{
    public:
        Piece *humanpieces = new Piece[12];
        Piece *computerpieces = new Piece[12];
        int compieces;
        int humpieces ;
        
    Players(){
        compieces = 12;
        humpieces = 12;
    }

    // deleting computer pieces
    void deletingpiecescomp(int x, int y){
        int index;
        for(int i = 0; i < compieces; i++ ){
            if(computerpieces[i].locationX==x && computerpieces[i].locationY==y){
                index = i;
                break;
            }
        }

        // now deleting the piece at the index location
        int n=0;
        Piece *temp = new Piece[12];
        for(int i = 0; i < compieces; i++){
            if(i==index)
                continue;
            *(temp+n)=*(computerpieces+i);
            n++;
        }
        compieces--;
        // now copying back into the list of computer pieces
         for(int i = 0; i < compieces; i++){
            *(computerpieces+i) = *(temp+i);
        }
        delete [] temp;
    }

    // deleting human pieces
     void deletingpieceshuman(int x, int y){
        int index;
        for(int i = 0; i < humpieces; i++ ){
            if(humanpieces[i].locationX==x && humanpieces[i].locationY==y){
                index = i;
                break;
            }
        }

        // now deleting the piece at the index location
        int n=0;
        Piece *temp = new Piece[12];
        for(int i = 0; i < humpieces; i++){
            if(i==index)
                continue;
            *(temp+n)=*(humanpieces+i);
            n++;
        }
        humpieces--;
        // now copying back into the list of computer pieces
         for(int i = 0; i < humpieces; i++){
            *(humanpieces+i) = *(temp+i);
        }
        delete [] temp;
    }

    // setting human pieces on the board
    void setHumanPieces(char arr[8][8], char colour){
        int pieceno = 0;
        
        
        // setting the twelve pieces on the checker board
        for(int i = 5; i < 8; i++){
            for(int j = 0; j < 8; j++){
                if(arr[i][j]=='D'){
                    arr[i][j] = colour;

                    humanpieces[pieceno].setAttributes(colour,i,j,false);
                    pieceno++;
                }
            }
        }
    } 
    // setting computer pieces on the board
    void setComputerPieces(char arr[8][8], char colour){
        int pieceno = 0;
        
        
        // setting the twelve pieces on the checker board
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 8; j++){
                if(arr[i][j]=='D'){
                    arr[i][j] = colour;

                    computerpieces[pieceno].setAttributes(colour,i,j,false);
                    pieceno++;
                }
            }
        }

    }

     void takeMoveHuman(char arr[8][8], char dir, int i){
        // checking for right forward move
        if((dir=='r' && arr[humanpieces[i].locationX-1][humanpieces[i].locationY+1] == 'D') || (dir=='r' && arr[humanpieces[i].locationX-1][humanpieces[i].locationY+1] == computerpieces[0].type)){
            // checking for jump
            if(humanpieces[i].checkForJump(arr,humanpieces[i].locationX-1,humanpieces[i].locationY+1,'h','r')){
                do{
                int x = humanpieces[i].locationX, y = humanpieces[i].locationY;
                cout << "One down!" << endl;
                // deleting computer piece at this location
                deletingpiecescomp(x-1,y+1);

                arr[x][y] = 'D';
                arr[x-1][y+1] ='D';
                arr[x-2][y+2] = humanpieces[i].type;
                humanpieces[i].locationX-=2;
                humanpieces[i].locationY+=2;
                }while(humanpieces[i].checkForJump(arr,humanpieces[i].locationX-1,humanpieces[i].locationY+1,'h','r'));
                
            }
            // if simple move is possible
            else{
                arr[humanpieces[i].locationX][humanpieces[i].locationY] = 'D';
                arr[humanpieces[i].locationX-1][humanpieces[i].locationY+1] = humanpieces[i].type;
                humanpieces[i].locationX--;
                humanpieces[i].locationY++;
                cout << "moved" << endl;
            }
        }

         // checking for left forward move
        else if((dir=='l' && arr[humanpieces[i].locationX-1][humanpieces[i].locationY-1] == 'D') || (dir=='l' && arr[humanpieces[i].locationX-1][humanpieces[i].locationY-1] == computerpieces[0].type)){
            // checking for jump
           if(humanpieces[i].checkForJump(arr,humanpieces[i].locationX-1,humanpieces[i].locationY-1,'h','l')){
                do{
                int x = humanpieces[i].locationX, y = humanpieces[i].locationY;
                cout << "One down!" << endl;
                // deleting computer piece at this location
                deletingpiecescomp(x-1,y-1);
                arr[x][y] = 'D';
                arr[x-1][y-1] ='D';
                arr[x-2][y-2] = humanpieces[i].type;
                humanpieces[i].locationX-=2;
                humanpieces[i].locationY-=2;
                }while(humanpieces[i].checkForJump(arr,humanpieces[i].locationX-1,humanpieces[i].locationY-1,'h','l'));
                
            }
                

            }
            // if simple move is possible
            else{
                arr[humanpieces[i].locationX][humanpieces[i].locationY] = 'D';
                arr[humanpieces[i].locationX-1][humanpieces[i].locationY-1] = humanpieces[i].type;
                humanpieces[i].locationX--;
                humanpieces[i].locationY--;
            }
        }

         void takeMoveComputer(char arr[8][8], char dir, int i){
        // checking for right forward move
        if(dir='r'){
            // checking for jump
            if(computerpieces[i].checkForJump(arr,computerpieces[i].locationX+1,computerpieces[i].locationY+1, 'c', 'r')){
                do{
                int x = computerpieces[i].locationX, y = computerpieces[i].locationY;
                cout << "One down!" << endl;
                // deleting human pieces
                deletingpieceshuman(x+1,y+1);

                arr[x][y] = 'D';
                arr[x+1][y+1] ='D';
                arr[x+2][y+2] = computerpieces[i].type;
                computerpieces[i].locationX+=2;
                computerpieces[i].locationY+=2;
                }while(humanpieces[i].checkForJump(arr,computerpieces[i].locationX+1,computerpieces[i].locationY+1,'c','r'));
                
            }
            // if simple move is possible
            else{
                arr[computerpieces[i].locationX][computerpieces[i].locationY] = 'D';
                arr[computerpieces[i].locationX+1][computerpieces[i].locationY+1] = computerpieces[i].type;
                computerpieces[i].locationX++;
                computerpieces[i].locationY++;
            }
        }

         // checking for left forward move
        else if(dir='l'){
            // checking for jump
           if(computerpieces[i].checkForJump(arr,computerpieces[i].locationX+1,computerpieces[i].locationY-1, 'c','l')){
                do{
                int x = computerpieces[i].locationX, y = computerpieces[i].locationY;
                cout << "One down!" << endl;
                // deleting human pieces
                deletingpieceshuman(x+1,y-1);
                
                arr[x][y] = 'D';
                arr[x+1][y-1] ='D';
                arr[x+2][y-2] = computerpieces[i].type;
                computerpieces[i].locationX+=2;
                computerpieces[i].locationY-=2;
                }while(computerpieces[i].checkForJump(arr,computerpieces[i].locationX+1,computerpieces[i].locationY-1,'c','r'));
                
            }
                

            }
            // if simple move is possible
            else{
                arr[computerpieces[i].locationX][computerpieces[i].locationY] = 'D';
                arr[computerpieces[i].locationX+1][computerpieces[i].locationY-1] = computerpieces[i].type;
                computerpieces[i].locationX++;
                computerpieces[i].locationY--;
            }
        }


};

class Game{
public:
Players p;
    
    // choose colours and set pieces
    void choosecolours(char arr[8][8]){
    // letting the user choose colour
    char colourp1, colourp2;
    cout << "Choose your colour:\nO\n0\n";
    cin >> colourp1;
    if(colourp1=='0') colourp2='O';
    else colourp2 = '0';
    p.setHumanPieces(arr,colourp1);
    p.setComputerPieces(arr,colourp2);
    }
    
    // this function is responsible for human's turn
    bool movehuman(char arr[8][8] ){
        // making sure the player has enough pieces to play
        if(p.humanpieces>0){
        
        bool check = false;
        // asking player 1 to enter the move
        do{
        int x, y;
        cout << "x: ";
        cin >> x;
        cout << "y: ";
        cin >> y;
        int index;
        // locating the index of the required piece in pieces array
        for(int i = 0; i < p.humpieces; i++){
            if(p.humanpieces[i].locationX==x && p.humanpieces[i].locationY==y){
                index = i;
            }
        }
        //Now checking if the required piece is eligible to move
        if(p.humanpieces[index].checkmoveisvalidhuman(arr)){
            char dir;
            cout << "Do you wanna move forward right or forward left\nType 'r' or 'l'\n";
            cin >> dir;

            // making the individual piece move i.e. calling the function from Piece class
            if(dir=='r'){
                p.takeMoveHuman(arr,'r',index);
                cout << "move has been taken" << endl;
            }
            else if(dir=='l'){
                p.takeMoveHuman(arr,'l',index);
            }
            check = false;
        }
        else{
            cout << "The piece can not move" << endl;
            check = true;
        }
        }while(check);
        return true;
        }
        else{
            cout << "Human is out of pieces" << endl;
            return false;
        }

    }
    
    // now making computer move
    bool movecomputer(char arr[8][8]){
        int index;
        int x,y;
        bool check = false;
        // making sure computer has enough pieces to move
        if(p.compieces>0){
        do{
        int index = rand()% p.compieces;
        cout << index << " has been selected" << endl;

         // Now checking if the required piece is eligible to move
        if(p.computerpieces[index].checkmoveisvalidcomp(arr)){
            check = false;
            cout << "the piece can move" << endl;
            int dir = rand()%2;
            if(dir==0 ){
                p.takeMoveComputer(arr,'r',index);
                cout << "computer moved" << endl;
            }
            else if(dir==1){
                p.takeMoveComputer(arr,'l',index);
                cout << "computer moved" << endl;
            }
            check = false;
        }
        else{
            check = true;
        }
        }while(check);
        return true;
        }
    else{
        cout << "Computer is out of pieces " << endl;
        return false;
    }
    }
};

// This function plays the game
void playgame(Game &game, char arr[8][8]){
    // starting the game by choosing colours
    cout << "choosing colours";
    game.choosecolours(arr);
    
    displayBoard(arr);

    bool check1=true, check2 = true; // check one for human move and two for computer move
    while(check1 && check2){
        check1 = game.movehuman(arr);
        if(check1) cout << "human has moved" << endl;
        check2 = game.movecomputer(arr); 
        if(check2) cout << "Computer has moved" << endl;

        displayBoard(arr);
    }
}
int main(){
    
    Game game;
    char checkerboard[8][8];
    int x = 0;
    srand(time(NULL));
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
    // calling function for playing the game
    playgame(game,checkerboard);
   
    return 0;
}