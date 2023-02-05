/*
P02
Chua Jie Ren - S10222145D
THU YA SWE - S10222373G
*/

#include "PostList.h"	
#include "CommentList.h"
#include <fstream>
#include <string>
   
PostList::PostList() { size = 0; firstNode = NULL; }
PostList::~PostList() 
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

bool PostList::add(ItemType newItem)
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

bool PostList::add(int index, ItemType item)
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


void PostList::remove(int index)
{
	bool success = (index >= 0) && (index <= size) && (size != 0);
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
				tmp = previous->next;
			}

			previous->next = current->next;	
		}		

		cout << tmp->item.getText();
		delete tmp;
		tmp = NULL;
		size--; 
	}
}

void PostList::replace(int index, ItemType item)
{
	Node* temp = firstNode;

	for (int i = 0; i < index - 1; i++)  // move to node at specified index
	{
		temp = temp->next;
	}

	temp->item = item;           // replace the item  
}



// remove an item at a specified position in the list
/*
void PostList::remove(int index)
{
	bool success = (index > 0) && (index < size + 1);
	if (success)
	{  
		if (index == 1) {
			Node* temp = firstNode;
			firstNode = firstNode->next;
			delete temp;
			size--;
		}

		else {
			Node* temp = firstNode;
			for (int i = 1; i < index - 1; i++) {
				if (temp != NULL) {
					temp = temp->next;
				}
			}
			Node* tmp = temp->next;
			delete tmp;
			temp->next = temp->next->next;
			size--;
		}
	}
}
*/

ItemType PostList::get(int index)
{
	ItemType dataItem;
	bool success = (index >= 0) && (index <= size);
	if (success)
	{
		Node* current = firstNode;
		for (int i = 1; i < index; i++)
			current = current->next;		

		dataItem = current->item;
	}

	return dataItem;
}

bool PostList::isEmpty()
{
	return size == 0;
}

int PostList::getLength()
{
	return size;
}

//------------------- Other useful functions -----------------
void PostList::print()
{
	Node* temp = firstNode;

	if (temp == NULL)
		cout << "The list is empty." << endl;
	else
	{
		while (temp != NULL)
		{
			cout << "\nPosted by: " << temp->item.getUsername() << endl;
			cout << "Topic: " << temp->item.getTopic() << endl;
			cout << "Text: " << temp->item.getText() << endl;
			cout << "Comments: " << endl;
			temp = temp->next;
		}
	}
}

// print via topic
void PostList::topicPrint(string topicInput)
{
	Node* temp = firstNode;

	if (temp == NULL)
		cout << "The list is empty." << endl;
	else
	{
		while (temp != NULL)
		{
			if (temp->item.getTopic() == topicInput)
			{
				cout << "\nPost ID: " + to_string(temp->item.getID()) << endl;
				cout << "Posted by: " << temp->item.getUsername() << endl;
				cout << "Topic: " << temp->item.getTopic() << endl;
				cout << "Text: " << temp->item.getText() << endl;
				CommentList commentList;
				CommentList empty;
				commentList = temp->item.getComment();

				if (commentList.size != 0) {
					cout << "Comments: ";
					commentList.print();
				}
				else if (commentList.size == 0) {
					cout << "There are no comments yet on this post.";
				}

				cout << endl;
			}

			temp = temp->next;		
		}
	}
}

// print according to user
void PostList::accPrint(User user)
{
	Node* temp = firstNode;
	CommentList cl;

	if (temp == NULL)
		cout << "The list is empty." << endl;
	else
	{
		while (temp != NULL)
		{
			if (temp->item.getUsername() == user.getName())
			{
				cout << "\nPost ID: " + to_string(temp->item.getID()) << endl;
				cout << "Posted by: " << temp->item.getUsername() << endl;
				cout << "Topic: " << temp->item.getTopic() << endl;
				cout << "Text: " << temp->item.getText() << endl;
				CommentList commentList;
				CommentList empty;
				commentList = temp->item.getComment();

				if (commentList.size != 0) {
					cout << "Comments: ";
					commentList.print();
				}
				else if (commentList.size == 0) {
					cout << "There are no comments yet on this post.";
				}

				cout << endl;
			}

			temp = temp->next;
		}
	}
}

// print all posts
void PostList::printAll()
{
	Node* temp = firstNode;

	if (temp == NULL)
		cout << "The list is empty." << endl;
	else
	{
		while (temp != NULL)
		{
			cout << "\nPost ID: " + to_string(temp->item.getID()) << endl;
			cout << "Posted by: " << temp->item.getUsername() << endl;
			cout << "Topic: " << temp->item.getTopic() << endl;
			cout << "Text: " << temp->item.getText() << endl;
			CommentList commentList;
			CommentList empty;
			commentList = temp->item.getComment();
	
			if (commentList.size != 0) {
				cout << "Comments: ";
				commentList.print();
				cout << endl;
			}
			else if (commentList.size == 0) {
				cout << "There are no comments yet on this post.\n";
			}

			cout << "Likes: " << to_string(temp->item.getLikes());

			cout << endl;

			temp = temp->next;
		}
	}
}

// updating of file
void PostList::writeFile()
{
	Node* temp = firstNode;

	ofstream outFile;
	outFile.open("forumdata.txt", ios_base::trunc);

	if (temp == NULL)
	{
		cout << "The list is empty." << endl;
	}
	else
	{
		while (temp != NULL)
		{		
			outFile << temp->item.getUsername() << endl;
			outFile << temp->item.getTopic() << endl;
			outFile << temp->item.getText() << endl;
			CommentList cl;
			Post p;
			cl = temp->item.getComment();
			outFile << cl.CommentString() << endl;	
			p = temp->item;
			outFile << p.getLikes() << endl;
			temp = temp->next;
		}
		outFile.close();
	}
}

// clearing of postlist
void PostList::deleteAllNodes()
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



