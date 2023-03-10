#include<iostream>
#include<windows.h>		//Header files
#include<stdlib.h>
#include"delete.h"
using namespace std;

void updateNode(Node* head, int data, int pos)	//function for updating any data in the list
{
	Node* temp4 = new Node();	//creating a new node
	temp4->data = data;		//passing the data entered by the user to the new node created

	if (head == NULL)	//condition if there is no data in the list
	{
		cout << "List is empty " << endl;
	}

	else if (pos == 1)	//condition if the user wants to update the data present the 1st position of the list
	{
		head->data = temp4->data;
	}

	else   //condition if user wants to update data present at any position in the list
	{
		Node* ptr = head;  //creating a pointer that is pointing to the head pointer

		while (pos != 1 && ptr != NULL)
		{
			ptr = ptr->next;
			pos--;
		}

		if (ptr)
		{
			ptr->data = temp4->data;
		}
	}
}

