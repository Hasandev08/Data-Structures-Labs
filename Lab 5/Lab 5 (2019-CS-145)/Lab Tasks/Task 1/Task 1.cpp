#include<iostream>
#include<stdlib.h>	//header files
using namespace std;

struct Node		//creating nodes using struct
{	
	//creating two pointers for doubly linked list
	int data;	//data part of node
	Node* prev = NULL;	//prev pointer pointing to the previous node
	Node* next = NULL;	//next pointer pointing to the next node
};

void deleteNode(Node*& head, int x)		//function to delete any value in the list
{
	//creating pointers
	Node* temp = head->next;	//temp pointer is pointing to the second node
	Node* temp2 = head;		//temp2 pointer is pointing to the head node

	if (head == NULL)	//condition if there is no node in the linked list
	{
		cout << "Linked list is empty " << endl;
	}

	else if (x == 1)		//condition to delete the 1st node i.e. the head node
	{
		head = head->next;
		free(temp2);
		temp2 = NULL;
	}

	else
	{
		if (x == 5)		//condition to delete the last node of the linked list
		{
			while (temp2->next != NULL)
			{
				temp2 = temp2->next;
			}
			temp2->prev->next = NULL;
			free(temp2);
			temp2 = NULL;
		}

		else		//condition for deleting the nodes other than head and last node
		{
			x--;

			while (x != 1)	
			{
				temp = temp->next;
				temp2 = temp2->next;
				x--;
			}
			temp2->next = temp->next;
			temp->next->prev = temp2;
			free(temp);
			temp = NULL;
		}
	}
}

int main()
{
	int pos;

	//creating 5 nodes of the linked list
	Node* head = new Node();
	Node* temp = new Node();
	Node* temp1 = new Node();	
	Node* temp2 = new Node();
	Node* temp3 = new Node();

	//passing values to the nodes
	head->data = 12;
	head->prev = NULL;			//head node
	head->next = temp;

	temp->data = 32;
	temp->prev = head;
	temp->next = temp1;			//2nd node
	head->next = temp;

	temp1->data = 23;
	temp1->prev = temp;
	temp1->next = temp2;		//3rd node
	temp->next = temp1;

	temp2->data = 46;
	temp2->prev = temp1;
	temp2->next = temp3;		//4th node
	temp1->next = temp2;

	temp3->data = 67;
	temp3->prev = temp2;
	temp3->next = NULL;			//5th node
	temp2->next = temp3;

	Node* ptr = head;		//ptr pointer pointing to the head node

	cout << "The original list is : ";
	while (ptr != NULL)
	{
		cout << ptr->data << "->";			//printing the original list 
		ptr = ptr->next;
	}

	cout << "\b\b  " << endl;
	cout << endl;

	cout << "Enter the position that you want to delete from the list " << endl;
	cin >> pos;						//asking the user to enter the position he wants to delete from the linked list

	if (pos > 0 && pos < 6)
	{
		deleteNode(head, pos);		//calling the delete function
		cout << endl;

		ptr = head;
		cout << "The list after deletion is : " << endl;
		while (ptr != NULL)
		{
			if (ptr)
			{
				cout << ptr->data << "->";
				ptr = ptr->next;			//printing the linked list after deletion
			}
		}

		cout << "\b\b  ";
	}

	else	//if user enters any position not present in the list
	{
		cout << "The entered position does not exist in the list " << endl;		
	}

	cout << endl;

	return 0;
}