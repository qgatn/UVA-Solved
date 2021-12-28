#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <cstdlib>
using namespace std;

int f[30];
int primes[50000] = { 0 };
int p[50000] = { 0 };

int main()
{
	int pos = 0;
	p[0] = 1; p[1] = 1;
	for (int i = 2; i < 50000; ++i)
	{
		if (!p[i])
		{
			primes[pos++] = i;
			for (int j = 2 * i; j < 50000; j += i)
				p[j] = 1;
		}
	}
	int n;
	while (cin >> n && n)
	{
		int ct = 0, x = 0, m = n;
		while (n > 1 && x < pos)
		{
			if (n % primes[x] == 0)
			{
				f[ct++] = primes[x];
				while (n % primes[x] == 0)
				{
					n /= primes[x];
				}
			}
			x++;
		}
		if (n > 1) f[ct++] = n;
		long long fin = m;
		for (int i = 0; i < ct; ++i)
		{
			fin = fin / f[i] * (f[i] - 1);
		}
		cout << fin << endl;
	}
	return 0;
}