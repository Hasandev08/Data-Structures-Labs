#include<iostream>
#include<windows.h>		//Header files
#include<stdlib.h>
#include"update.h"
using namespace std;

void print(Node* head)		//function to print the linked list
{
	Node* ptr = head;		//creating a pointer pointing at the head

	if (head == NULL)	//condition if there is no data in the list
		cout << "The list is empty " << endl;

	while (ptr != NULL)
	{
		if (ptr)
		{
			cout << ptr->data << "->";	//printing the data of the list and then moving the pointer to next node
			ptr = ptr->next;
		}
	}

	cout << "\b\b  ";
	cout << endl;
	cout << endl;
}


