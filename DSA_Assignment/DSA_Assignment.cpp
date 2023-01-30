#include <iostream>
#include <string>
#include <fstream>
#include "User.h"
#include "Post.h"
#include "List.h"

using namespace std;

int option;
string username, password, fname, usern, pw;
User user;
ofstream outFile; // write file  
ifstream inFile; // read file
List postList;

void CreatePost(User user)
{
    string topic, post, comment;
    list<string> commentList;

    cout << "Topic: ";
    cin.ignore();
    getline(cin, topic);
    cout << "Post: ";
    getline(cin, post);

    // create new post object
    Post p(topic, user, post, commentList);
    // add post into post list
    postList.add(p);

    outFile.open("forumdata.txt", ios_base::app);
    if (outFile.fail())
    {
        cout << "File does not exist." << endl;
    }
    else
    {
        outFile << username << endl;
        outFile << topic << endl;
        outFile << post << endl;

        for (const auto& word : commentList)
        {
            comment += word;
        }

        outFile << comment << endl;
        outFile.close();
        cout << "\nPost created succesfully." << endl;
    }
    // write to their respective account file
    postList.writeFile(username);
}

// read from text file and get list data
void readForum(User user)
{
	string topic, username, text;
	list<string> commentList;

	inFile.open("forumdata.txt");
	if (inFile.fail())
	{
		cout << "File does not exist." << endl;
	}
	else
	{
		while (!inFile.eof())
		{
			getline(inFile, username);
			getline(inFile, topic);
			getline(inFile, text);
			Post p(topic, user, text, commentList);
			postList.add(p);
		}

		inFile.close();
	}
}

void LoadForum(User user)
{
	readForum(user);
	postList.print();
}


void MyPosts(string username)
{
    string str;

    cout << "Welcome, " << username << endl;
    cout << "\n---------------- Posts -------------------" << endl;
    fname = username + ".txt";
    inFile.open(fname);
    if (inFile.fail())
    {
        cout << "File does not exist." << endl;
    }
    else
    {
        // read till end of file
        while (!inFile.eof())
        {
            getline(inFile, str);
            cout << str << endl;
        }
        inFile.close();
    }
    
    
}

void MainMenu(User user)
{
    int option;
    do
    {
        cout << "\n---------------- Welcome to C++ Forum -------------------" << endl;
        cout << "Choose one option: \n[1] Create a post \n[2] Home \n[3] My Posts\n[4] Log out" << endl << "Choice: ";
        cin >> option;

        // create post
        if (option == 1)
        {
            CreatePost(user);
        }
        // load topic with posts
        else if (option == 2)
        {
            LoadForum(user);
        }
        // view own posts
        else if (option == 3)
        {
            //MyPosts(username);
        }
        // log out
        else if (option == 4) 
        {
            return;
        }
    } while (option != 0);
}

void Register() {

    bool notExists = true;
    cout << "Create a username: ";
    cin >> username;
    cout << "Create a password: ";
    cin >> password;

    inFile.open("username.txt");
    while (!inFile.eof()) {
        getline(inFile, usern);
        if (username == usern) {
            notExists = false;
        }
    }

    // if account with username exist
    if (!notExists) {
        cout << "There is already an existing account with that username. Please try again." << endl;
        cout << endl;
    }

    inFile.close();

    // if account with username does not exist
    if (notExists) {

        outFile.open(fname, ios_base::app);
        outFile << username << endl;
        outFile.close();

        outFile.open("password.txt", ios_base::app);
        outFile << password << endl;
        outFile.close();

        cout << "Your registration was successful!\n";
    }
   

    // if there is an account with same username
    /*
    if (username == usern)
    {
        cout << "There is already an existing account with that username. Please try again." << endl;
        inFile.close();
    }
    */


    // registration successful
    /*
    else {
        outFile.open(fname);
        outFile << username << endl << password << endl;
        cout << "You are successfully registered!" << endl;
        outFile.close();
        cout << endl;
    }
    */
}

bool LogIn() {

    bool login = false;
    cout << "\nEnter your username: ";
    cin >> username;
    cout << "Enter your password: ";
    cin >> password;

    /*
    fname = username + ".txt";
    inFile.open(fname);

    // if account with username does not exist
    if (!inFile.is_open() && inFile.fail())
    {
        cout << "There is no existing account with that username. Please register an account before logging in." << endl;
        inFile.close();   
        return false;
    }

    getline(inFile, usern);
    getline(inFile, pw);

    // username and password matches
    if (username == usern && password == pw)
    {       
        cout << "Log in successful!" << endl;
        cout << "Welcome, " << username << endl;
        inFile.close();
        MainMenu(username);
        return true;
    }
    // username and password does not match
    else
    {
        cout << "Invalid username or password! \nPlease try again!" << endl;
    }
    cout << endl;
    */

    int line = 0;
    inFile.open("username.txt");
    while (!inFile.eof())
    {

        getline(inFile, usern);
        if (username != usern)
        {
            line++;
        }

        else {
            inFile.close();
        }
    }

    inFile.open("password.txt");
    for (int i = 0; i < line; i++)
    {
        getline(inFile, pw);
        if (password == pw)
        {
            cout << "Log in successful!" << endl;
            inFile.close();
            User user(username, password);
            MainMenu(user);
            login = true;
            return true;
        }

    }

    if (login == false) {

        cout << "\nInvalid username or password! \nPlease try again!\n" << endl;
    }
    return false;
}

int main()
{

    /*
    int option;
    string username, password, fname, usern, pw;
    ofstream outFile; // write file  
    ifstream inFile; // read file 
    */

    do
    {
        cout << "---------------- C++ Forum -------------------" << endl;
        cout << "Choose one option: \n[1] Register \n[2] Log in" << endl << "Choice: ";
        cin >> option;

        // register 
        if (option == 1) 
        {      
            Register();        
        }

        // log in
        else if (option == 2) 
        {
            // stop displaying menu if log in is successful
            if (LogIn() == true) 
            {             
                option = 0; 
            }       
        }   
    } 
    while (option != 0);  
}

