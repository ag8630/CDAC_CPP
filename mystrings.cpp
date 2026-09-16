


#include<iostream>
using namespace std;

class mystring
{
    char *str;
    int len;
public:
    mystring()
    {
        cout<<"\n Default constructor..";
        len = 2;
        str = new char[len];
        str[0] = '\0';
    }
    mystring(const char *s)
    {
        int l;
        cout<<"\n Parameterized constructor..";
        for(l=0; s[l]!='\0';l++);
        len = l;
        str = new char[len+1];
        for(l=0 ; s[l]!='\0';l++)
            str[l] = s[l];
    }
    mystring(mystring &s)
    {
        int i;
        len = s.len;
        cout<<"\n Copy constructor is called..";
        str = new char[len+1];
        for(i = 0 ; i<len ; i++)
            str[i] = s.str[i];
        str[i] = '\0';
    }
    mystring(mystring &&s)
    {
        cout<<"\n\n move constructor is called..";
        len = s.len;
        str = s.str;
        s.str = nullptr;
    }

    ~mystring()
    {
        cout<<"\n\n Destructor is called..";
        if(str[0] != '\0')
        {
            delete []str;
            //str[0] = '\0';
        }
    }
    const mystring &operator = (const mystring &s)
    {
        int i;
        delete []str;
        cout<<"\n\n assignment operator is called..";
        len = s.len;
        str = new char[len+1];
        for(i = 0 ; i<len ; i++)
            str[i] = s.str[i];
        str[i] = '\0';
    }
    void append(const char *s) {
    // 1. Nayi string ki length count karo
    int new_len = 0;
    while (s[new_len] != '\0') new_len++;

    // 2. Combined size ki nayi memory maango
    char *temp = new char[len + new_len + 1];

    // 3. Purana data copy karo
    int i = 0;
    for (i = 0; i < len; i++) {
        temp[i] = str[i];
    }

    // 4. Naya data aage jodo
    for (int j = 0; s[j] != '\0'; j++, i++) {
        temp[i] = s[j];
    }
    temp[i] = '\0'; // Null character

    // 5. Purani memory free karke pointer update karo
    delete[] str;
    str = temp;
    len = len + new_len;
}
void display2(){
    
}

    void display()
    {
        cout<<"\n\n"<<str;
    }

};

int main()
{
    cout<<"Main..";
    mystring obj1;
    mystring obj2("Infoway Pune");
    mystring obj3(obj2);
    obj2.display();
    obj1 = move(obj2);
    obj1.display();
    
    cout << "--- Testing Append Function ---";
    mystring s1("Infoway");
    
    cout << "\n Before Append:";
    s1.display(); // Output: Infoway

    s1.append(" Pune");
    
    cout << "\n After Append:";
    s1.display(); // Output: Infoway Pune

    
    return 0;
}
/*

add append function, which will concat the
   string parameter into str
add setString and getString
add + operator overloaded function
add char charAt(int) function, returns char at pos

 char &operator[](int index)
   {
      return str[index];
   }

  in main() function cout<<str1[3];
*/
