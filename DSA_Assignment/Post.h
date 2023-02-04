#pragma once
#include <iostream>
#include <list>
#include "User.h"
#include "CommentList.h"

using namespace std;

class Post {
private:
	string topic;
	User user;
	string text;
	CommentList commentList;
	int postID;

public:
	Post(string topic, User user, string text, CommentList commentList, int postID);

	Post() = default;
	
	string getTopic();

	void setTopic(string newTopic);
	
	string getUsername();
	
	void setUserName(string newUsername);

	string getText();
	
	void setText(string newText);

	CommentList getComment();

	int getID();

	void print();

	void setComment(CommentList newCommentList);

};

