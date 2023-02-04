#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "User.h"
#include "Post.h"
#include "PostList.h"
#include "TopicList.h"
#include "CommentList.h"
#pragma once


static int current_id = 1;
int option;
string username, password, fname, usern, pw;
User user;
ofstream outFile; // write file  
ifstream inFile; // read file

TopicList topicList;
PostList postList;
PostList accList;
CommentList commentList;

// Creating a Post
void CreatePost(User user)
{
    string topic, post, comment;
    CommentList commentList;

    cout << "\nWelcome, " << user.getName() << endl;
    cout << "---------------- Create a post -------------------" << endl;
    cout << "Topic: ";
    cin.ignore();
    getline(cin, topic);
    cout << "Post: ";
    getline(cin, post);

    // create new post object
    Post p(topic, user, post, commentList, current_id++, 0);
    // add post into post list
    // postList.add(p);
    
    outFile.open("forumdata.txt", ios_base::app);
    if (outFile.fail())
    {
        cout << "File does not exist." << endl;
    }
    else
    {
        outFile << endl << user.getName() << endl;
        outFile << topic << endl;
        outFile << post << endl;
        outFile << " ";
        /*
        for (const auto& word : commentList)
        {
            comment += word;
        }
        */

        //outFile << comment << endl;
        outFile.close();
        cout << "\nPost created succesfully." << endl;
    } 
}



// Initialize List
void ReadForum(User user)
{
    
    string topic, username, text, likes;
    string comment;
    // load the forum data
	inFile.open("forumdata.txt");
	if (inFile.fail())
	{
		cout << "File does not exist." << endl;
	}
	else
	{
        while (getline(inFile, username) && (getline(inFile, topic) && (getline(inFile, text) && (getline(inFile, comment)))))
		{      
            CommentList commentList;
            commentList.size = 0;
            User u(username, "123");

            cout << comment;
            if (comment == " ") {
                Post p = Post(topic, u, text, commentList, current_id++, comment, likes);
                postList.add(p);
            }
            
            //cout << to_string(c);

            else {
                while (comment != " ")
                {
                    if (comment.find(',') == NULL)
                    {
                        cout << "NULL";
                        comment = ",";
                    }

                    else if (comment.find(',') != NULL)
                    {
                        int comma = comment.find(',');
                        string comment1 = comment.substr(0, comma);
                        commentList.add(comment1);
                        //cout << comment1;
                        //cout << " length: " + to_string(comment1.length()) + " " + to_string(comment.length()) << endl;
                        //cout << comment << endl;
                        //cout << comment.length();
                        //cout << comment1 << endl;
                        //cout << comment.substr(comment1.length() + 1, comment.length() - 1);
                        //commentList.print();

                        /*
                        size_t pos = comment.find(comment1);

                        if (pos != std::string::npos)
                        {
                            comment.erase(pos, comment1.length());
                            cout << comment;
                        }
                        */

                        if (comment1.length() + 1 == comment.length()) {
                            //cout << "work 1";
                            comment = " ";
                            break;
                        }
                        if (comment1.length() == comment.length()) {
                            //cout << "work 2";
                            comment = " ";
                            break;
                        }
                        else {
                            //cout << "work";

                            comment = comment.substr(comment1.length() + 1, comment.length() - 1);
                        }
                    }
                }

                /*
                while (std::getline(inputFile, line)) {
                    std::size_t firstComma = line.find(',');
                    std::string topic = line.substr(0, firstComma);
                    std::size_t secondComma = line.find(',', firstComma + 1);
                    std::string name = line.substr(firstComma + 1, secondComma - firstComma - 1);
                    std::size_t thirdComma = line.find(',', secondComma + 1);
                    std::string comment = line.substr(secondComma + 1, thirdComma - secondComma - 1);
                    int likes = std::stoi(line.substr(thirdComma + 1));
                    addPost(topic, name, comment, likes);
                }
                */


                Post p = Post(topic, u, text, commentList, current_id++);
                postList.add(p);
                cout << "work2";
            }

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


// Creating of topic
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

// Print Forum by Topic
void PrintTopicForum(User user)
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
            PrintTopicForum(user);
        }
    }
    else
    {
        topicList.print();
        cout << "\nSelect topic: ";
        cin >> topicInput;

        cout << "\n---------------- " << topicInput << " Posts -------------------" << endl;
        postList.topicPrint(topicInput);
    }
}

// View My Posts
void MyPosts(User user)
{
    int option, wantedPost;
    string newText;
    do {
		cout << "\nWelcome, " << user.getName() << endl;
		cout << "---------------- My Posts -------------------" << endl;
		postList.accPrint(user);
		cout << postList.getLength();
        cout << "\n[1] Delete a post \n[2] Edit a post" << endl << "Choice: ";
        cin >> option;

        // delete a post
        if (option == 1)
        {
            cout << "Which post?: ";
            cin >> wantedPost;
            std::istringstream(wantedPost) >> wantedPost;
            postList.remove(wantedPost);
            
            cout << postList.getLength();
			postList.writeFile();
            postList.deleteAllNodes();
            ReadForum(user);
            
            option = 0;
            break;
        }

        // edit a post
        else if (option == 2)
        {
			cout << "Which post?: ";
			cin >> wantedPost;
            cout << "New post: ";
            cin.ignore();
            getline(cin, newText);
            cout << newText;
            Post p = postList.get(wantedPost);
            p.print();
            p.setText(newText);
            p.print();
            postList.replace(wantedPost, p);
            postList.writeFile();
            postList.deleteAllNodes();
            ReadForum(user);

            option = 0;
            break;
        }

    } while (option != 0);
}

void PrintAllPosts()
{
    int index;
    string comment;
    do
    {
		cout << "---------------- My Posts -------------------" << endl;
		postList.printAll();
		cout << "Which post to comment: ";
		cin >> index;
        if (index == 0) { break; }
        Post p = postList.get(index);
        cout << "Comment: ";
        cin.ignore();
        getline(cin, comment);
        commentList = p.getComment();
        commentList.add(comment);
        index = 0;

        postList.writeFile();

    } while (index != 0);
}

void MainMenu(User user)
{
    // loads the forum data
    postList.deleteAllNodes();
    ReadForum(user);

    int option;
    do
    {
        cout << "\n---------------- Welcome to C++ Forum -------------------" << endl;
        cout << "Choose one option: \n[1] Create a post \n[2] Create a topic \n[3] View Forum \n[4] View Forum by Topic \n[5] My Posts \n[6] Log out" << endl << "Choice: ";
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
        // view all posts
        else if (option == 3)
        {
                   
            postList.deleteAllNodes();
            current_id = 1;
            ReadForum(user);
            PrintAllPosts();

        }
        // view posts with specified topic
        else if (option == 4)
        {
            PrintTopicForum(user);
        }
        // view own posts
        else if (option == 5)
        {
            MyPosts(user);
        }
        // log out
        else if (option == 6) 
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

