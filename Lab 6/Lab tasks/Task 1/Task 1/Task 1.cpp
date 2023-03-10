#include<iostream>
#include<stdlib.h>
using namespace std;

struct Node
{
	int data;
	Node* next;
};

Node* head = NULL;

void insertNode(int data)
{
	Node* temp = new Node();
	temp->data = data;
	Node* ptr = head;

	temp->next = ptr;
	head = temp;
}

void deleteNode()
{
	Node* ptr = head;
	head = head->next;
	free(ptr);
	ptr = NULL;
}

void display()
{
	Node* ptr = head;

	if (head == NULL)
	{
		cout << "The queue is empty " << endl;
	}

	else
	{
		cout << "The queue is : ";
		while (ptr != NULL)
		{
			if (ptr)
			{
				cout << ptr->data << "<-";
				ptr = ptr->next;
			}
		}

		cout << "\b\b  ";
	}

	cout << endl;
	cout << endl;
}

void menu()
{
	cout << "Select any option " << endl;
	cout << "   1. Insert number in queue " << endl;
	cout << "   2. Delete number in queue " << endl;
	cout << "   3. Display the queue " << endl;
	cout << "   0. Exit " << endl;
}

int main()
{
	char ch;
	int data;

	do
	{
		menu();
		cin >> ch;

		switch (ch)
		{
			case '1':
				cout << "Enter the number that you want to insert in the queue " << endl;
				cin >> data;
				insertNode(data);
				system("cls");
				break;

			case '2':
				deleteNode();
				system("cls");
				break;

			case '3':
				system("cls");
				display();
				break;

			default:
				cout << "Invalid Input! " << endl;
				cout << endl;
				break;
		}
	} while (ch != '0');

	return 0;
}