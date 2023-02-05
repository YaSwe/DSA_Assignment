/*
P02
Chua Jie Ren - S10222145D
THU YA SWE - S10222373G
*/

#include "Post.h"
#include "PostList.h"

Post::Post(string ptopic, User puser, string ptext, CommentList pcommentList, int id, int like)
{
	topic = ptopic;
	user = puser;
	text = ptext;
	commentList = pcommentList;
	postID = id;
	likes = like;
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

// returning of commentlist
CommentList Post::getComment()
{
	return commentList;
}

void Post::setComment(CommentList newCommentList)
{
	commentList = newCommentList;
}

// returning of postid
int Post::getID() 
{
	if (postID != NULL) {
		return postID;
	}
	return -1;
}

// printing of post
void Post::print() {
	cout << topic << text << postID;
}

// returning of likes for specified post
int Post::getLikes() 
{
	return likes;
}

// setting likes
void Post::setLikes(int like) 
{
	likes = like;
}