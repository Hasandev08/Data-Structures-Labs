#include<iostream>
using namespace std;

int arr[20][20];

void display(int val1)
{
	for (int i = 0; i < val1; i++)
	{
		for (int j = 0; j < val1; j++)
		{
			cout << arr[i][j] << " ";
		}
		
		cout << endl;
	}
}

void adjacencyMatrix(int val, int val1)
{
	arr[val][val1] = 1;
	arr[val1][val] = 1;
}

int main()
{
	int value = 6;
	
	adjacencyMatrix(0, 2);
	adjacencyMatrix(4, 1);
	adjacencyMatrix(3, 2);
	adjacencyMatrix(5, 3);
	adjacencyMatrix(4, 2);
	
	display(value);
	
	return 0;
}
