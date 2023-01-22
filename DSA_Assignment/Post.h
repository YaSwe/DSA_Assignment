#pragma once
#include <iostream>
#include "User.h"
using namespace std;

class Post {
private:
	string topic;
	User user;
	string text;

public:
	Post(string topic, string text);

	void createPost(string topic, User user, string text) 
	{

	}

	void deletePost()
	{

	}
};
