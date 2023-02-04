#pragma once
#include<iostream>
using namespace std;

class CommentList
{
public:
	struct Node
	{
		string item;
		Node* next;
	};

	Node* firstNode;
	int  size;

	CommentList();

	//~CommentList();

	bool add(string item);

	bool add(int index, string item);

	void remove(int index);

	string get(int index);

	bool isEmpty();

	int getLength();
	
	string CommentString();

	void print();

};

