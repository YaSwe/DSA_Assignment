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

void Post::setTopic(string newTopic)
{
	topic = newTopic;
}

string Post::getUsername()
{
	return user.getName();
}

void Post::setUserName(string newUserName)
{
	user.getName() = newUserName;
}

string Post::getText()
{
	return text;
}

void Post::setText(string newText)
{
	text = newText;
}

list<string> Post::getComment()
{
	return commentList;
}

void Post::setComment(list<string> newCommentList)
{
	commentList = newCommentList;
}

