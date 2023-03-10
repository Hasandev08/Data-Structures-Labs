#include <iostream>
#include<queue>
#include<limits>
using namespace std;

struct Node 
{
    int data;
    Node *left;
    Node *right;
};

Node* newNode(int data)
{
    Node* ptr = new Node();
    ptr->data = data;
    ptr->left = NULL;
    ptr->right = NULL;
    
    return ptr;
}

//----------------------------------------------INSERT A NODE IN TREE---------------------------------------------

Node* insert(Node* root, int d) 
{
    if (root == NULL) 
	{
        root = newNode(d);
    }
    
    else if (d <= root->data) 
	{
        root->left = insert(root->left, d);
    }
    
    else 
	{
        root->right = insert(root->right, d);
    }
    
    return root;
}

//------------------------------------------------SEARCH A NODE-------------------------------------------------

bool search(Node* root, int d) 
{
    if (root == NULL) 
	{
        return false;
    }
    
    else if (root->data == d) 
	{
        return true;
    }
    
    else if (d <= root->data) 
	{
        return search(root->left, d);
    }
    
    else 
	{
        return search(root->right, d);
    }
}

Node* find(Node* root, int d) 
{
    if (root == NULL) 
	{
        return NULL;
    }
    
    else if (root->data == d) 
	{
        return root;
    }
    
    else if (d <= root->data) 
	{
        return find(root->left, d);
    }
    
    else 
	{
        return find(root->right, d);
    }
}


//-----------------------------------------------FIND MINIMUM-------------------------------------------

int find_min(Node* root)			// iterative function 
{            
    if (root == NULL) 
	{
        cout << "The tree is empty." << endl;
        return -1;
    }
    
    Node* current = root;

    while (current->left != NULL) 
	{
        current = current->left;
    }
    
    return current->data;
}

int findmin(Node* root) 				//recursive function
{            
	if (root == NULL) 
	{
        cout << "The tree is empty." << endl;
        return -1;
    }
    
    Node* current = root;

    if (current->left == NULL)
	{
        return current->data;
    }
    
    return findmin(current->left);
}

Node* Find_Min(Node* root) 
{            
    if (root == NULL) 
	{
        cout << "The tree is empty." << endl;
        return NULL;
    }
    
    Node* current = root;

    if (current->left == NULL) 
	{
        return current;
    }
    
    return Find_Min(current->left);
}

//---------------------------------------------HEIGHT OF A TREE-----------------------------------------
int height(Node* root) 
{
    if (root == NULL) 
	{
        return -1;
    }
    
    else 
	{
		int left;
		int right;
		
        left = height(root->left);
        right = height(root->right);
        
        return max(left,right) + 1;
    }
}

//--------------------------------------------LEVEL-ORDER TRAVERSAL--------------------------------------

void level_order(Node* root) 
{
    if (root == NULL) 
	{
        return;
    }
    
    queue<Node*> Q;
    Q.push(root);

    while (!Q.empty()) 
	{
        Node* current = Q.front();
        cout << current->data << "  ";
        
        if (current->left != NULL) 
		{
            Q.push(current->left);
        }
        
        if (current->right != NULL) 
		{
            Q.push(current->right);
        }
        
        Q.pop();
    }
}

//---------------------------------------DEPTH-FIRST TRAVERSING-------------------------------

