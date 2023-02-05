/*
P02
Chua Jie Ren - S10222145D
THU YA SWE - S10222373G
*/

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
	// set new topic
	void setTopic(string newTopic);
	
	string getUsername();
	// set new username
	void setUserName(string newUsername);

	string getText();
	// set new text
	void setText(string newText);

	// return the commentlist
	CommentList getComment();

	// get stored id of selected post
	int getID();

	// printing of post details'
	void print();

	// returing of likes value
	int getLikes();

	// setting the like value
	void setLikes(int like);

	void setComment(CommentList newCommentList);

};

