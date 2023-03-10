#include<iostream>
#include<windows.h>		//Header files
#include<stdlib.h>
using namespace std;

struct Node		//declaring struct to create nodes in the link list
{
	int data;	//1st part of linked list storing data														
	Node* next;	//2nd part of lined list that points to the next node
};
