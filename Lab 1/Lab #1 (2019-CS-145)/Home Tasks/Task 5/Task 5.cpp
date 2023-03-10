#include<iostream>
using namespace std;

int main()
{
	int mangoes[1];
	int orange[1];
	int banana[1];
	int x = 0, y = 0, z = 0;
	int total;

	cout << "Enter the number of times mangoes are purchased " << endl;
	cin >> mangoes[1];

	cout << "Enter the number of times oranges are purchased " << endl;
	cin >> orange[1];

	cout << "Enter the number of times bananas are purchased " << endl;
	cin >> banana[1];
	cout << endl;

	for (int i = 0; i < mangoes[1]; i++)
	{
		x += 20;
	}

	for (int i = 0; i < orange[1]; i++)
	{
		y += 10;
	}

	for (int i = 0; i < banana[1]; i++)
	{
		z += 5;
	}

	total = x + y + z;

	cout << "*****************************************************************************" << endl;
	cout << "Customer No." << "\t" << "Mangoes" << "\t\t" << "Oranges" << "\t\t" << "Bananas" << "\t\t" << "Total Bill" << endl;
	cout << "*****************************************************************************" << endl;
	cout << "     1" << "\t\t" << "   " << mangoes[1] << "\t\t" << "   " << orange[1] << "\t\t" << "   " << banana[1] << "\t\t" << "   " << total << endl;

	return 0;
}