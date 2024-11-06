#include<iostream>
#include<conio.h> //to use functions of getch
#include<Windows.h> //To use the functions of sleep
using namespace std;

int main(){
    char start;
    cout<<"\t-------------------------------------------"<<endl;
    cout<<"  \t\t     : Snake King :"<<endl;
    cout<<"\t-------------------------------------------"<<endl;
    cout<<"\tPress 's' to Start : ";
    cin>>start;
    if (start=='s'){
        cout<<"\tGame Started";
    }
    return 0;
}
