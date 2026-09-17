#include <iostream>
using namespace std;

class MyBuffer {
    int *data;
    int size;

public:
    // Parameterized Constructor
    MyBuffer(int s) {
        size = s;
        data = new int[size];
        for (int i = 0; i < size; i++) {
            data[i] = (i + 1) * 10; // 10, 20, 30... fill kar rahe hain
        }
    }

    // --- AAPKO YAHAN ASSIGNMENT OPERATOR LIKHNA HAI ---
    MyBuffer& operator=(const MyBuffer &ref) {
        
        // Step 1: Self assignment check
        if(this == &ref){
            return *this;
        }
        delete [] data;
        size = ref.size;
        data = new int[size];
    for (int i = 0; i < size; i++) {
        data[i] = ref.data[i];
    }
    
        return *this;
    }

    // Display
    void display() {
        if (data != nullptr) {
            for (int i = 0; i < size; i++) cout << data[i] << " ";
            cout << endl;
        } else {
            cout << "Empty" << endl;
        }
    }

    // Destructor
    ~MyBuffer() {
        delete[] data;
    }
};

int main() {
    MyBuffer b1(3); // b1 me h: 10 20 30
    MyBuffer b2(2); // b2 me h: 10 20

    b2 = b1;        // Assignment operator call hoga!

    cout << "b2 Data: ";
    b2.display();   // Output aana chahiye: 10 20 30 

    b1 = b1;        // Self assignment test
    cout << "b1 Data after self-assign: ";
    b1.display();   // Output crash nahi hona chahiye, 10 20 30 aana chahiye

    return 0;
}