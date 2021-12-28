#include <iostream>
#include <string>
#include <algorithm> 
using namespace std;

#define ll long long

ll gcd(ll a, ll b)
{
	if (a % b == 0)
	{
		return b;
	}
	else
	{
		return gcd(b, a % b);
	}
}

int main()
{
	int p, t = 0, m, d;
	int temp;
	string s, a;
	int n[100];
	getline(cin, a);
	for (int i = 0; i < a.length(); i++)
	{
		t = (t * 10) + ((int)a[i] - '0');
	}
	for (int i = 0; i < t; i++)
	{
		p = 0;
		temp = 0;
		m = 0;
		getline(cin, s);
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] == ' ' || i == s.length() - 1)
			{
				if (i == s.length() - 1)
				{
					temp = (temp * 10) + ((int)s[i] - '0');
				}
				n[p++] = temp; temp = 0;
			}
			else
			{
				temp = (temp * 10) + ((int)s[i] - '0');
			}
		}
		for (int i = 0; i < p - 1; i++)
		{
			for (int j = i + 1; j < p; j++)
			{
				d = gcd(n[i], n[j]);
				m = (d > m) ? d : m;
			}
		}
		cout << m << endl;
	}
	return 0;
}