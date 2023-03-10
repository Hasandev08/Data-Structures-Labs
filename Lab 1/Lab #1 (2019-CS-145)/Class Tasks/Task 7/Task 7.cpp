#include<iostream>
using namespace std;
int main()
{
	int numbers[5];
	int squares[5];
	int cubes[5];
	int sum[5];
	int total = 0;

	cout << "Enter the elements of arrays " << endl;
	for (int i = 0; i < 5; i++)
		cin >> numbers[i];

	cout << "Numbers: ";
	for (int i = 0; i < 5; i++)
		cout << numbers[i] << " ";

	cout << endl;

	for (int i = 0; i < 5; i++)
		squares[i] = numbers[i] * numbers[i];

	cout << "Squares: ";
	for (int i = 0; i < 5; i++)
		cout << squares[i] << " ";

	cout << endl;

	for (int i = 0; i < 5; i++)
		cubes[i] = squares[i] * numbers[i];

	cout << "Cube: ";
	for (int i = 0; i < 5; i++)
		cout << cubes[i] << " ";

	cout << endl;

	for (int i = 0; i < 5; i++)
		sum[i] = numbers[i] + squares[i] + cubes[i];

	cout << "Sum: ";
	for (int i = 0; i < 5; i++)
		cout << sum[i] << " ";

	cout << endl;

	for (int i = 0; i < 5; i++)
		total = total + sum[i];

	cout << "Grand Total : " << total << endl;

	return 0;
}