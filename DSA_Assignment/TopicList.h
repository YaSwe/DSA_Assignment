/*
P02
Chua Jie Ren - S10222145D
THU YA SWE - S10222373G
*/

#pragma once
#include<iostream>
using namespace std;

class TopicList
{
public:
	struct Node
	{
		string item;
		Node* next;
	};

	Node* firstNode;
	int  size;

	TopicList();

	~TopicList();

	bool add(string item);

	bool add(int index, string item);

	void remove(int index);

	string get(int index);

	bool isEmpty();

	int getLength();

	void print();

	void deleteAllNodes();


};

