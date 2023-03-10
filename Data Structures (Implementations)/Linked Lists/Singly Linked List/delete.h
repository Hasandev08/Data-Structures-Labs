#include<iostream>
#include<windows.h>		//Header files
#include<stdlib.h>
#include"insert.h"
using namespace std;

void deleteNode(Node* head, int pos)	//function for deleting the node
{
	//creating 3 pointers pointing to head node
	Node* prevptr = head;
	Node* currentptr = head;
	Node* ptr = head;

	if (head == NULL)   //condition if the linked list is empty
	{
		cout << "List is empty " << endl;
	}

	else if (pos == 1)	//condition to delete the head node
	{
		head = head->next;
		free(prevptr);
		prevptr = NULL;
	}

	else     //condition for deleting any node in the linked list
	{
		while (pos != 1)	//when the position will become 1 the loop will be ended
		{
			prevptr = currentptr;
			currentptr = currentptr->next;
			pos--;
		}
		prevptr->next = currentptr->next;
		free(currentptr);
		currentptr = NULL;
	}
}

