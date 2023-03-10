#include<iostream>
using namespace std;

void insertionSort(int arr[], int n)
{
	for (int i = 1; i < n - 1; i++)
	{
		int value = arr[i];
		int hole = i;
		
		while (hole > 0 && arr[hole - 1] > value)
		{
			arr[hole] = arr[hole-1];
			hole--;
		}
		
		arr[hole] = value;
	}
}

int main()
{
	int arr[5];
	
	cout << "Enter the entities of array " << endl;
	for (int i = 0 ; i < 5; i++)
		cin >> arr[i];
		
	insertionSort(arr, 5);
	
	for (int i = 0; i < 5; i++)
		cout << arr[i] << " ";
		
	return 0;		
}
