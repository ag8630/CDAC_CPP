#include <iostream>
using namespace std;

class student {
private:
    int rno;
    string name;
    int mk1; 
    int mk2;
    int mk3;
    char grade;

public:
    student() {
        rno = 0;
        name = "";
        mk1 = mk2 = mk3 = 0;
        grade = 'G';
    }

    // Constructor accepts 5 parameters and calculates grade automatically
    student(int rn, string nme, int m1, int m2, int m3) {
        this->rno = rn;
        this->name = nme;
        this->mk1 = m1;
        this->mk2 = m2;
        this->mk3 = m3;
        calculate_grade();
    }

    void set_details(int rn, string nme, int m1, int m2, int m3) {
        this->rno = rn;
        this->name = nme;
        this->mk1 = m1;
        this->mk2 = m2;
        this->mk3 = m3;
        calculate_grade();
    }

    void get_details() {
        cout << "\n student details  => ["
             << "name = " << name 
             << " roll number = " << rno 
             << " marks 1 = " << mk1 
             << " marks 2 = " << mk2 
             << " marks 3 = " << mk3 
             << " grade = " << grade << "]";
    }

    void calculate_grade() {
        int total = mk1 + mk2 + mk3;

        if (total >= 280 && total <= 300) {
            grade = 'A';
        } 
        else if (total >= 260 && total < 280) {
            grade = 'B';
        } 
        else if (total >= 240 && total < 260) {
            grade = 'C';
        } 
        else if (total >= 220 && total < 240) {
            grade = 'D';
        } 
        else if (total >= 200 && total < 220) {
            grade = 'E';
        } 
        else if (total >= 180 && total < 200) {
            grade = 'F';
        } 
        else {
            grade = 'G';
        }
    }
};

int main() {
    student s1(1, "shiv", 100, 100, 100);
    s1.get_details();

    return 0;
}