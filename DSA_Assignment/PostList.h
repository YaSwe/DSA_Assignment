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

	void accPrint(User user);

	void printAll();

	void writeFile();

	void deleteAllNodes();

};

