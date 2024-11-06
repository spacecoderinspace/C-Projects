/*
 #include<bits/stdc++.h>
/* or,
#Include<iostream>
#include<cstdlib> for random function to generate random number
#include<ctime> to generate number as per time
#include<cstring> 

using namespace std;

string getPassword(int length){
    string Password ="";
    string characters="aquickbrownfoxjumpsoverthelazydogAQUICKBROWNFOXJUMPOVERTHELAZYDOG0123456789";
    int charSize =characters.size();
    srand(time(0));
    int randomIndex;
    for(int i=0;i<length;i++){
        randomIndex=rand() % charSize;
        Password+=characters[randomIndex];
    }return Password;
}


int main(){
    
    int length;
    cout<<"Enter the length of the Password :"<<endl;
    cin>>length;
    string password =getPassword(length);
    cout<<"Generated Password :"<<password;

} 
*/ /*Better code using
Seed Casting: Used static_cast for clarity in srand().
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

string getPassword(int length) {
    string password = "";
    string characters = "aquickbrownfoxjumpsoverthelazydogAQUICKBROWNFOXJUMPOVERTHELAZYDOG0123456789!@#$%^&*";
    int charSize = characters.size();
    
    srand(static_cast<unsigned int>(time(0))); // Seed with current time
    for (int i = 0; i < length; i++) {
        int randomIndex = rand() % charSize;
        password += characters[randomIndex];
    }
    return password;
}

int main() {
    int length;
    cout << "Enter the length of the Password: ";
    cin >> length;
    
    if (length <= 0) {
        cout << "Password length must be a positive integer!" << endl;
        return 1;
    }
    
    string password = getPassword(length);
    cout << "Generated Password: " << password << endl;
    
    return 0;
}