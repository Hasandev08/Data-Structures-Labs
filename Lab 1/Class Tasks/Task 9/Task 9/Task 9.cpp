#include<iostream>
using namespace std;

void operation(int x, int y)
{
	char u;

	cout << "Enter the operation to be performed (+,-,*,/) " << endl;
	cin >> u;

	switch (u)
	{
		case '+':
			cout << "The result of the arithmetic operation is : " << x + y;
			break;

		case '-':
			cout << "The result of the arithmetic operation is : " << x - y;
			break;

		case '*':
			cout << "The result of the arithmetic operation is : " << x * y;
			break;

		case '/':
			cout << "The result of the arithmetic operation is : " << x / y;
			break;
	}
}

int main()
{
	int a, b;

	cout << "Enter the 1st value " << endl;
	cin >> a;

	cout << "Enter the 2nd value " << endl;
	cin >> b;
 
	operation(a, b);

	cout << endl;

	return 0;
}