#pragma once
#include <iostream>
#include <list>
#include "User.h"
using namespace std;

class Post {
private:
	string topic;
	User user;
	string text;
	list<string> commentList;

public:
	Post(string topic, User user, string text, list<string> commentList);

	Post() = default;
	
	string getTopic();
	
	string getUsername();
	
	string getText();
	
	list<string> getComment();

};

