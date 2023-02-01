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

	void setTopic(string newTopic);
	
	string getUsername();
	
	void setUserName(string newUsername);

	string getText();
	
	void setText(string newText);

	list<string> getComment();

	void setComment(list<string> newCommentList);

};

