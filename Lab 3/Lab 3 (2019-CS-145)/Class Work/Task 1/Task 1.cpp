#include<iostream>																				//Header file
using namespace std;

int addValue(int SIZE, int arr[], int x)
{
	for (int i = SIZE; i < SIZE+1; i++)															//function for adding the element in the array
		arr[SIZE] = x;	
}

int main()
{
	int SIZE;
	int* arr = new int[SIZE];																	//declaring a dynamic array
	int x;

	cout << "Enter the size of the array " << endl;												//asking the size of array
	cin >> SIZE;

	cout << "Enter " << SIZE << " elements of the array " << endl;
	for (int i = 0; i < SIZE; i++)																//asking the elements of the array
		cin >> arr[i];
	
	cout<<"Original Array= ";
	for (int i = 0; i < SIZE; i++)																//printing the original array
		cout << arr[i] << " ";
	
	cout << endl;
	cout << endl;

	cout << "Enter the number to be added in the array " << endl;								//asking the user to add the number to be added in the array
	cin >> x;
	
	cout << "Updated Array : ";	
	addValue(SIZE, arr, x);																		//calling the function
	
	for(int i = 0; i < SIZE+1; i++)											
		cout << arr[i] << " ";																	//printing the updated array
		
	delete arr;
		
	return 0;	 
}
