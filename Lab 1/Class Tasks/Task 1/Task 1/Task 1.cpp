#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	double a, b, c;
	double s, area, result;

	cout << "Enter the values of all three sides " << endl;
	cin >> a >> b >> c;
	cout << endl;

	s = (a + b + c) / 2;

	area = s * (s - a) * (s - b) * (s - c);
	result = sqrt(area);

	cout << "The area is : " << result << endl;

	return 0;
}