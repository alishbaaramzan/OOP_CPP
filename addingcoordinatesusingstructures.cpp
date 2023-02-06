#include<iostream>
using namespace std;

// making a structure to model a point in plane
struct point{
    int x;
    int y;
} P1, P2, P3;
int main(){
    // Taking input
    cout << "For co-ordinate 1:\n";
    cout << "x: ";
    cin >> P1.x;
    cout << "y: ";
    cin >> P1.y;
    cout << "For co-ordinate 2:\n";
    cout << "x: ";
    cin >> P2.x;
    cout << "y: ";
    cin >> P2.y;

    // Addinf the coordinates
    P3.x = P1.x + P2.x;
    P3.y = P1.y + P2.y;

    // Displaying result
    cout << "The sum of the co-ordinates is: (" << P3.x << "," << P3.y << ")" << endl;
    return 0; 
}