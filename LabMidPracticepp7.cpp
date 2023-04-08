#include<iostream>
#include<cmath>
using namespace std;

class Vector;
class Point{
    private:
    float x,y,z;
    friend Point movebyVector(const Point &p, const Vector &v);

    public:
    Point(){}
    Point(float x, float y, float z){
        this->x = x;
        this->y = y;
        this->z = z;
    }
    void display(){
        cout << "(" << x <<"," << y << "," << z <<")" << endl;
    }
};

class Vector{
    private:
    float length;
    char direction;
    float x, y, z;
    friend Point movebyVector(const Point &p, const Vector &v);
    public:
    Vector(){
        float a,b,c;
        cout << "Enter the coordinates of x, y, z: ";
        cin >> a >> b >> c;
        length = sqrt((a*a)+(b*b)+(c*c));
         cout << length << endl;
        cout << "Enter the direction: ";
        cin >> direction;
        if(direction=='x'){
            x = length;
            y = 0;
            z = 0;
        }
        else if(direction=='y'){
           x = 0;
           y = length;
           z = 0;
        }
        else if(direction=='z'){
            x = 0;
            y = 0;
            z = length;
        }
        cout << x << " " << y << " " << z << endl;
    }
 };
Point movebyVector(const Point &p1, const Vector &v1){
    Point temp;
    temp.x = p1.x + v1.x;
    temp.y = p1.y + v1.y;
    temp.z = p1.z + v1.z;
    return temp;
}
int main()
{
    Point p1(2,1,0);
    Vector v1;
    Point p2 = movebyVector(p1,v1);
    p2.display();
    return 0;
}