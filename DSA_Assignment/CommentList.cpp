#include "CommentList.h"	
#include <fstream>
#include <string>

CommentList::CommentList() { size = 0; firstNode = NULL; }

/*CommentList::~CommentList(){}

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
*/

bool CommentList::add(string newItem)
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

bool CommentList::add(int index, string item)
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

void CommentList::remove(int index)
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

string CommentList::get(int index)
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

bool CommentList::isEmpty()
{
	return size == 0;
}

int CommentList::getLength()
{
	return size;
}


string CommentList::CommentString() {
	string s;
	Node* temp = firstNode;

	if (temp == NULL)
		s = " ";
	else
	{
		while (temp != NULL)
		{

			s = s + temp->item + ",";
			temp = temp->next;

		}
	}

	return s;
}



//------------------- Other useful functions -----------------
void CommentList::print()
{
	Node* temp = firstNode;
	int tempsize = size;
	if (temp == NULL)
		cout << "The list is empty." << endl;
	else
	{
		while (temp != NULL)
		{
			if (tempsize > 1) {
				cout << temp->item << ", ";
				tempsize--;
				temp = temp->next;
				
			}

			else {
				cout << temp->item;
				tempsize--;
				temp = temp->next;
			}

		}
	}
}




