//Header files
#include<iostream>
#include<windows.h>		//Header file for inserting colors and beep sound
#include<stdlib.h>		
using namespace std;

struct Node		//using struct to create a node
{
	int num;		//part of node storing the no of images
	int key;
	string data;	//part of node storing the names
	Node* prev;		//pointer pointing at the previous node
	Node* next;		//pointer pointing at the next node
};

Node* insertNodeAtStart(Node* &head, string data, int num)	//to insert data at the start of linked list
{
	Node* temp = new Node();	//creating a new node
	//passing values to the part of each node
	temp->data = data;
	temp->num = num;
	temp->prev = NULL;
	temp->next = head;
	head->prev = temp;
	head = temp;

	return head;
}

void insertNodeAtPos(Node* head, string data, int num, int x)	//to inert data at any position in the list
{
	Node* temp = new Node();		//declaring a new node
	Node* ptr = head;		//pointing the pointer to head
	//passing the values to the new node created
	temp->data = data;
	temp->num = num;

	x--;
	while (x != 1)		//traversing the list
	{
		if (ptr)
		{
			ptr = ptr->next;
			x--;
		}
	}
	Node* ptr1 = ptr->next;		//creating another pointing to the node next to ptr
	//inserting the node entered by the user
	ptr->next = temp;
	ptr1->prev = temp;
	temp->prev = ptr;
	temp->next = ptr1;
}

void insertNodeAtEnd(Node* head, string data, int num)		//to insert data at the end of the list
{
	Node* temp = new Node();	//creating a new node
	//*******passing the data to the newly created node*******
	temp->data = data;
	temp->num = num;
	temp->next = NULL;
	//********************************************************
	Node* ptr = head;	//creating a pointer pointing at the head

	while (ptr->next != NULL)	//traversing the list till the last node
	{
		ptr = ptr->next;
	}

	ptr->next = temp;	//inserting the node at the end of the list
	temp->prev = ptr;
}

void deleteNodeAtStart(Node*& head)		//function to delete the 1st node
{
	//creating pointers
	Node* temp2 = head;		//temp2 pointer is pointing to the head node

	head = head->next;
	head->prev = NULL;
	free(temp2);		//removing the 1st node
	temp2 = NULL;
}

void deleteNodeAtPos(Node*& head, int x)		//function to delete any value in the list
{
	//creating pointers
	Node* temp = head->next;	//temp pointer is pointing to the second node
	Node* temp2 = head;		//temp2 pointer is pointing to the head node

	x--;
			
	while (x != 1)		//traversing the list
		{
		temp = temp->next;
		temp2 = temp2->next;
		x--;
	}
	temp2->next = temp->next;	
	temp->next->prev = temp2;
	free(temp);			//removing the node entered
	temp = NULL;
}

void deleteLastNode(Node*& head)	//function to delete the last node
{
	//creating pointers
	Node* temp = head->next;		//temp2 pointer is pointing to the head node
	Node* ptr = head;

	while (temp->next != NULL)		//traversing the list
	{
		temp = temp->next;
	}

	ptr = temp->prev;
	ptr->next = NULL;
	free(temp);			//removing the last node
	temp = NULL;
}

void updateNode(Node* head, string data, int num, int x)		//update function
{
	Node* temp = new Node();	//creating a node that is to be replaced by the already present node
	temp->data = data;		//passing the value (string) entered by the user to the newly created node 
	temp->num = num;		//passing the value (integer) entered by the user to the newly created node
	Node* ptr = head->next;		//creating a pointer that is pointing to next node of head

	if (head == NULL)		//condition if there is no linked list present
	{
		cout << "The list is empty " << endl;
	}

	else if (x == 1)	//condition if user wants to update the head node
	{
		head->data = temp->data;
		head->num = temp->num;
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
		ptr->num = temp->num;
	}
}

void printForward(Node* head)		//to print the list in the ascending order
{
	Node* ptr = head;		//ptr pointer pointing to the head node

	if (ptr)
	{
		while (ptr != NULL)		//traversing the node till the last node
		{
			cout << "Name of page : " << ptr->data << endl;
			cout << "Number of images : " << ptr->num << endl;
			cout << endl;
			ptr = ptr->next;
		}
	}
}

void printBackward(Node* head)		//to print the list in the descending order
{
	Node* ptr = head;		//declaring a pointer pointing at the head node
	head->prev = NULL;

	if (ptr)
	{
		while (ptr->next != NULL)	//traversing the node till the last node
		{
			ptr = ptr->next;
		}
		head = ptr;		//making the last node as the head node

		while (ptr != NULL)		//printing the list in the opposite direction
		{
			if (ptr)
			{
				cout << "Name of page : " << ptr->data << endl;
				cout << "Number of images : " << ptr->num << endl;
				cout << endl;
				ptr = ptr->prev;
			}
		}
	}
}

