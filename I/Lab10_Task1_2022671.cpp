#include<iostream>
using namespace std;

class Shape{
    protected:
        float area;
        float volume;
    public:
        virtual void compute_area(){};
        virtual void compute_volume(){};
        virtual void display() = 0;
};

class Point : public Shape{
    protected:
        int x;
        int y;
    public:
        Point(){}
        Point(int x, int y){
            this->x = x;
            this->y = y;
        }
};

class Circle : public Point{
    protected:
        float radius;
    public:
        Circle(){}
        Circle(int x, int y, float radius) : Point(x,y){
            this->radius = radius;
        }

        void compute_area(){
            this->area = 3.14*radius*radius; // Area = pi * r^2
        }
        void display(){
            cout << "RADIUS OF CIRCLE " << radius << endl;
            cout << "POSITION IS x=" << x <<" y=" <<y << endl;
            cout << "AREA OF CIRCLE IS " << area << endl;
        }
};

class Cylinder : public Circle{
    protected:
        float height;
    public:
        Cylinder(){}
        Cylinder(int x, int y, float radius, float height) : Circle(x, y, radius){
            this->height = height;
        }

        void compute_area(){
            this->area = 2 * 3.14 * radius * height + 2 * 3.14 * radius * radius; // Area = 2*pi*r*h + 2*pi*r^2
        }
        void compute_volume(){
            this->volume = 3.14 * radius * radius * height; // Volume = pi * r^2 * h
        }
        void display(){
            cout << "HEIGHT OF CYLINDER " << height << endl;
            cout << "RADIUS OF CYLINDER " << radius << endl;
            cout << "POSITION IS x=" << x <<" y=" <<y << endl;
            cout << "AREA OF CYLINDER IS " << area << endl;
            cout << "VOLUME OF CYLINDER IS " << volume << endl;
        }

};
int main(){
    Shape *ptr;

     // Using the pointer for Cylinder class
    ptr = new Cylinder(34, 56, 2, 4);
    ptr->compute_area();
    ptr->compute_volume();
    ptr->display();

    // Using the pointer for circle
    ptr = new Circle(10, 5, 32);
    ptr->compute_area();
    ptr->display();

    delete ptr;
    return 0;   
}