#include<iostream>
using namespace std;

class Time {
private:
    int hh;
    int mm;
    int ss;


public : 
    void set_time(int h,int m,int s){
        
        hh = h;
        mm = m;
        ss = s;
        
    }
    void display(){
        cout<<"\n"<<hh<<":"<<mm<<":"<<ss;
    }

    
};
int main(){
    Time t1, t2;
    t1.set_time(21,10,44);
    t1.display();
    t2.set_time(8,16,32);
    t2.display();
    return 0;

}
