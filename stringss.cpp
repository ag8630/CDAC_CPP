#include<iostream>
using namespace std;

int main(){
    char str[35] ;
    int i;
    int cn[128] = {0};
    cout << "\n enter a string";
    cin.getline(str,35,'\n');
    int cnt [128] ={0};
    for(i = 0;str[i]!='\0';i++){//populate cnt array to increase index
        cn[str[i]]++;
    }
    //printing loop 
    for(i = 0;str[i]!= '\0';i++){
        if(cnt[str[i]]!=0){
            if(str[i]==32){
                cout<<"space-"<< cn[str[i]];
            } 
            else{
                cout<<str[i]<<"-"<<cnt[str[i]];
            }  
             }

    }
}
