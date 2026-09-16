#include <iostream>
using namespace std;

class mystring {
    // Member variables ko Class ke andar sabse upar likhna compulsory hai
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

    // 2. Parameterized Constructor (Ye missing tha aapke code me)
    mystring(const char *s) {
        cout << "\n Parameterized constructor called";
        len = 0;
        while (s[len] != '\0') {
            len++;
        }
        str = new char[len + 1];
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

    // Display Method
    void display() {
        cout << "\n String: " << str;
    }

    // Destructor
    ~mystring() {
        delete[] str;
    }
};

int main() {
    mystring obj1;                  // Default
    mystring obj2("infoway pune");  // Parameterized
    mystring obj3 = obj2;           // Copy Constructor Call Hua!

    obj2.display();
    obj3.display();

    return 0;
}