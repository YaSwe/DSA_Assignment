/*
P02
Chua Jie Ren - S10222145D
THU YA SWE - S10222373G
*/

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
	// adding of item
	bool add(string item);

	bool add(int index, string item);
	// removal of item at index
	void remove(int index);
	// getting of item at index
	string get(int index);
	// return true if empty
	bool isEmpty();
	// get length of list
	int getLength();
	// return a string of all comments
	string CommentString();
	// printing of all comments in list
	void print();

};

