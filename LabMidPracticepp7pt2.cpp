#include<iostream>
#include<cmath>
using namespace std;

class Vector;
class Point{
    private:
    float x,y,z;
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
    friend class Vector;
    friend Point movebyVector(const Point &p, const Vector &v);
};

class Vector{
    private:
    float x,y,z;
    float length;
    char direction;
    Point p;

    public:
    Vector(float a, float b, float c, char d) : p(a,b,c){
        length = sqrt((p.x*p.x)+(p.y*p.y)+(p.z*p.z));
        direction = d;
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
    }
    friend Point movebyVector(const Point &p, const Vector &v);
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
    Point p(2,1,0);
    Vector v(2,0,0,'x');
    Point p2 = movebyVector(p,v);
    p2.display();
    return 0;

}