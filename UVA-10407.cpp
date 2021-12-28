#include <iostream>
#include <string>
#include <cmath>
using namespace std;

#define ll long long

int gcd(int x, int y)
{
	if (!x)
		return y;
	if (!y)
		return x;
	int t;
	while (x % y)
	{
		t = x;
		x = y;
		y = t % y;
	}
	return y;
}


int main()
{
	int n[1000] = { 0 };
	int pos = 0, diff, final;
	cin >> n[pos++];
	while (n[0] != 0)
	{
		while (cin >> n[pos])
		{
			if (n[pos] == 0)
			{
				break;
			}
			pos++;
		}
		final = abs(n[0] - n[1]);
		for (int i = 2; i < pos; i++)
		{
			final = gcd(final, abs(n[i] - n[i - 1]));
		}
		cout << final << endl;
		pos = 0;
		cin >> n[pos++];
	}
	return 0;
}