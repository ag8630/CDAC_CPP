#include<iostream>
using namespace std;
class date{
    int dd, mm ,yy;
     
    public:
    date(){
        cout<<"default one called";
    }
    ~date(){
        cout<<"\n" << "destructor called";
    }
    
    void set_date(int dd, int mm , int yy ){
        this->dd = dd; 
        this->mm = mm;
         this->yy =yy;

    }

    void get_date(){
        cout << "\n" << dd<< "/" << mm<< "/" << yy;
    }
    
};// compiler always use default constructor if not called.
int main(){
    int i;
    date d1;
    d1.set_date(15,9,2026);// actual param
    d1.get_date();

    return 0;

}