#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <queue>
#include <string>
#include <iostream>
using namespace std;

#define ll unsigned long long
#define pb push_back
#define pop pop_back
vector<int> f;

ll gcd(ll x, ll y)
{
	if (!x)
		return y;
	if (!y)
		return x;
	ll t;
	while (x % y)
	{
		t = x;
		x = y;
		y = t % y;
	}
	return y;
}

ll lcm(ll a, ll b)
{
	return ((a * b) / gcd(a, b));
}

int main()
{
	ll n, p;
	cin >> n;
	while (n != 0)
	{
		f.clear();
		p = 0;
		for (ll i = 1; i <= (ll)sqrt(n); i++)
		{
			if (n % i == 0)
			{
				f.pb(i);
				f.pb(n / i);
			}
		}
		if ((ll)sqrt(n) * (ll)sqrt(n) == n)
		{
			f.pop();
		}
		for (ll i = 0; i < f.size(); i++)
		{
			for (ll j = i; j < f.size(); j++)
			{
				if (lcm(f[i], f[j]) == n)
					p++;
			}
		}
		cout << n << " " << p << endl;
		cin >> n;
	}
}