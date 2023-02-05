/*
P02
Chua Jie Ren - S10222145D
THU YA SWE - S10222373G
*/

#pragma once
#include<iostream>
#include "Post.h"
#include "CommentList.h"
using namespace std;

typedef Post ItemType;

class PostList
{
public:
	struct Node
	{
		ItemType item;	
		Node* next;	
	};

	
	Node* firstNode;
	int  size;

	PostList();

	~PostList();

	bool add(ItemType item);

	bool add(int index, ItemType item);

	void remove(int index);

	ItemType get(int index);

	bool isEmpty();

	int getLength();

	void print();

	void topicPrint(string topicInput);
	// printing of list according to topic inputted by user
	void accPrint(User user);
	// printing of all items in list
	void printAll();

	void replace(int index, ItemType item);

	// updating the text file
	void writeFile();

	// removal of everything
	void deleteAllNodes();

};

