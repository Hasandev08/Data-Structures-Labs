#include<iostream>
using namespace std;

void bubbleSort(int arr[], int n)
{
	for (int j = 1; j < n - 1; j++)
	{
		int flag = 0;
		
		for (int i = 0; i < n - j - 1; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				int temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
				flag = 1;
			}
		}
		
		if (flag == 0)
			break;
	}
}

int main()
{
	int arr[5];
	
	cout << "Enter the entities of array " << endl;
	for (int i = 0 ; i < 5; i++)
		cin >> arr[i];
		
	bubbleSort(arr, 5);
	
	for (int i = 0; i < 5; i++)
		cout << arr[i] << " ";
		
	return 0;		
}
