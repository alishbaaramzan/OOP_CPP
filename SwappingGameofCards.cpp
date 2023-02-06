#include<iostream>
#include<cstdlib> 
#include<ctime>
#include<string.h>
using namespace std;

// defining values for our suits
enum suit{SPADES,CLUBS,HEARTS,DIAMONDS};

// making a structure for a card
struct card{
    int number;
    string suit;
};
int main(){
    srand(time(NULL));
    card prize;
    card cards[3];

    // assigning random values to the cards
    for(int i = 0; i < 3; i++){
        int randn= rand()%10 + 1;
        int rands=rand()%4;
        if(rands==SPADES){
            cards[i].number=randn;
            cards[i].suit = "spades";
        }
        else if(rands==CLUBS){
            cards[i].number=randn;
            cards[i].suit = "clubs";
        }
        else if(rands==HEARTS){
            cards[i].number=randn;
            cards[i].suit = "hearts";
        }
        else if(rands==DIAMONDS){
            cards[i].number=randn;
            cards[i].suit = "diamonds";
        }
    }

    // displaying values stored in three cards
    for(int i = 0; i < 3; i++){
        cout << "Card " << i+1 << " is " << cards[i].number << " of " << cards[i].suit << endl;
    }
    cout << endl;

    // setting prize equal to card 1
    prize = cards[0];
    int winloc=1;

    // Now swapping the cards and tracking location of winning card if it gets swapped
    for(int i = 0; i < 3; i++){
        int randl1 = rand()%3 ;
        int randl2 = rand()%3 ;
        cout << cards[randl1].number << " of " << cards[randl1].suit << " has been swapped with ";
        cout << cards[randl2].number << " of " << cards[randl2].suit << endl;
        if(randl1==0){
            winloc = randl2+1;
        }
        else if (randl2==0){
            winloc = randl1+1;
        }
    }
    cout << endl;
    
    // Now asking user for the location of winning card
    int user;
    cout << "What is the location of " << prize.number << " of " << prize.suit << endl;
    cin>> user;

    // checking the input location with location of the prize
    if(user==winloc){
        cout << "You win!\n";
    }
    else 
        cout << "You lose\n";
    
    return 0;

}