#include<iostream>
using namespace std;
class Animal{
    protected:
    string name;
    int age ;
    public:
    Animal(){
        cout<<"\n Animal Default constructor called";
        name = "unknown";
        age = 00;
    }
    Animal(string nam, int y){
        cout<<"\n Animal Parametrized constructor called";
        name = nam;
        age = y;

    }
    virtual ~Animal(){
         cout<<"\n Animal Destructor called";

    }
    virtual void talk() = 0;
    virtual void display() {
        
        cout << "\n name = " << name;
        cout << "\n age = " << age;
    }

};
class Dog : public Animal{
    public:
    Dog(){
        cout << "\n dog constructor called ";
    }
    Dog(string n , int ys): Animal(n , ys){
        cout << "\n dog param constructor called ";
    }
    void display()override{
        Animal::display();
        
    }
    void talk() override {
        cout << "\n My Dog name is" <<name<<" and his age is"<< age<<" months ";
             
    }

};
class Cat : public Animal{
    public:
    Cat(){
        cout<<"\n Cat default constructor called";

    }
    Cat(string n, int ys) : Animal(n, ys) {
        cout << "\n Cat param constructor called";
    }
    void talk() override {
        cout << "\n My cat name is " << name << " & she is " << age << " month old";
    }
    bool operator==(const Cat& c) {
        return (this->name == c.name);
    }
    
    ~Cat(){
        cout<<"\n cat destructor called";
    }
    
    

};

int main()
{	
	// Animal *animal = new Animal();  //This line should give compile time error "Cant create object of abstract class" 
	
	//My Dog name is Boss & age is 15 months
	Animal *dogPtr = new Dog("Boss", 15);
	dogPtr->talk(); //Every animal has unique way of sound
	delete dogPtr;

	//My cat name is Puppy & she is 3 month old and it is-a Animal
	 Cat c1("Puppy", 3);
	 Cat c2("Sweety", 4);
     
	
	//Use strcmp function to to compare names of 2 Cat
	if(c1 == c2)  
		cout<<"Both are same!"<<endl;
	else
		cout<<"Both are different!"<<endl;
		
	c1.talk();
    return 0;
}