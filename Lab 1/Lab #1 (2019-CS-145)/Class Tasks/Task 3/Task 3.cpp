#include<iostream>
using namespace std;

void function(int x, int y)
{
	if (x > y)
		cout << "The bigger number is : " << x << endl;

	else if (x == y)
		cout << "The numbers are equal " << endl;

	else
		cout << "The bigger number is : " << y << endl;
}

int main()
{
	int a, b;
	double length, radius, space, trees, l, n;
	cout << "Enter the 1st number " << endl;
	cin >> a;

	cout << "Enter the 2nd number " << endl;
	cin >> b;

	cout << endl;

	function(a, b);

	cout << endl;

	cout << "------------------------------2nd part of question----------------------------" << endl;

	cout << "Enter the length " << endl;
	cin >> length;

	cout << "Enter the radius " << endl;
	cin >> radius;

	cout << "Enter the space " << endl;
	cin >> space;

	l = (2 * radius) + space;
	n = length - space;

	trees = (n - l) * 4;

	cout << "The total trees are : " << trees << endl;

	space = trees * (2 * radius);

	cout << "The space occupied by trees is : " << space << endl;

	return 0;
}
