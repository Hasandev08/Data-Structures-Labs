#include<iostream>																			//Header file
using namespace std; 

int deleteNum(int *arr, int SIZE)															//function to delete the number
{
	int index;
	
	cout << "Enter the index of the number to be deleted " << endl;							//asking the user to enter the index of the number to be deleted
	cin >> index;
	
	int *a = new int[SIZE-1];
	
	for (int i = 0; i < index; i++)															//decreasing a number from the array and storing it in another array
		a[i] = arr[i];
		
	for (int i = index; i <= SIZE; i++)														//moving the other elements to cover the space of deleted element
		a[i] = arr[i+1];
		
	for (int i = 0; i < SIZE-1; i++)														//moving the updated array back in original array
		arr[i] = a[i];
		
	return *arr;		
}

int main()
{
	int SIZE;
	int* arr = new int[SIZE];																//dynamic array
	
	cout << "Enter the size of the array " << endl;											//asking the size of array from user
	cin >> SIZE;
	
	cout << endl;
	
	cout << "Enter the elements of the array " << endl;										//asking to input the elements of array from user
	for (int i = 0; i < SIZE; i++)
	{
		cin >> arr[i];
	}
	
	cout << endl;
	
	cout << "The original array is : ";												
	for (int i = 0; i < SIZE; i++)
	{																						//printing the original array
		cout << arr[i] << " ";
	}
	
	cout << endl;
	cout << endl;
	
	deleteNum(arr, SIZE);																	//calling the function
	
	cout << endl;
	
	cout << "The Updated array is : ";
	for (int i = 0; i < SIZE-1; i++)
	{
		cout << arr[i] << " ";																//printing the updated array
	}
	
	delete arr;
	
	return 0;
}
