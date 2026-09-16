#include <iostream>
using namespace std;
class Base{
    int i ;
    public :
    Base(){
        cout<<"\n Base defalt constructor";
        i = 10;
    }
    Base(int n){
        cout<<"\n Base param constructor";
        i = n;
    }
    void display(){
        cout<<"\n i ="<<i;
    }
};
class Derived: public Base{
    int j ;
    Derived(){
        cout<<"\n derived default conmstructor called ";
        j = 20;

    }
    
    Derived(int n , int m){
        cout<<"\n derived default conmstructor called ";
        // i =n; error i is private in base
        j =m;
    }
    ~Derived(){
        cout<,"\n destructor is called";
    }
   
    
};
int main (){

    Base obj;
    obj.display();

    Derived obj1;
    
    return 0;
    
}