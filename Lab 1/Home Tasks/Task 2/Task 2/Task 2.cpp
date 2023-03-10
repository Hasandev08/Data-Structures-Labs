#include<iostream>
using namespace std;

void addFractions(int a, int b, int c, int d, int& result1, int& result2)
{
	result1 = (a * d) + (b * c);
	result2 = (b * d);
}

void subtractFractions(int a, int b, int c, int d, int& result1, int& result2)
{
	result1 = (a * d) - (b * c);
	result2 = (b * d);
}

void multiplyFractions(int a, int b, int c, int d, int& result1, int& result2)
{
	result1 = (a * c);
	result2 = (b * d);
}

void divideFractions(int a, int b, int c, int d, int& result1, int& result2)
{
	result1 = (a * d);
	result2 = (b * c);
}

void menu()
{
	cout << "------------------------------------------------------" << endl;
	cout << "------------------Fraction Calculator-----------------" << endl;
	cout << "------------------------------------------------------" << endl;
}

int main()
{
	menu();

	int a, b, c, d, x, result1=1, result2=1;
	char n;

	z:
	cout << "Enter the numerator 1 " << endl;
	cin >> a;

	cout << "Enter the denominator 1 " << endl;
	cin >> b;

	cout << "Enter the numerator 2 " << endl;
	cin >> c;

	cout << "Enter the denominator 2 " << endl;
	cin >> d;
	cout << endl;

	cout << "1st Fraction is : " << a << "/" << b << endl;
	cout << "2nd Fraction is : " << c << "/" << d << endl;
	cout << endl;

	cout << "Press the button for operations accordingly " << endl;
	cout << "1. For addition " << endl;
	cout << "2. For subtraction " << endl;
	cout << "3. For multiplication " << endl;
	cout << "4. For division " << endl;
	cout << "5. End program " << endl;
	cin >> x;

	switch (x)
	{
		case 1:
			addFractions(a, b, c, d, result1, result2);
			cout << "The result is : " << result1 << "/" << result2 << endl;
			break;

		case 2:
			subtractFractions(a, b, c, d, result1, result2);
			cout << "The result is : " << result1 << "/" << result2 << endl;
			break;

		case 3:
			multiplyFractions(a, b, c, d, result1, result2);
			cout << "The result is : " << result1 << "/" << result2 << endl;
			break;

		case 4:
			divideFractions(a, b, c, d, result1, result2);
			cout << "The result is : " << result1 << "/" << result2 << endl;
			break;

		case 5:
			return 0;
	}

	cout << "Do you want to continue (Y/N) " << endl;
	cin >> n;

	if (n == 'Y' || n == 'y')
		goto z;

	else if (n == 'N' || n == 'n')
		return 0;

	else
		cout << "Invalid input ";

	return 0;
}