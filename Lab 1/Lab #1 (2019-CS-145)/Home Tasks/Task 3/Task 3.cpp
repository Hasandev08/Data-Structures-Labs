#include<iostream>
using namespace std;

int main()
{
	int arr[10], i, j = 1, k = 1, l = 1;
	int backup[10];

	cout << "Enter the data of Hard Drives " << endl;
	for (int i = 0; i < 10; i++)
	{
		cin >> arr[i];
	}

	cout << "The Data of all 10 drives is : " << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << "Drive # " << j << " = " << arr[i] << endl;
		j++;
		backup[i] = arr[i];
	}
	
	cout << endl;

	cout << "Enter the position of the file that is corrupted " << endl;
	cin >> i;
	cout << endl;
	arr[i] = -1;

	cout << "Displaying the corrupted drive : " << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << "Drive # " << k << " = " << arr[i] << endl;
		k++;
	}

	cout << endl;

	arr[i] = backup[i];

	cout << "After restoring the data from backup " << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << "Drive # " << l << " = " << arr[i] << endl;
		l++;
	}

	return 0;
}