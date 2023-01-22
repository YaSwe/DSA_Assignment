#include <iostream>
#include <string>
#include <fstream>
#include "User.h"
using namespace std;

int main()
{
    int option;
    string username, password, fname, usern, pw;
    ofstream outFile; // write file for register 
    ifstream inFile; // read file for log in

    do
    {
        cout << "---------------- Main Menu -------------------" << endl;
        cout << "Choose one option: \n[1] Register \n[2] Log in \n"<< endl;
        cin >> option;

        // register 
        if (option == 1) 
        {
            User u;         
            cout << "Create a username: ";
            cin >> username;
            cout << "Create a password: ";
            cin >> password;
            u.setName(username);
            u.setPassword(password);   
            fname = username + ".txt";
            outFile.open(fname);
            outFile << username << endl << password << endl;
            cout << "You are successfully registered!" << endl;
            outFile.close();
        }

        // log in
        else if (option == 2) 
        {
            cout << "Enter your username: " << endl;
            cin >> username;
            cout << "Enter your password: " << endl;
            cin >> password;
            fname = username + ".txt";
            inFile.open(fname);

            // if account with username does not exist
            if (!inFile.is_open() && inFile.fail()) 
            {
                cout << "There is no existing account with that username. PLease register an account before logging in." << endl;
                inFile.close();
                continue;
            }

            getline(inFile, usern);         
            getline(inFile, pw);

            // if username and password matches 
            if (username == usern && password == pw) 
            {
                cout << "Log in successful!" << endl;
                cout << "Welcome, " << username << endl;
                inFile.close();
            }
            // useranme and password does not match
            else
            {
                cout << "Invalid username or password! \nPlease try again!" << endl;
            }
            cout << endl;
        }

    } while (option != 0);
}

