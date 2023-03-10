#include<iostream>
using namespace std;

int main()
{
	int dividend, divisor, quotient, remainder;
	char x;

	a:
	cout << "Enter the dividend " << endl;
	cin >> dividend;

	cout << "Enter the divisor " << endl;
	cin >> divisor;

	quotient = dividend / divisor;
	remainder = dividend % divisor;

	cout << "The quotient is : " << quotient << endl;
	cout << "The remainder is : " << remainder << endl;

	cout << "Do you want to continue (Y/N) " << endl;
	cin >> x;

	if (x == 'Y' || x == 'y')
		goto a;

	else if (x == 'N' || x == 'n')
		return 0;

	else
		cout << "Invalid input " << endl;

	return 0;
}