#include <iostream>
using namespace std;

struct Node 
{                                           
    int data;                                           
    struct Node* link;                                 
};

Node *front = NULL;
Node *tail = NULL;                           

Node* Enque(int x) 
{                                    
	Node* temp = new Node;                              
    temp->data = x;                                     
    temp->link = NULL;                                  

    if (front == NULL && tail == NULL) 
	{                 
        front = tail = temp;                            
    }
    
    else 
	{
        tail->link = temp;                              
        tail = temp;                                    
    }
    
    return front;
}

void Deque() 
{                                          
    Node* temp = front;
    
    if (front == tail) 
	{                                
        front = NULL;
        tail = NULL;
    }
    
    else 
	{
        front = temp->link;                             
        temp->link = NULL;                              
    }
    
    delete(temp);                                       
}

int Front() 
{                                          
    return front->data;
}

void Display() 
{                                       
    Node* temp;
    temp = front;

    while (temp != NULL) 
	{                              
        cout << temp->data << "\t";
        temp = temp->link;
    }
    
    cout << endl;
}

int main()
{
    int x;
	char option;                                       
	
    do 
	{
		cout << "Select your option:" << endl;
    	cout << "   1. Insert a node in queue " << endl;
    	cout << "   2. Delete a node in queue " << endl;
    	cout << "   3. Display front" << endl;
    	cout << "   4. Display " << endl;
    	cout << "   0. Exit " << endl;
  	 	cin >> option;
  	 	
  	 	switch(option)
  	 	{
  	 		case '1':
  	 			system("cls");
  	 			cout << "Enter the number you want to insert in queue : ";
            	cin >> x;
            	Enque(x);
            	system("cls");
            	break;
            	
            case '2':
            	system("cls");
            	Deque();
            	system("cls");
            	break;
            	
            case '3':
            	system("cls");
            	cout << "The front element is : " << Front() << endl;
            	cout << endl;
            	break;
            	
            case '4':
            	system("cls");
            	Display();
            	cout << endl;
            	break;
            	
            case '0':
				return 0;
		}

    }while(option != 0);                                 
	
	return 0;               
}