void preorder(Node* root) 
{
    if (root == NULL) 
	{
        return;
    }
    
    cout << root->data << "  ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root) 
{
    if (root == NULL) 
	{
        return;
    }
    
    inorder(root->left);
    cout << root->data << "  ";
    inorder(root->right);
}

void postorder(Node* root) 
{
    if (root == NULL) 
	{
        return;
    }
    
    postorder(root->left);
    postorder(root->right);
    cout << root->data << "  ";
}

//-----------------------------------IF A GIVEN BINARY TREE IS BINARY SEARCH TREE---------------------------//

bool isSubTreeLesser(Node* root, int value) 
{    
    if (root == NULL) 
	{
        return true;
    }
    
    if (root->data <= value && isSubTreeLesser(root->left, value) && isSubTreeLesser(root->right, value)) 
	{
        return true;
    }
    
    else 
	{
        return false;
    }
}

bool isSubTreeGreater(Node* root, int value) 
{   
    if (root == NULL) 
	{
        return true;
    }
    
    if (root->data > value && isSubTreeGreater(root->left, value) && isSubTreeGreater(root->right, value)) 
	{
        return true;
    }
    
    else 
	{
        return false;
    }
}

bool isbst(Node* root) 
{     
    if (root == NULL) 
	{
        return true;
    }
    
    if (isSubTreeLesser(root->left, root->data) && isSubTreeGreater(root->right, root->data) && isbst(root->left) && isbst(root->right)) 
	{   
        return true;
    }
    
    else 
	{
        return false;
    }
}

bool bstutil(Node* root, int minValue, int maxValue) 
{    
    if (root == NULL) 
	{
        return true;
    }
    
    if (root->data <= minValue && root->data > maxValue && bstutil(root->left, minValue, root->data) && bstutil(root->right, root->data, maxValue)) 
	{   
        return true;
    }
    
    else 
	{
        return false;
    }
}

bool bst(Node* root) 
{   
    return bstutil(root, INT_MIN, INT_MAX); 
}

//----------------------------------------------DELETING A NODE-------------------------------------------//

Node* deleteNode(Node* root, int data) 
{
    if (root == NULL) 
	{     
        return root;
    }
    
    else if (data < root->data) 
	{       
        root->left = deleteNode(root->left, data);
    }
    
    else if (data > root->data) 
	{   
        root->right = deleteNode(root->right, data);
    }
    
    else 
	{
        if (root->left == NULL && root->right == NULL) 
		{      
        	delete root;
          	root = NULL;
        }
        
        else if (root->left == NULL) 
		{        
            Node* temp = root;
            root = root->right;
            delete temp;
        }
        
        else if (root->right == NULL) 
		{      
            Node* temp = root;
            root = root->left;
            delete temp;
        }
        
    	else 
		{            
            Node* temp;
            temp->data = findmin(root->right);    
            root->data = temp->data;              
        	root->right = deleteNode(root->right, temp->data);   
        }
    }
  
    return root;
}

//-----------------------------------   INORDER SUCCESSOR   -------------------------------//

Node* GetSuccessor(Node* root, int data) 
{
    Node* current = find(root, data);

    if (current == NULL) 
	{
        return NULL;
    }
    
    if (current->right != NULL) 
	{
        return Find_Min(current->right);
    }
    
    else 
	{
        Node* successor = NULL;
        Node* ancestor = root;
        
        while (ancestor != current) 
		{
            if (current->data < ancestor->data) 
			{
                successor = ancestor;
                ancestor = ancestor->left;
            }
            
            else 
			{
                ancestor = ancestor->right;
            }
        }
        
        return successor;
    }
}

//----------------------------------------------MAIN FUNCTION---------------------------------------

int main()
{
    Node* root = NULL;
    int num;
    int data;
    
    cout << "Enter the number of BINARY SEARCH TREE nodes you want : ";
    cin >> num;

    cout << "Enter the data : " << endl;
    for (int i = 0; i < num; i++) 
	{
        cin >> data;
        root = insert(root, data);
    }

    cout << endl;
    
    int num1;
    
    cout << "Enter the number you want to search : " << endl;
    cin >> num1;
    
    if (search(root, num1) == true) 
	{
        cout << "The Number is present in the Binary Search Tree " << endl;
    }
    
    else 
	{
        cout << "The Number is not present in the Binary Search Tree " << endl;
    }
    
    cout << endl;

    cout << "Minimum number of the tree is : " << findmin(root) << endl;
    cout << "Height of the tree is : " << height(root) << endl;
    
    return 0;
}
