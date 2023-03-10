#include<iostream>
using namespace std;

int main()
{
	int arr[5] = { 145,122,323,434,545 };
	int n;

	cout << "Enter the number whose location is to be displayed " << endl;
	cin >> n;
	cout << endl;

	for (int i = 0; i < 5; i++)
	{
		if (arr[i] == n)
		{
			cout << "The location is : " << (i + 1) << endl;
			break;
		}

		if (i==4)
			cout << "The value doesn't exist in the array " << endl;
	}
	
	return 0;
}
