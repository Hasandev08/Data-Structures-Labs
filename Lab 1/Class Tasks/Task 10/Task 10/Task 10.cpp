#include<iostream>
using namespace std;

int Area(double b, double h)
{
	int area;

	area = 0.5 * b * h;

	return area;
}

int main()
{
	double b, h;

	cout << "Enter the base of the triangle " << endl;
	cin >> b;

	cout << "Enter the height of the triangle " << endl;
	cin >> h;

	cout << endl;

	cout << "The area of the triangle is : " << Area(b, h) << endl;

	return 0;
}