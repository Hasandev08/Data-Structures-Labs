#include<iostream>
#include<windows.h>		//Header files
#include<stdlib.h>
#include"struct.h""
using namespace std;

Node* insertAtStart(Node* head, int data)		//function for inserting data at the start of linked list
{
	Node* ptr = new Node();		//creating a new node that is to be inserted at the start
	ptr->data = data;	//passing the data entered the user
	ptr->next = NULL;	//passing the value NULL to the pointer pointing at next node

	ptr->next = head;
	head = ptr;

	return head;
}

void insertAtPos(Node* head, int data, int x)  //function for inserting data at any position in the linked list
{
	Node* ptr = head;		//creating a pointer pointing at the head of the linked list
	Node* ptr1 = new Node();	//creating a node that is to be inserted in the lined list
	ptr1->data = data;		//passing the data entered by the user
	ptr1->next = NULL;		//passing NULL to the pointer that points to the next node	

	x--;	//decrementing the position entered by the user

	while (x != 1)	//while loop
	{
		if (ptr)	//removing extensions
		{
			ptr = ptr->next;
		}
		x--;
	}

	if (ptr && ptr1)
	{
		ptr1->next = ptr->next;	//inserting the node in the list
		ptr->next = ptr1; //linking the nodes
	}
}

void insertAtEnd(Node* head, int data)		//function for inserting data at the end of the list
{
	Node* ptr;		//creating a pointer
	Node* temp = new Node();	//creating a new node

	ptr = head;		//pointer pointing at the head of the list

	temp->data = data;		//passing the data entered by the user into the node
	temp->next = NULL;		//passing NULL to the node's pointer that is pointing to next node

	while (ptr->next != NULL)
	{
		ptr = ptr->next;
	}

	ptr->next = temp;	//linking the node to linked list
}

