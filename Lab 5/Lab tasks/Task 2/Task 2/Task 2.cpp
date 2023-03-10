#include<iostream>
#include<stdlib.h>		//header files
using namespace std;

struct Node		//using struct to create a node
{
	int data;		//part of node storing the data
	Node* prev;		//pointer pointing at the previous node
	Node* next;		//pointer pointing at the next node
};

void updateNode(Node* head, int data, int x)		//update function
{
	Node* temp = new Node();	//creating a node that is to be replaced by the already present node
	temp->data = data;		//passing the value (data) entered by the user to the newly created node 
	Node* ptr = head->next;		//creating a pointer that is pointing to next node of head

	if (head == NULL)		//condition if there is no linked list present
	{
		cout << "The list is empty " << endl;
	}

	else if (x == 1)	//condition if user wants to update the head node
	{
		head->data = temp->data;
	}

	else if (x > 5)		//if user enters any position not in the linked list the data is then inserted at the end
	{
		while (ptr->next != NULL)
		{
			ptr = ptr->next;
		}

		ptr->next = temp;
		temp->prev = ptr;

		cout << "As the entered position is not present in the linked list the data will be inserted at the end of the linked list " <<endl;
		cout << endl;
	}

	else		//condition if user wants to update any value in the node
	{
		x--;
		while (x != 1)
		{
			ptr = ptr->next;
			x--;
		}
		ptr->data = temp->data;
	}
}

int main()
{
	int pos;
	int data;

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

	cout << "Enter the value that you want to in you linked list after updating " << endl;	//asking the user to enter the value
	cin >> data;																			//that he wants in the linked list

	cout << "Enter the position at which you want to update the entered data " << endl;		//asking the user to enter the
	cin >> pos;																				//at which he wants to update the value

	cout << endl;

	updateNode(head, data, pos);	//calling the update function

	ptr = head;

	cout << "The list after updating the value is : ";		
	while (ptr != NULL)
	{
		if (ptr)
		{
			cout << ptr->data << "->";
			ptr = ptr->next;			//printing the linked list after deletion
		}
	}

	cout << "\b\b  ";
	cout << endl;

	return 0;
}