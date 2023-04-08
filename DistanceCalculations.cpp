#include <iostream>
#include <cmath>
using namespace std;
 
class Point{
    public : 
    //methods
    Point(){};
    Point(double x, double y){
        m_x = x; 
        m_y = y;
    }
    double distance_to( Point target){
        return sqrt(pow(target.m_x - m_x, 2) + pow(target.m_y - m_y, 2));
    }
    void print_info(){
        std::cout << "Point [ x : " << m_x << ", y: " << m_y << "]" << std::endl;
    }
    //member variables
    private : 
    double m_x;
    double m_y;
};
 
int main()
{
    Point p1(1,1); // giving values to the data mambers using constructor
    Point p2(2,2);
    p1.print_info();
    p2.print_info();
    float distance = p1.distance_to(p2);//calculating the distance between the two points
    cout << "Distance is " << distance << endl;
    return 0;
}