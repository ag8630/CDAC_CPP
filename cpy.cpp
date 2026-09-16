// add append function , which will concat the string parameter intp str add setstring and 
// getstring add + operator ovrloaded function 
// add charat(int ) function, returns char at position 
// 
// const char &operator[] (int index )
///{
//     return str [index];
// } 
    //int main() cout <<str[3];


#include<iostream>
#include<cstring> // strlen aur strcpy ke liye
using namespace std;

class mystring {
    char *str;
    int len;

public:
    // 1. Default Constructor
    mystring() {
        cout << "\n Default constructor called";
        len = 0;
        str = new char[1];
        str[0] = '\0';
    }

    // 2. Parameterized Constructor
    mystring(const char *s) {
        cout << "\n Parameterized constructor called";
        len = 0;
        while (s[len] != '\0') len++; // Correct length calculation

        str = new char[len + 1]; // Extra 1 byte for null character '\0'
        for (int i = 0; i < len; i++) {
            str[i] = s[i];
        }
        str[len] = '\0';
    }

    // 3. Copy Constructor (Deep Copy)
    mystring(const mystring &s) {
        cout << "\n Copy constructor called";
        len = s.len;
        str = new char[len + 1];
        for (int i = 0; i < len; i++) {
            str[i] = s.str[i];
        }
        str[len] = '\0';
    }

    // 4. Move Constructor
    mystring(mystring &&s) noexcept {
        cout << "\n Move constructor called";
        len = s.len;
        str = s.str;
        s.str = nullptr;
        s.len = 0;
    }

    // 5. Destructor
    ~mystring() {
        cout << "\n Destructor called";
        delete[] str; // C++ delete[] nullptr ko safely handle kar leta hai
    }

    // 6. Assignment Operator
    mystring &operator=(const mystring &s) {
        cout << "\n Assignment operator called";
        if (this == &s) return *this; // Self-assignment check

        delete[] str; // Purani memory release karo

        len = s.len;
        str = new char[len + 1];
        for (int i = 0; i < len; i++) {
            str[i] = s.str[i];
        }
        str[len] = '\0';

        return *this; // Reference return karna zaroori hai
    }

    void display() const {
        if (str) {
            cout << "\n Output: " << str;
        }
    }
};

int main() {
    cout << "main";
    mystring obj1;
    mystring obj2("infoway pune");

    obj2.display();

    cout << "\n";
    return 0;
}

