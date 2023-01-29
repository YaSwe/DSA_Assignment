#include "Post.h"
#include "List.h"

Post::Post(string ptopic, User puser, string ptext, list<string> pcommentList)
{
	topic = ptopic;
	user = puser;
	text = ptext;
	commentList = pcommentList;
}

string Post::getTopic()
{
	return topic;
}

string Post::getUsername()
{
	return user.getName();
}

string Post::getText()
{
	return text;
}

list<string> Post::getComment()
{
	return commentList;
}

