/*
P02 Group 8
Chua Jie Ren - S10222145D
THU YA SWE - S10222373G

Additional features - View posts by selected topic (line 232), like a post (line 362)
*/

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "User.h"
#include "Post.h"
#include "PostList.h"
#include "TopicList.h"
#include "CommentList.h"

using namespace std;
static int current_id = 1;
string option;
int choice;
string username, password, fname, usern, pw;
User user;
ofstream outFile; // write file  
ifstream inFile; // read file

TopicList topicList; 
PostList postList; 
CommentList commentList;

// Create new post
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
    // add new post into post list
    postList.add(p);
    
    // open forumdata.txt to append the new post
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
        outFile << " " << endl;

        //outFile << comment << endl;
        outFile << "0";
        outFile.close();
        cout << "\nPost created succesfully." << endl;
    } 
}



// Initializing List 
void ReadForum(User user)
{
    string topic, username, text, likes;
    string comment;
    // open the forumdata.txt to load the posts data
	inFile.open("forumdata.txt");
	if (inFile.fail())
	{
		cout << "File does not exist." << endl;
	}
	else
	{
        while (getline(inFile, username) && getline(inFile, topic) && getline(inFile, text) && getline(inFile, comment) && getline(inFile, likes))
		{      
            int like = 0;
            CommentList commentList;
            commentList.size = 0;
            User u(username, "123");

            // if no comments
            if (comment == " ") {
                
                stringstream ss;
                ss << likes;
                ss >> like;
                // current_id++ so that it is assigned automatically
                Post p = Post(topic, u, text, commentList, current_id++, like);
                postList.add(p);
            }
            
            //cout << to_string(c);

            else {

                // Getting the comments, placing it into a CommentList
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

                        if (comment1.length() + 1 == comment.length()) 
                        {
                            //cout << "work 1";
                            comment = " ";
                            break;
                        }
                        if (comment1.length() == comment.length()) 
                        {
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

                // converting to integer
                stringstream ss;
                ss << likes;
                ss >> like;
                //cout << to_string(like);
                // automatically assigned id
                Post p = Post(topic, u, text, commentList, current_id++, like);
                postList.add(p);
                //cout << "work2";

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
                
            }
		}
		inFile.close();
	}

    // open topicdata.txt to load topic data 
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


// Creating new topic
void CreateTopic(User user)
{
    string topic;
    cout << "\nWelcome, " << user.getName() << endl;
    cout << "---------------- Create a topic -------------------" << endl;
    cout << "Enter a C++ topic: ";
    cin >> topic;

    // open topicdata.txt to append the new topic
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

    // if no topics are found
    if (topicList.getLength() < 1)
    {
        cout << "\nNo topics are found. Create one? [Y/N]" << endl;
        cin >> option;
        // create topic
        if (option == 'Y')
        {
            CreateTopic(user);
        }
        else if (option == 'N')
        {
            PrintTopicForum(user);
        }
    }
    // display all topics and select topic 
    else
    {
        // display all topics
        topicList.print();
        cout << "\nSelect topic or '0' to exit: ";
        cin >> topicInput;
        if (topicInput == "0") {
            return;
        }
        cout << "\n---------------- " << topicInput << " Posts -------------------" << endl;
        // display posts based on selected topic
        postList.topicPrint(topicInput);
    }
}

// View posts made by the logged in user
void MyPosts(User user)
{
    int option, wantedPost;
    string newText;
    do {
		cout << "\nWelcome, " << user.getName() << endl;
		cout << "---------------- My Posts -------------------" << endl;
		postList.accPrint(user);
		//cout << postList.getLength();
        cout << "\nChoose an option:\n[1] Delete a post \n[2] Edit a post\n[0] Exit" << endl << "Your Choice: ";
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
            current_id = 0;
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
            //cout << newText;
            Post p = postList.get(wantedPost);
            p.setText(newText);
            postList.replace(wantedPost, p);
            postList.writeFile();

            option = 0;
            break;
        }

    } while (option != 0);
}

// printing of all posts
void PrintAllPosts()
{
    int index;
    int option;
    string comment;
    do
    {
		cout << "\n---------------- My Posts -------------------" << endl;
		postList.printAll();
		cout << "\nChoose an option: \n[1] Comment on a post \n[2] Like a post \n[0] Exit \nYour Option: ";
        cin >> option;

        // exit 
        if (option == 0) 
        { 
            break; 
        }
        // comment on a post
        else if (option == 1) 
        {          
            cout << "Which post do you want to comment on? ";
            cin >> index;
            // retrieve post using index input
            Post p = postList.get(index);
            cout << "Comment: ";
            cin.ignore();
            getline(cin, comment);
            // updating the commentlist, then updating the post in postlist.
            commentList = p.getComment();
            commentList.add(comment);
            p.setComment(commentList);
            postList.replace(index, p);
            postList.writeFile();
            option = 0;
        }

        // like a post
        else if (option == 2) 
        {
            cout << "Which post do you want to like?: ";
            cin >> index;
            // retrieve post using index input
            Post p = postList.get(index);
            // updating of selected post's likes.
            p.setLikes(p.getLikes() + 1);         
            postList.replace(index, p);
            postList.writeFile();
            option = 0;
        }    

    } while (option != 0);
}


// display main menu with all options
void MainMenu(User user)
{
    // delete current linked list
    postList.deleteAllNodes();
    // load forum and topic data
    ReadForum(user);

    int option;
    do
    {
        cout << "\n---------------- Welcome to C++ Forum -------------------" << endl;
        cout << "Choose one option: \n[1] Create a post \n[2] Create a topic \n[3] View Forum \n[4] View Forum by Topic \n[5] My Posts \n[6] Log out" << endl << "Choice: ";
        cin >> option;

        // create new post
        if (option == 1)
        {         
            CreatePost(user);
        }
        // create new topic
        else if (option == 2)
        {          
            CreateTopic(user);
        }
        // view all posts by all users
        else if (option == 3)
        {
            // delete current linked list      
            postList.deleteAllNodes();
            current_id = 1;
            // load forum and topic data
            ReadForum(user);         
            PrintAllPosts();
        }
        // view posts by selected topic
        else if (option == 4)
        {          
            topicList.deleteAllNodes();
            postList.deleteAllNodes();
            ReadForum(user);
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
            option = -1;
            
        }
        else if (cin.fail())
        {
            cout << "Invalid input. Try again: ";
            cin >> option;
        }

    } while (option != 0);
}

// register new account
void Register() {

    bool notExists = true;
    cout << "Create a username: ";
    cin >> username;
    cout << "Create a password: ";
    cin >> password;

    // open username.txt to check if account with username exist
    inFile.open("username.txt");
    while (!inFile.eof()) 
    {
        getline(inFile, usern);
        if (username == usern) 
        {
            notExists = false;
        }
    }

    // if account with same username exist
    if (!notExists) 
    {
        cout << "There is already an existing account with that username. Please try again." << endl;
        cout << endl;
        return;
    }

    inFile.close();

    // if account with same username does not exist
    if (notExists) 
    {

        outFile.open("username.txt", ios_base::app);
        outFile << username << endl;
        outFile.close();

        outFile.open("password.txt", ios_base::app);
        outFile << password << endl;
        outFile.close();

        cout << "Your registration was successful!\n";
    }
}

// log in with registered account
bool LogIn() {

    bool login = false;
    cout << "\nEnter your username or '0' to exit: ";
    cin >> username;
    if (username == "0")
    {
        return false;
    }
    cout << "Enter your password: ";
    cin >> password;

    while (!login) 
    {

        int line = 0;
        // open username.txt to read lines
        inFile.open("username.txt");
        while (!inFile.eof())
        {
            getline(inFile, usern);
            if (username != usern)
            {
                line++;
            }

            else 
            {
                inFile.close();                
            }
        }

        // open password.txt to check password
        inFile.open("password.txt");
        // read until same line in username.txt
        for (int i = 0; i < line; i++)
        {
            getline(inFile, pw);
        }

        if (password == pw)
        {
            cout << "\nLog in successful!" << endl;
            inFile.close();
            User user(username, password);
            // display main menu
            MainMenu(user);
            return true;
        }
        else 
        {
            cout << "\nInvalid username or password!\n";
            inFile.close();
            return false;
        }
    }
    return false;
}

int main()
{
    do
    {
        cout << "---------------- C++ Forum -------------------" << endl;
        cout << "Choose one option: \n[1] Register \n[2] Log in" << endl << "Choice: ";
        cin >> choice;

        // register
        if (choice == 1)
        {             
            Register();
            choice == 3;
        }

        // log in
        else if (choice == 2)
        {
            if (LogIn())
            {                  
            }

        }  

        else if(cin.fail())
        {
            cout << "Invalid input." << endl;
            return -1;
        }
    } 
    while (choice != 0);
}

