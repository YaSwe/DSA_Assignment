#pragma once
#include<iostream>
#include "Post.h"
using namespace std;

typedef Post ItemType;

class List
{
public:
	struct Node
	{
		ItemType item;	
		Node* next;	
	};

	Node* firstNode;	
	int  size;

	List();

	~List();

	bool add(ItemType item);

	bool add(int index, ItemType item);

	void remove(int index);

	ItemType get(int index);

	bool isEmpty();

	int getLength();

	void print();

	void accPrint(User user);

	void writeFile();

	void readFile(List List);
};

