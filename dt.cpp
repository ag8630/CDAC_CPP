#include<iostream>
using namespace std;
class date{
    public:
    int dd ,  mm ,  yy ; 
    

    date (int d , int m , int y ){
        cout<<"\n param constructor called";
        this->dd = d ;
        this->mm = m ; 
        this->yy = y ;
        cout<<"\n date = "<< d<<"/"<<m<<"/"<<y;


    }
    ~date(){
        cout<<"\ndestructor called ";
    }
    


};
int main(){
    date d1(12,12,12) , d2(26,5,2026) ; 
    return 0;
    
}