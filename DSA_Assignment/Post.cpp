#include "Post.h"
#include "PostList.h"

Post::Post(string ptopic, User puser, string ptext, CommentList pcommentList, int id, int likes)
{
	topic = ptopic;
	user = puser;
	text = ptext;
	commentList = pcommentList;
	postID = id;
	likes = 0;
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

CommentList Post::getComment()
{
	return commentList;
}

void Post::setComment(CommentList newCommentList)
{
	commentList = newCommentList;
}

int Post::getID() {
	if (postID != NULL) {
		return postID;
	}
	return -1;
}

void Post::print() {
	cout << topic << text << postID;
}

