#include<iostream>
#include<stdlib.h>		//header files
using namespace std;

struct Node		//using struct to create a node
{
	int data;		//part of node storing the data
	Node* prev;		//pointer pointing at the previous node
	Node* next;		//pointer pointing at the next node
};

void updateNode(Node* head, int data, int num)		//update function
{
	Node* ptr = head;

	while (ptr->next != NULL)
	{
		if(ptr->data == num)
		{
			ptr->data = data;
			return;
		} 
		
		ptr = ptr->next;
	}
}


void insertNodeAtEnd(Node* head, int data)		//to insert data at the end of the list
{
	Node* temp = new Node();	//creating a new node
	temp->data = data;
	temp->prev =NULL;
	temp->next = NULL;
	Node* ptr = head;	//creating a pointer pointing at the head

	while (ptr->next != NULL)	//traversing the list till the last node
	{
		ptr = ptr->next;
	}

	ptr->next = temp;	//inserting the node at the end of the list
	temp->prev = ptr;
}

void print(Node* head)
{
	Node* ptr = head;
	while (ptr != NULL)
	{
		cout << ptr->data << "->";			//printing the list 
		ptr = ptr->next;
	}
	cout << "\b\b  " << endl;
	cout << endl;
}

int main()
{
	int data;
	int num;

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

	temp->data = 27;
	temp->prev = head;			//2nd node
	temp->next = temp1;
	head->next = temp;

	temp1->data = 53;
	temp1->prev = temp;			//3rd node
	temp1->next = temp2;
	temp->next = temp1;

	temp2->data = 46;
	temp2->prev = temp1;		//4th node
	temp2->next = temp3;
	temp1->next = temp2;

	temp3->data = 67;
	temp3->prev = temp2;		//5th node
	temp3->next = NULL;
	temp2->next = temp3;

	Node* ptr = head;		//ptr pointer pointing to the head node

	cout << "The original list is : ";
	print(head);

	cout << "Enter the data that you want to CHANGE from the linked list " << endl;
	cin >> num;

	cout << "Enter the value that you want in your linked list AFTER UPDATING " << endl;	//asking the user to enter the value
	cin >> data;																			//that he wants in the linked list

	cout << endl;
	
	// Search Function
	bool flag = false;
	Node *ptr1 = head;
	
	if(ptr1)
	{
		while(ptr1->next != NULL)
		{
			if(ptr1->data == num) 
				flag = true;
				
			ptr1 = ptr1->next;
		}
	}
	// end of search function
	
	if (flag) //checking if search function found that data in list
	{
		// if yes then update
		updateNode(head, data, num);
		cout << "The list after updating the value is : ";
		print(head);
	}
	
	else 
	{
		// else insert at end
		insertNodeAtEnd(head, data);
		cout << "The list after updating the value is : ";
		print(head);
		cout << "As the entered value was not in the given list, the value is inserted at the end of the node " << endl;
	}

	return 0;
}
