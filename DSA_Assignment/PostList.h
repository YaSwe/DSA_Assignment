#pragma once
#include<iostream>
#include "Post.h"
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

	void print(string topicInput);

	void accPrint(User user);

	void writeFile();

};

