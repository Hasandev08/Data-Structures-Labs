#include<iostream>
using namespace std;

int binarySearch(int arr[], int num)
{
	int start = 0;
	int end = 9;

	while (start <= end)
	{
		int mid = ((start + end) / 2);

		if (arr[mid] == num)
			return mid;

		else if (arr[mid] < num)
			start = mid + 1;

		else 
			end = mid - 1;
	}

	return -1;
}

int main()
{
	int arr[10];
	int num;
	int output;

	cout << "Enter the entities of array in ascending order " << endl;
	for (int i = 0; i < 10; i++)
		cin >> arr[i];

	system("cls");

	cout << "The entered array is : ";
	for (int i = 0; i < 10; i++)
		cout << arr[i] << " ";

	cout << endl;
	cout << endl;

	cout << "Enter the number that you want to search from the array " << endl;
	cin >> num;

	output = binarySearch(arr, num);

	if (output == -1)
		cout << "The number is not present in the array " << endl;

	else
		cout << "The number is at position : " << output << endl;
		
	return 0;
}