#include<iostream>
using namespace std;

class pnt {
    public:
    int x , y ;
    pnt(int x1 , int y1){
        cout<<"\n param constructor called";
        this->x = x1;
        this->y = y1;
    }
    void display(){
        cout<<"\n("<<x<<","<<y<<")";
    }
    ~pnt(){
        cout<<"\ndestructor called ";
    }

};
int main(){
    pnt p1(2,4), p2(5,7);
    p1.display();
    p2.display();
    
}