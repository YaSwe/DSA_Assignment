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
	int likes;

public:
	Post(string topic, User user, string text, CommentList commentList, int postID, int likes);

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

	int getLikes();

	void setLikes(int like);

	void setComment(CommentList newCommentList);

};