string getFirstPageNameFromNumber(Node* head, int num)		//function to get the page name of 1st page from number of images
{
	Node* temp = new Node();		//creating a new node
	Node* ptr = head;			//creating a pointer pointing at the head
	temp->num = num;

	return ptr->data;		//the string present in the head is returned
}

string getPageNameFromNumber(Node* head, int num)		//function to get the page name of any page from number of images
{
	Node* temp = new Node();		//creating a new node
	Node* ptr = head;			//creating a pointer pointing to the head
	temp->num = num;

	if (ptr)
	{
		while (ptr->next != NULL)		//traversing the list
		{
			ptr = ptr->next;
			if (ptr->num == temp->num)
			{
				return ptr->data;		//returning the string of the specific number
				break;
			}
			
		}
	}
}

string getFirstPageName(Node* head, int k)		//function to get the page name of 1st page from the position
{
	Node* temp = new Node();		//creating a new node
	Node* ptr = head;			//creating a pointer pointing at the head
	temp->key = k;

	return ptr->data;		//the string present in the head is returned
}

string getPageName(Node* head, int k)		//function to get the page name of any page from the position
{
	Node* temp = new Node();		//creating a new node
	Node* ptr = head;			//creating a pointer pointing to the head
	temp->key = k;

	if (ptr)
	{
		while (ptr->next != NULL)		//traversing the list
		{
			ptr = ptr->next;
			if (ptr->key == temp->key)
			{
				return ptr->data;		//returning the string of the specific number
				break;
			}

		}
	}
}

void menu()
{
	//*********************************************   MAIN MENU    **************************************************

	cout << "                          ******************************************************** " << endl;
	cout << "                   **************************                  ************************** " << endl;
	cout << "              **************************     ABC Flower Website     ************************** " << endl;
	cout << "                   **************************                  ************************** " << endl;
	cout << "                          ******************************************************** " << endl;
	cout << endl;
	cout << endl;
}

