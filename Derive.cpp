#include <iostream>
#include <string>
using namespace std;

class person {
protected:
    int id;
    string name;

public:
    person() {
        cout << "\n person constr called ";
        id = 9999;
        name = "unknown";
    }
    person(int i, string s) {
        cout << "\n person constr param called ";
        id = i;
        name = s;
    }
    virtual ~person() { // Virtual destructor for safe polymorphic cleanup
        cout << "\n person dstructor";
    }
    virtual void talk() = 0;
    virtual void display() {
        cout << "\n id = " << id;
        cout << "\n name = " << name;
    }
};

class emp : public person {
protected:
    string dept;
    float bsal;

public:
    emp() {
        cout << "\n emp constructor";
        dept = "unknown";
        bsal = 0.0f;
    }
    // Fixed typo: striong -> string
    emp(int i, string nm, string d, float s) : person(i, nm) {
        cout << "\n emp param constructor";
        dept = d;
        bsal = s;
    }
    ~emp() override {}

    void display() override {
        person::display(); // Call base display
        cout << "\n Department = " << dept;
        cout << "\n basic salary = " << bsal;
    }
    virtual float cal_sal() = 0;
};

class manager : public emp {
protected:
    float allowance;

public:
    manager() {
        cout << "\n manager constructor";
        allowance = 0.0f;
    }
    // Fixed parameter mismatch: changed 'nm' to 'name'
    manager(int i, string name, string d, float b, float a) : emp(i, name, d, b) {
        cout << "\n manager param constructor";
        allowance = a;
    }
    ~manager() override {
        cout << "\n destructor manager";
    }
    void display() override {
        emp::display(); // Call base display
        cout << "\n allowance = " << allowance;
    }
};

class sales_manager : public manager {
protected:
    int total_sales;

public:
    sales_manager() {
        cout << "\n sales manager constructor";
        total_sales = 0;
    }
    sales_manager(int i, string nm, string d, float bs, float al, int sales) 
        : manager(i, nm, d, bs, al) {
        cout << "\n sales manager param constructor";
        total_sales = sales;
    }
    ~sales_manager() override {
        cout << "\n sales manager destructor";
    }
    void display() override {
        manager::display();
        cout << "\n total sales = " << total_sales;
    }
    float cal_sal() override {
        if (total_sales > 5000)
            return bsal + allowance + 7000;
        else if (total_sales > 3000)
            return bsal + allowance + 5000;
        else
            return bsal + allowance + 3000;
    }
    void talk() override {
        cout << "\n I am sales manager.. my name is " << name 
             << "\n I have made total sales in this month " << total_sales;
    }
};



int main() {
    // sales_manager obj(12, "pooja", "sales", 50000.00f, 7500.0f, 4500);
    // obj.talk();
    // cout << "\n\n--- Employee Details ---";
    // obj.display();
    // cout << "\n Total Salary = " << obj.cal_sal() << "\n";
    emp *p = new sales_manager(12, "pooja", "sales", 50000.00f,7000,4500);// does not create object becuse manager dont have cal salary implementattion 
    cout<<"\n Total sal = "<< p->cal_sal();
    delete p;
    return 0;
}