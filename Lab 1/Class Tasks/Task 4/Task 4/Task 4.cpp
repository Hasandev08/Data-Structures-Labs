#include<iostream>
using namespace std;

int main()
{
	int n, flag = 0, m = 0;

	cout << "Enter the number " << endl;
	cin >> n;

	m = n / 2;

	for (int i = 2; i <= m; i++)
	{
		if (n % i == 0)
		{
			cout << "The number is not prime " << endl;
			flag = 1;
			break;
		}
	}

	if (flag == 0)
	{
		cout << "The number is prime " << endl;
	}

	if (n % 2 == 0)
		cout << "The number is even " << endl;

	else
		cout << "The number is odd " << endl;

	return 0;
}