int main()
{
	//creating nodes of the linked list
	Node* head = new Node();
	Node* temp = new Node();
	Node* temp1 = new Node();
	Node* temp2 = new Node();
	Node* temp3 = new Node();
	Node* temp4 = new Node();

	//passing values to the nodes
	head->num = 22;
	head->data = "Rose";
	head->prev = NULL;			//head node
	head->key = 1;
	head->next = temp;

	temp->num = 37; 
	temp->key = 2;
	temp->data = "Sunflower";	//2nd node
	temp->prev = head;			
	temp->next = temp1;			
	head->next = temp;

	temp1->num = 54;
	temp1->key = 3;
	temp1->data = "Jasmine";	//3rd node
	temp1->prev = temp;
	temp1->next = temp2;		
	temp->next = temp1;

	temp2->num = 69;
	temp2->key = 4;
	temp2->data = "Iris";		//4th node
	temp2->prev = temp1;
	temp2->next = temp3;		
	temp1->next = temp2;

	temp3->num = 73;
	temp3->key = 5;
	temp3->data = "Tulips";		//5th node
	temp3->prev = temp2;
	temp3->next = NULL;			
	temp2->next = temp3;

	Node* ptr = head;		//ptr pointer pointing to the head node

	for (int i = 0; i < 10; i++)
	{
		system("cls");
		system("color 8B");		//setting color of code and the background color

		{
			for (int j = 1; j < i; j++)
			{
				cout << "\n";
			}
		}
		menu();
		Sleep(25);
	}
	Beep(3000, 500);		//for making beep sound
	Sleep(10);
	Beep(2000, 1000);

	system("cls");
	menu();

	char operation;

	do
	{
		string data;
		string y;
		int num;

		//*********************************************    MENU    **************************************************
		start:
		cout << "Select the option that you want to perform " << endl;
		cout << "   1. Insert any page " << endl;
		cout << "   2. Delete any page" << endl;
		cout << "   3. Update any page " << endl;
		cout << "   4. Display " << endl;
		cout << "   5. To display the PAGE NAME " << endl;
		cout << "   0. To End the program " << endl;
		cin >> operation;

		switch (operation)		//switch case
		{
			case '1':
				char z;
				cout << "Enter the page NAME that you want to insert in the list " << endl;
				cin >> data;

				cout << "Enter the number of IMAGES that you want to insert on the page " << endl;
				cin >> num;

				system("cls");
				menu();
				cout << "Select any option from the following " << endl;
				cout << "   1. Insert data at the beginning " << endl;
				cout << "   2. Insert data at any desired position " << endl;
				cout << "   3. Insert data at the end " << endl;
				cout << "   4. Exit to main menu " << endl;
				cin >> z;

				switch (z)		//nested switch case for insertion
				{
					case '1':	//for inserting at the start
					insertNodeAtStart(head, data, num);		//calling the function to insert the data at start
					temp4 = head;
					system("cls");
					menu();
					break;

					case '2':		//for insertion at any position
						int pos;
						cout << "Enter the position at which you want to insert the new page " << endl;
						cin >> pos;
						insertNodeAtPos(head, data, num, pos);		//calling the function to insert data at any position
						system("cls");
						menu();
						break;

					case '3':		//for insertion at the end position
						insertNodeAtEnd(head, data, num);		//calling the function to insert data at the end
						system("cls");
						menu();
						break;

					case '4':		//for moving to main menu
						system("cls");
						menu();
						goto start;
						break;
				}
				break;

			case '2':			//for deletion
				system("cls");
				menu();
				
				char op;
				
				//*********************************************    MENU    **************************************************

				cout << "Select the options from the following " << endl;
				cout << "   1. Delete 1st page " << endl;
				cout << "   2. Delete desired page " << endl;
				cout << "   3. Delete the last page " << endl;
				cout << "   4. Exit to main menu " << endl;
				cin >> op;

				switch (op)		//nested switch case for deletion
				{
					case '1':		//for deletion of head node
						deleteNodeAtStart(head);		//calling the function for deletion of head node
						system("cls");
						menu();

					case '2':		//for deletion of data at any position
						int s;

						cout << "Enter the position of the page which you want to be deleted " << endl;
						cin >> s;

						deleteNodeAtPos(head, s);		//calling the function for deletion of data at any position
						system("cls");
						menu();
						break;

					case '3':		//for deletion of the last node
						deleteLastNode(head);		//calling the function to delete the last node
						system("cls");
						menu();
						break;

					case '4':		//for moving to main menu
						system("cls");
						menu();
						goto start;
						break;
				}
				break;

			case '3':		//for updating
				int i;
				int p;

				cout << "Enter the NAME that you want to be updated in the page " << endl;
				cin >> y;

				cout << "Enter the NUMBER of IMAGES you want to be updated on the page " << endl;
				cin >> i;

				cout << "Enter the position at which you want to update the data you entered " << endl;
				cin >> p;

				updateNode(head, y, i, p);		//calling the function to update any node in the list
				system("cls");
				menu();
				break;

			case '4':		//for printing the nodes
				system("cls");
				menu();

				char d;

				//*********************************************    MENU    **************************************************

				cout << "Select the option from the following " << endl;
				cout << "   1. Print the pages in ascending order " << endl;
				cout << "   2. Print the pages in descending order " << endl;
				cout << "   3. Exit to main menu " << endl;
				cin >> d;

				switch(d)
				{
					case '1':		//for printing in ascending order
						printForward(head);		//calling the function
						break;

					case '2':		//for printing in descending order
						printBackward(head);	//calling the funtion
						break;

					case '3':		//for moving to main menu
						system("cls");
						menu();
						goto start;
						break;
				}
				break;

			case '5':		//for printing the names of the pages
				char u;

				//*********************************************    MENU    **************************************************

				cout << "Select any option " << endl;
				cout << "   1. Get NAME of page by no.of images " << endl;
				cout << "   2. Get NAME of page by page number " << endl;
				cout << "   3. Exit to main menu " << endl;
				cin >> u;

				switch (u)
				{
					case '1':		//for printing name through no.of images
						system("cls");
						menu();
						int h;

						cout << "Enter the page number whose name you want " << endl;
						cin >> h;
						cout << endl;

						cout << "The name of the Page is : ";
						if (h == head->num)
							cout << getFirstPageNameFromNumber(head, h);	  //calling the function for printing the name of 1st page

						else
							cout << getPageNameFromNumber(head, h);			//calling the function for printing name of any page

						cout << endl;
						break;

					case '2':		//for printing the name of the page through position
						system("cls");
						menu();
						int k;

						cout << "Enter the page number whose name you want to be displayed " << endl;
						cin >> k;

						cout << "The name of the Page is : ";
						if (k == head->key)
							cout << getFirstPageName(head, k);		//calling the function to print the name of the 1st page

						else
							cout << getPageName(head, k);		//calling the function to print the name of any page

						cout << endl;
						break;

					case '3':			//for moving to main menu
						system("cls");
						menu();
						goto start;
						break;
				}

				break;
		}
	} while (operation != '0');		//if user enters '0' the program will be ended

	return 0;
}