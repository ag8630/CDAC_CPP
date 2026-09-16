#include<iostream>
using namespace std;
class point{
    public:
    int x, y ;
    void set_point(int x1 , int y1){
        
        x = x1; y = y1;
        
    }
    void display(){
        cout<<"("<<x<<","<<y<<")";
    }
};
int main(){
    point p1,p2;
    p1.set_point(2,3);
    p2.set_point(5,6);
    p1.display();
    p2.display();
    return 0;
}