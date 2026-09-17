
// dangling pointer -- pointer holding a value or address which does not belong to processes addresses space  
// if we allocate memory at run time and release that memory after use . the pointer which was holding addresss will become 
// dangling pointer 
#include<iostream>
using namespace std;
class myarray{
    int size;
    int *ptr;
    public:
    myarray(){
        size = 5;

        ptr = new int[size];
        for(int i =0;i<size;i++){
            ptr[i] = i+1;
        }
    }
    void display(){
        for(int i = 0; i<size ; i++){
            cout<<"\n"<<ptr[i];
        }
        ptr[3] = 300;
    }
    // ~myarray(){
    //     cout << "\nDestructor called for ptr: " << ptr;
    //     delete[]ptr;
    //     ptr = nullptr;
       
    // }
};
int main(){
    myarray a1;
    myarray a2(a1);
    cout<<" okay";
    a1.display();
    a2.display();
    return 0;

}
