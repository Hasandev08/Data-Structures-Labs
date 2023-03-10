#include<iostream>
using namespace std;

int main()
{
	x:
	int n, fact = 1;
	char m;

	cout << "Enter the number " << endl;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		fact = fact * i;
	}

	cout << "The factorial of the number is : " << fact << endl;

	cout << "Do you want to Continue (Y/N) " << endl;
	cin >> m;

	if (m == 'Y' || m == 'y')
		goto x;

	else if (m == 'N' || m == 'n')
		return 0;

	else
		cout << "Invalid input " << endl;

	return 0;
}