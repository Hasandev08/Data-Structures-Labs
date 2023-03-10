#include<iostream>
using namespace std;

int binarySearch(int arr[], int start, int end, int x)
{
	if (start > end)
	{
		return -1;
	}
	
	int mid = ((start + end) / 2);
	
	if (x == arr[mid])
		return mid;
		
	else if (x < arr[mid])
		return binarySearch(arr, start, (mid - 1), x);
		
	else
		return binarySearch(arr, (mid + 1), end, x);		
}

int main()
{
	int arr[5];
	int num;
	int output;
	int start = 0;
	int end = 4;

	cout << "Enter the entities of array in ascending order " << endl;
	for (int i = 0; i < 5; i++)
		cin >> arr[i];

	system("cls");

	cout << "The entered array is : ";
	for (int i = 0; i < 5; i++)
		cout << arr[i] << " ";

	cout << endl;
	cout << endl;

	cout << "Enter the number that you want to search from the array " << endl;
	cin >> num;

	output = binarySearch(arr, start, end, num);

	cout << "The number is at position (starting from 0) : " << output << endl;
		
	return 0;
}
