#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Temp {
    string searchName, searchPassword, searchEmail;
    string userName, Email, Password;
    fstream file;

public:
    void login();
    void signUp();
    void forgot();
} obj; /*The syntax } obj; at the end of the class declaration creates an instance of the
Temp class named obj. This is an example of defining an object right after the class declaration, 
which is allowed in C++.*/

int main() {
    int choice;
    cout << "1- Login" << endl;
    cout << "2- Sign-up" << endl;
    cout << "3- Forgot Password" << endl;
    cout << "4- Exit" << endl;
    cout << "\nEnter your Choice: ";
    cin >> choice;
    cin.ignore();  // Clears the newline character from the input buffer

    switch (choice) {
    case 1:
        obj.login();
        break;
    case 2:
        obj.signUp();
        break;
    case 3:
        obj.forgot();
        break;
    case 4:
        return 0;
    default:
        cout << "Invalid Selection" << endl;
    }
    return 0;
}

void Temp::signUp() {
    cout << "Enter your username: ";
    //cin.ignore();
    getline(cin, userName);
    cout << "Enter your email address: ";
    getline(cin, Email);
    cout << "Enter your password: ";
    getline(cin, Password);

    file.open("loginData.txt", ios::out | ios::app);
    if (!file) {
        cerr << "Error: Unable to open file for writing.\n";
        return;
    }
    file << userName << "*" << Email << "*" << Password << endl;
    file.close();
    cout << "Signup successful!" << endl;
}

void Temp::login() {
    cout << "Please Login.." << endl;
    cout << "Enter your username: ";
    //cin.ignore();
    getline(cin, searchName);
    cout << "Enter your password: ";
    getline(cin, searchPassword);

    file.open("loginData.txt", ios::in);
    if (!file) {
        cerr << "Error: Unable to open file for reading.\n";
        return;
    }

    bool found = false;
    while (getline(file, userName, '*') &&
           getline(file, Email, '*') &&
           getline(file, Password)) {
        if (userName == searchName) {
            found = true;
            if (Password == searchPassword) {
                cout << "Login Success" << endl;
                cout << "Username: " << userName << endl;
                cout << "Email id: " << Email << endl;
            } else {
                cout << "Password Incorrect, please try again!" << endl;
            }
            break;
        }
    }
    if (!found) {
        cout << "Username not registered." << endl;
    }
    file.close();
}

void Temp::forgot() {
    cout << "Enter your username: ";
   // cin.ignore();
    getline(cin, searchName);
    cout << "Enter your email address: ";
    getline(cin, searchEmail);

    file.open("loginData.txt", ios::in);
    if (!file) {
        cerr << "Error: Unable to open file for reading.\n";
        return;
    }

    bool found = false;
    while (getline(file, userName, '*') &&
           getline(file, Email, '*') &&
           getline(file, Password)) {
        if (userName == searchName) {
            found = true;
            if (Email == searchEmail) {
                cout << "Account found." << endl;
                cout << "Your password is: " << Password << endl;
            } else {
                cout << "Email does not match our records." << endl;
            }
            break;
        }
    }
    if (!found) {
        cout << "Username not found." << endl;
    }
    file.close();
}
/*
EXPLANATION :-
# found Flag: Used in both login and forgot to keep track of whether the username was found in the 
file. This prevents multiple outputs of "Username not registered" or "Username not found."

# : This is only used once in main and before each new input set in signUp, login, and 
forgot methods.

============================================================
file.open("loginData.txt", ios::out | ios::app); attempts to open a file named loginData.txt in write 
mode with the append option.

ios::out specifies that the file is opened for output (writing).

ios::app specifies that new data should be added to the end of the file, preserving existing 
content. Without ios::app, opening the file in ios::out mode would overwrite its contents.
---------------------------------------
also it,

if (!file) checks if the file was opened successfully. When a file fails to open (e.g., due to 
permission issues, missing directory, or lack of available resources), file evaluates to false.

If file did not open successfully, cerr << "Error: Unable to open file for writing.\n"; 
sends an error message to the standard error output (cerr), informing the user that the file 
could not be opened.

return; exits the function early, preventing any attempts to write to a file that wasn’t 
successfully opened.

*/