#include <iostream>
using namespace std;

int fib[1002][250];

void calc()
{
	fib[0][0] = 1;
	fib[1][0] = 1;
	int c = 0;
	for (int i = 2; i < 1002; i++)
	{
		for (int j = 0; j < 250; j++)
		{
			fib[i][j] = fib[i - 1][j] + fib[i - 2][j] + c;
			c = fib[i][j] / 10;
			fib[i][j] = fib[i][j] % 10;
		}
	}
}

int main()
{
	for (int i = 0; i < 1002; i++)
	{
		for (int j = 0; j < 250; j++)
		{
			fib[i][j] = 0;
		}
	}
	calc();
	int n, k;
	while (cin >> n)
	{
		k = 1;
		for (int i = 249; i >= 0; i--)
		{
			if (fib[n + 1][i] != 0)
			{
				k = 0;
			}
			if (k == 0)
			{
				cout << fib[n + 1][i];
			}
		}
		cout << endl;
	}
}