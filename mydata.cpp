#include <iostream>
using namespace std;
class data
{
    int real, imag;

public:
    data()
    {
        cout << "\n"
             << "default constructor";
        real = 0;
        imag = 0;
    }
    data(int r, int i)
    {
        real = r;
        imag = i;
        cout << "\n"
             << " param constructor";
    }
    ~data()
    {
        cout << "\n"
             << "default destructor";
    }
    void display()
    {
        cout << "\n\n"
             << real << "+" << imag << "i";
    }
    void display1()
    {
        cout << "\n\n"
             << real << "+" << imag << "i";
    }
    void display2(data c)
{
    if (*this == c)
        cout << "\n\nObjects are Equal";
    else
        cout << "\n\nObjects are Not Equal";
}
    data operator+(data c)
    {
        data result;
        result.real = real + c.real;
        result.imag = imag + c.imag;
        return result;
    }
    data operator-(data c)
    {
        data result;
        result.real = real - c.real;
        result.imag = imag - c.imag;
        return result;
    }
    // data operator+(data c)
    // {
    //     data result;
    //     result.real = real + c.real;
    //     result.imag = imag + c.imag;
    //     return result;
    // }
    bool operator==(data c)
    {
        if (real == c.real &&imag == c.imag)
            return true;
        else
        {
            return false;
        }
    }
};
int main()
{
    data c1(4, 5), c2(2, 3), c3;
    c3 = c1 + c2;
    c3.display();
    c3 = c1 - c2;
    c3.display1();
    c3.display2(c2);
    return 0;
}
// operator overloading

// operator keyword , by using this create for + , - , > , == ;
// what is valueAtThis;