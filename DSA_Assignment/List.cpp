#include "List.h"	
#include <fstream>
   
List::List() { size = 0; firstNode = NULL; }
List::~List() 
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

bool List::add(ItemType newItem)
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

bool List::add(int index, ItemType item)
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

void List::remove(int index)
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

ItemType List::get(int index)
{
	ItemType dataItem;
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

bool List::isEmpty()
{
	return size == 0;
}

int List::getLength()
{
	return size;
}

//------------------- Other useful functions -----------------
void List::print()
{
	Node* temp = firstNode;

	if (temp == NULL)
		cout << "The list is empty." << endl;
	else
	{
		while (temp != NULL)
		{
			cout << "Topic: " << temp->item.getTopic() << endl;
			cout << "Text: " << temp->item.getText() << endl;
			cout << endl;
			temp = temp->next;		
		}
	}
}

void List::writeFile(string username)
{
	Node* temp = firstNode;

	ofstream outFile;
	string fname = username + ".txt";
	outFile.open(fname, ios_base::app);

	if (temp == NULL)
	{
		cout << "The list is empty." << endl;
	}
	else
	{
		while (temp != NULL)
		{
			if (temp->item.getUsername() == username)
			{
				outFile << "Posted by: " << username << endl;
				outFile << "Topic: " << temp->item.getTopic() << endl;
				outFile << "Post: " << temp->item.getText() << endl;
				cout << endl;
			}
			temp = temp->next;
		}
		outFile.close();
	}
}
