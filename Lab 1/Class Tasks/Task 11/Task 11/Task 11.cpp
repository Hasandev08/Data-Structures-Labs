#include<iostream>
using namespace std;

void function()
{
	static int i = 0;

	for (int j = 0; j < 5; j++)
	{
		i++;
		cout << i << " ";
	}
}

int main()
{
	function();
	
	return 0;
}
