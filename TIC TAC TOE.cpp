#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

void userturn(char grid[5][5], char x, char y){
	if(x=='1' &&  y=='1'){
		grid[0][0]='X';
	}
	if(x=='1' &&  y=='2'){
		grid[0][2]='X';
	}
	if(x=='1' &&  y=='3'){
		grid[0][4]='X';
	}
	if(x=='2' &&  y=='1'){
		grid[2][0]='X';
	}
	
	if(x=='2' &&  y=='2'){
		grid[2][2]='X';
	}
	if(x=='2' &&  y=='3'){
		grid[2][4]='X';
	}
	if(x=='3' &&  y=='1'){
		grid[4][0]='X';
	}
	if(x=='3' &&  y=='2'){
		grid[4][2]='X';
	}
	if(x=='3' &&  y=='3'){
		grid[4][4]='X';
	}
}
 	

bool permit(char grid[5][5], int& draw){
	int temp = 0;
	for(int i = 0; i < 5; i+=2){
		for(int j = 0; j < 5; j+=2){
			if(grid[i][j]==' '){
				temp++;
				break; 
			}
		}
	}
	if(temp)
		return true;
	else{
		draw--;
		return false;
	}
	

}
void displaygrid(char grid[5][5]){
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 5; j++){
			cout << grid[i][j];
		}
		cout << endl;
	}
	cout << endl << endl;
}
bool checkcomputer(char grid[5][5]){
	if(grid[0][0]=='0' && grid[0][2]=='0' && grid[0][4]=='0' ){
		cout << "Computer wins!" << endl;
		return false;
	}
	if(grid[2][0]=='0' && grid[2][2]=='0' && grid[2][4]=='0' ){
		cout << "Computer wins!" << endl;
		return false;
	}
	if(grid[4][0]=='0' && grid[4][2]=='0' && grid[4][4]=='0' ){
		cout << "Computer wins!" << endl;
		return false;
	}
	if(grid[0][0]=='0' && grid[2][2]=='0' && grid[4][4]=='0' ){
		cout << "Computer wins!" << endl;
		return false;
	}
	if(grid[0][4]=='0' && grid[2][2]=='0' && grid[4][4]=='0' ){
		cout << "Computer wins!" << endl;
		return false;
	}
	if(grid[0][0]=='0' && grid[2][0]=='0' && grid[4][0]=='0' ){
		cout << "Computer wins!" << endl;
		return false;
	}
	if(grid[0][2]=='0' && grid[2][2]=='0' && grid[4][2]=='0' ){
		cout << "Computer wins!" << endl;
		return false;
	}
	if(grid[0][4]=='0' && grid[2][4]=='0' && grid[4][4]=='0' ){
		cout << "Computer wins!" << endl;
		return false;
	}
	else
		return true;
}
bool checkuser(char grid[5][5]){
	if(grid[0][0]=='X' && grid[0][2]=='X' && grid[0][4]=='X' ){
		cout << "User wins!" << endl;
		return false;
	}
	if(grid[2][0]=='X' && grid[2][2]=='X' && grid[2][4]=='X' ){
		cout << "User wins!" << endl;
		return false;
	}
	if(grid[4][0]=='X' && grid[4][2]=='X' && grid[4][4]=='X' ){
		cout << "User wins!" << endl;
		return false;
	}
	if(grid[0][0]=='X' && grid[2][2]=='X' && grid[4][4]=='X' ){
		cout << "User wins!" << endl;
		return false;
	}
	if(grid[0][4]=='X' && grid[2][2]=='X' && grid[4][0]=='X' ){
		cout << "User wins!" << endl;
		return false;
	}
	if(grid[0][0]=='X' && grid[2][0]=='X' && grid[4][0]=='X' ){
		cout << "User wins!" << endl;
		return false;
	}
	if(grid[0][2]=='X' && grid[2][2]=='X' && grid[4][2]=='X' ){
		cout << "User wins!" << endl;
		return false;
	}
	if(grid[4][0]=='X' && grid[4][2]=='X' && grid[4][4]=='X' ){
		cout << "User wins!" << endl;
		return false;
	}
	else
		return true;
}
bool aid_winning_move1(char grid[5][5], int n){
	int check = 0;
	for(int i = 0; i < 5; i+=2){
		if(grid[n][i]=='0') 
			check++;
		if(grid[n][i]=='X')
			check--;
	}
	if(check==2)
		return true;
	else
		return false;
}
bool aid_winning_move2(char grid[5][5], int n){
	int check = 0;
	for(int i = 0; i < 5; i++){
		if(grid[i][n]=='0') 
			check++;
		if(grid[i][n]=='X')
			check--;
	}
	if(check==2)
		return true;
	else
		return false;
}
bool aid_winning_move3(char grid[5][5]){
	int check = 0;
	int j = 0;
	for(int i = 0; i < 5; i+=2){
			if(grid[i][j]=='0')
				check++;
			if(grid[i][j]=='X')
			check--;
			j+=2;
	}
	if(check==2)
		return true;
	else
		return false;
}
bool aid_winning_move4(char grid[5][5]){
	int check = 0;
	int j = 4;
	for(int i = 0; i < 5; i+=2){
			if(grid[i][j]=='0')
				check++;
			if(grid[i][j]=='X')
			check--;
			j-=2;
	}

	if(check==2)
		return true;
	else
		return false;
}
bool winning_move(char grid[5][5]){
	int c = 0;
	if(aid_winning_move1(grid,0)){
		for(int i = 0; i < 5; i+=2)
			grid[0][i]='0';
			c++;
		}
	else if(aid_winning_move1(grid,2)){
		for(int i = 0; i < 5; i+=2)
			grid[2][i]='0';
			c++;
		}
	else if(aid_winning_move1(grid,4)){
		for(int i = 0; i < 5; i+=2)
			grid[4][i]='0';
			c++;
		}
	else if(aid_winning_move2(grid,0)){
		for(int i = 0; i < 5; i+=2)
			grid[i][0]='0';
			c++;
		}
	else if(aid_winning_move2(grid,2)){
		for(int i = 0; i < 5; i+=2)
			grid[i][2]='0';
			c++;
		}
	else if(aid_winning_move2(grid,4)){
		for(int i = 0; i < 5; i+=2)
			grid[i][4]='0';
			c++;
		}
	else if(aid_winning_move3(grid)){
		int j = 0;
		for(int i = 0; i < 5; i+=2){
				grid[i][j]='0';	
				c++;
				j+=2;
		}
}
	else if(aid_winning_move4(grid)){
		int j = 4;
		for(int i = 0; i < 5; i+=2){
				grid[i][j]='0';
				c++;
				j-=2;
		}
	if(c!=0) return true;
	else     return false;
		
}
}
bool block_user(char grid[5][5]){
	int c = 0;
	int turn = 0;
	if(turn == 0){
	for(int j = 0; j <= 4; j+=2){
	int check = 0;
	for(int i = 0; i <=4; i+=2){
		if(grid[j][i]=='X') check++;
		if(grid[j][i]=='0') check--;
	}
	if(check==2){
		for(int i = 0; i <= 4; i+=2){
			if(grid[j][i]==' '){
				grid[j][i]='0';
			}
		}
		c++;
		turn++;
	}
	
}
}
	
	if(turn==0){	
	for(int j = 0; j <= 4; j+=2){
	int check = 0;
	for(int i = 0; i <=4; i+=2){
		if(grid[i][j]=='X') check++;
		if(grid[i][j]=='0') check--;
	}
	if(check==2){
		for(int i = 0; i <= 4; i+=2){
			if(grid[i][j]==' '){
				grid[i][j]='0';
			}
		}
		c++;
		turn++;
	}
}
}	
	int checker = 0;
	if(turn==0){
	for(int i = 0; i <=4; i+=2){
		if(grid[i][i]=='X') checker++;
		if(grid[i][i]=='0') checker--;
		}
	if(checker==2){
	    for(int i = 0; i <=4; i+=2){
			if(grid[i][i]==' '){
				grid[i][i] = '0';
			}		
		}
		c++;
		turn++;
	}
}
	checker = 0;
	int j = 4;
	if(turn==0){
	for(int i = 0; i <=4; i+=2){
		if(grid[i][j]=='X') checker++;
		if(grid[i][j]=='0') checker--;
		j-=2;
		}
	if(checker==2){
	    for(int i = 0; i <=4; i+=2){
			if(grid[i][i]==' '){
				grid[i][i] = '0';
			}		
		}
		c++;
		turn++;
	}
}

	if(c!=0) return true;
	else     return false;
	

}
void computerturn(char grid[5][5]){
	
	cout << "Computer's turn!\n";
	if(winning_move(grid));
	else if(block_user(grid));
	else{
	while(true){
	int x = rand()%5;
	if(x%2!=0) x+=1;
	int y = rand()%5;
	if(x%2!=0) y+=1;
	if(grid[x][y] ==' '){
	grid[x][y]= '0';
	break;
	}
}
}
}
int main(){
	srand(time(NULL));
	char grid[5][5] = { {' ','|',' ','|',' '},
						{'-',' ','-',' ','-'},
						{' ','|',' ','|',' '},
						{'-',' ','-',' ','-'},
						{' ','|',' ','|',' '}
	};
	char userx, usery;
	int draw = 1;
	bool check1 = true, check2 = true;
	char border = 178;
	for(int i = 0; i < 120; i++){
		cout << border;
	}
	cout << endl;
	for(int i = 0; i < 50; i++){
		cout << " ";
	}
	cout << "TIC TAC TOE" << endl;
	for(int i = 0; i < 50; i++){
		cout << " ";
	}
	cout << "Game Begins!" << endl << endl;
	for(int i = 0; i < 40; i++){
		cout << " ";
	}
	cout << "Adhere to following rules" << endl;
	for(int i = 0; i < 40; i++){
		cout << " ";
	}
	cout << "1. Choose rows and columns from 1 to 3" << endl;
	for(int i = 0; i < 40; i++){
		cout << " ";
	}
	cout << "2. Do not enter the same position again" << endl;
	for(int i = 0; i < 40; i++){
		cout << " ";
	}
	cout << "ENJOY!" << endl << endl;
	for(int i = 0; i < 120; i++){
		cout << border;
	}
	cout << endl;
	
	
	while(permit(grid,draw) && check1 && check2){
		computerturn(grid);
		displaygrid(grid);
		check1 = checkcomputer(grid);
		if(check1 && permit(grid,draw)){
		cout << "User's turn!\nRow: " << endl;
		cin >> userx;
		cout << "Column: " << endl;
		cin >> usery;
		userturn(grid,userx, usery);
		displaygrid(grid); 	
	    check2 = checkuser(grid);
	}
}	
	if(draw!=1){
		cout << "It's a draw" << endl;
	}
	return 0;
	
	
}

/* to do
do not allow same step again
do not allow out of bound steps
add to aesthetics*/
