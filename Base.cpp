#include<iostream>
using namespace std ;
class Base{
    public:
     virtual void fun() { 
         cout<<"\n Base fun()";
    }
    Base(){
        cout<<"\n BAse constructor";
    }
    virtual ~Base(){
        cout<<"\n base destructor";

    }
};
class Derived: public Base{
    public:
    void fun(){
        cout<<"\n Derived fun()";

    }
    Derived(){
        cout<<"\n derived constructor";
    }
    ~Derived(){
        cout<<"\n derived destructor";

    }
};
int main(){
    // Base obj1;
    // obj1.fun();
    // Derived obj2;
    // obj2.fun();

    // Base *bptr = new Base();
    // bptr ->fun();
    // Derived *dptr = new Derived();
    // dptr->fun(); 
    // Base *bptr1 = new Derived(); // base class pointer can hold its derived class object 
    // bptr1->fun();
    // Base *obj = new Derived();
    // obj-> fun();
    // Base *ptr = new Base();
    // delete ptr;
    Base *ptr = new Derived();
    delete ptr;

    return 0;
}