#include <iostream>
#include <string>
#include <fstream>
#include "User.h"

using namespace std;

int option;
string username, password, fname, usern, pw;
ofstream outFile; // write file  
ifstream inFile; // read file

void Register() {
    cout << "Create a username: ";
    cin >> username;
    cout << "Create a password: ";
    cin >> password;
    fname = username + ".txt";
    outFile.open(fname);
    outFile << username << endl << password << endl;
    cout << "You are successfully registered!" << endl;
    outFile.close();
    cout << endl;
}

bool LogIn() {
    cout << "Enter your username: ";
    cin >> username;
    cout << "Enter your password: ";
    cin >> password;
    fname = username + ".txt";
    inFile.open(fname);

    // if account with username does not exist
    if (!inFile.is_open() && inFile.fail())
    {
        cout << "There is no existing account with that username. Please register an account before logging in." << endl;
        inFile.close();
        return false;
    }

    getline(inFile, usern, '\n');
    getline(inFile, pw, '\n');

    // username and password does not match
    if (username != usern && password != pw)
    {
        cout << "Invalid username or password! \nPlease try again!" << endl;
    }
    // username and password matches
    else
    {
        cout << "Log in successful!" << endl;
        cout << "Welcome, " << username << endl;
        inFile.close();
        return true;
    }
    cout << endl;
}

void LoadForum() 
{
    string str;

    cout <<"\n---------------- Welcome to C++ Forum -------------------" << endl;
    inFile.open("Forum.txt");
    if (inFile.fail()) 
    {
        cout << "File does not exist." << endl;
    }
    else
    {
        while (!inFile.eof())
        {
            getline(inFile, str);
            cout << str << endl;
        }
        inFile.close();
    }
}

int main()
{
    int option;
    string username, password, fname, usern, pw;
    ofstream outFile; // write file  
    ifstream inFile; // read file 

    do
    {
        cout << "---------------- C++ Forum -------------------" << endl;
        cout << "Choose one option: \n[1] Register \n[2] Log in \n"<< endl;
        cin >> option;

        // register 
        if (option == 1) 
        {      
            Register();
            option = 0;
        }

        // log in
        else if (option == 2) 
        {
            // read forum file and print
            if (LogIn() == true) 
            {
                option = 0;
                LoadForum();
            }
        }   

    } while (option != 0);  
}

