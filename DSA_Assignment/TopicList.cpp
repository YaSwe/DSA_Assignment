/*
P02
Chua Jie Ren - S10222145D
THU YA SWE - S10222373G
*/

#include "TopicList.h"	
#include <fstream>
#include <string>

TopicList::TopicList() { size = 0; firstNode = NULL; }
TopicList::~TopicList()
{
	Node* currNode = firstNode;
	while (currNode != NULL)
	{
		Node* nextNode = currNode->next;
		delete currNode;
		currNode = NULL;
		currNode = nextNode;
	}
	firstNode = NULL;
}

bool TopicList::add(string newItem)
{
	Node* newNode = new Node;
	newNode->item = newItem;
	newNode->next = NULL;

	if (isEmpty())
		firstNode = newNode;
	else
	{
		Node* temp = firstNode;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = newNode;
	}

	size++;

	return true;
}

bool TopicList::add(int index, string item)
{
	bool success = (index >= 0) && (index <= size);

	if (success) {
		Node* newNode = new Node;
		newNode->item = item;
		newNode->next = NULL;

		if (index == 1) {
			newNode->next = firstNode;
			firstNode = newNode;
		}
		else {
			Node* temp = firstNode;
			for (int i = 1; i < index - 1; i++) {
				temp = temp->next;
			}
			newNode->next = temp->next;
			temp->next = newNode;
		}
		size++;
	}
	return success;
}

void TopicList::remove(int index)
{
	bool success = (index >= 0) && (index <= size - 1) && (size != 0);
	if (success)
	{
		Node* tmp = firstNode;
		if (index == 0)
			firstNode = firstNode->next;
		else
		{
			Node* current = firstNode;
			Node* previous = firstNode;
			for (int i = 1; i < index; i++)
			{
				previous = current;
				current = current->next;
			}

			previous->next = current->next;
		}
		delete tmp;
		tmp = NULL;
		size--;
	}
}

string TopicList::get(int index)
{
	string dataItem;
	bool success = (index >= 0) && (index <= size - 1);
	if (success)
	{
		Node* current = firstNode;
		for (int i = 1; i < index; i++)
			current = current->next;

		dataItem = current->item;
	}

	return dataItem;
}

bool TopicList::isEmpty()
{
	return size == 0;
}

int TopicList::getLength()
{
	return size;
}

//------------------- Other useful functions -----------------
void TopicList::print()
{
	Node* temp = firstNode;

	if (temp == NULL)
		cout << "The list is empty." << endl;
	else
	{
		while (temp != NULL)
		{	
			cout << "- " << temp->item << " -" << endl;
			temp = temp->next;
		}
	}
}

void TopicList::deleteAllNodes()
{
	Node* current = firstNode;
	Node* next;

	while (current != NULL) {
		next = current->next;
		delete current;
		current = next;
		size--;
	}
	firstNode = NULL;
}



