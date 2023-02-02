#include <iostream>
#include <string>
#include <fstream>
#include "User.h"
#include "Post.h"
#include "PostList.h"
#include "TopicList.h"

using namespace std;

int option;
string username, password, fname, usern, pw;
User user;
ofstream outFile; // write file  
ifstream inFile; // read file

TopicList topicList;
PostList postList;
PostList accList;

void CreatePost(User user)
{
    string topic, post, comment;
    list<string> commentList;

    cout << "\nWelcome, " << user.getName() << endl;
    cout << "---------------- Create a post -------------------" << endl;
    cout << "Topic: ";
    cin.ignore();
    getline(cin, topic);
    cout << "Post: ";
    getline(cin, post);

    // create new post object
    Post p(topic, user, post, commentList);
    // add post into post list
    // postList.add(p);
    
    outFile.open("forumdata.txt", ios_base::app);
    if (outFile.fail())
    {
        cout << "File does not exist." << endl;
    }
    else
    {
        outFile << user.getName() << endl;
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
}

// read from text file and get list data
void readForum(User user)
{
    string topic, username, text, comment, str;
	list<string> commentList;

    // load the forum data
	inFile.open("forumdata.txt");
	if (inFile.fail())
	{
		cout << "File does not exist." << endl;
	}
	else
	{
        while (getline(inFile, username) && (getline(inFile, topic) && (getline(inFile, text) && (getline(inFile, comment, '\n')))))
		{      
            User u(username, "123");
			Post p(topic, u, text, commentList);
			postList.add(p);
		}
		inFile.close();
	}

    // load the topic data
    inFile.open("topicdata.txt");
    if (inFile.fail())
    {
        cout << "File does not exist." << endl;
    }
    else
    {
        while (getline(inFile, topic))
        {
            topicList.add(topic);
        }
        inFile.close();
    }
}

// read from text file and get list data for own posts
void readForumAcc(User user)
{
    string topic, username, text, comment, str;
    list<string> commentList;

    inFile.open("forumdata.txt");
    if (inFile.fail())
    {
        cout << "File does not exist." << endl;
    }
    else
    {
        while (getline(inFile, username) && (getline(inFile, topic) && (getline(inFile, text) && (getline(inFile, comment, '\n')))))
        {
            User u(username, "123");
            Post p(topic, u, text, commentList);
            if (u.getName() == user.getName())
            {
                accList.add(p);
            }
        }
        inFile.close();
    }
}

void CreateTopic(User user)
{
    string topic;
    cout << "\nWelcome, " << user.getName() << endl;
    cout << "---------------- Create a topic -------------------" << endl;
    cout << "Enter a C++ topic: ";
    cin >> topic;

    outFile.open("topicdata.txt", ios_base::app);
    if (outFile.fail())
    {
        cout << "File does not exist." << endl;
    }
    else
    {
        outFile << topic << endl;
        outFile.close();
        cout << "\nTopic created succesfully." << endl;
    }
}

void LoadForum(User user)
{
    string topicInput;
    char option;

    cout << "\n----------- Topics --------------" << endl;

    if (topicList.getLength() < 1)
    {
        cout << "\nNo topics are found. Create one? [Y/N]" << endl;
        cin >> option;
        if (option == 'Y')
        {
            CreateTopic(user);
        }
        else if (option == 'N')
        {
            LoadForum(user);
        }
    }
    else
    {
        topicList.print();
        cout << "\nSelect topic: ";
        cin >> topicInput;

        cout << "\n---------------- " << topicInput << " Posts -------------------" << endl;
        postList.print(topicInput);
    }
}

void MyPosts(User user)
{
    string topic, username, text, comment, str;

    cout << "\nWelcome, " << user.getName() << endl;
    cout << "---------------- My Posts -------------------" << endl;
    postList.accPrint(user);
    cout << postList.getLength();
}

void MainMenu(User user)
{
    // loads the forum data
    readForum(user);
    int option;
    do
    {
        cout << "\n---------------- Welcome to C++ Forum -------------------" << endl;
        cout << "Choose one option: \n[1] Create a post \n[2] Create a topic \n[3] Home \n[4] My Posts\n[5] Log out" << endl << "Choice: ";
        cin >> option;

        // create post
        if (option == 1)
        {
            CreatePost(user);
        }
        else if (option == 2)
        {
            CreateTopic(user);
        }
        // load topic with all posts
        else if (option == 3)
        {
            LoadForum(user);
        }
        // view own posts
        else if (option == 4)
        {
            MyPosts(user);
        }
        // log out
        else if (option == 5) 
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
}

bool LogIn() {

    bool login = false;
    cout << "\nEnter your username: ";
    cin >> username;
    cout << "Enter your password: ";
    cin >> password;

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
            cout << "\nLog in successful!" << endl;
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

