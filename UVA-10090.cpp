#include <iostream>
#include <string>
#include <cmath>
using namespace std;

#define ll long long

ll x, y, d;

void eeu(ll a, ll b)
{
	if (b == 0)
	{
		x = 1;
		y = 0;
		d = a;
	}
	else
	{
		eeu(b, a % b);
		ll x1 = y;
		ll y1 = x - (a / b) * y;
		x = x1;
		y = y1;
	}
}


int main()
{
	ll n, c1, c2, n1, n2, cnt1, cnt2, p1, p2, final;
	while (cin >> n >> c1 >> n1 >> c2 >> n2)
	{
		eeu(n1, n2);
		if (n % d != 0)
		{
			cout << "failed" << endl;
		}
		else
		{
			cnt1 = (ll)ceil(-(double)x * n / n2);
			cnt2 = (ll)floor((double)y * n / n1);
			if (cnt2 < cnt1)
			{
				cout << "failed" << endl;
			}
			else
			{
				p1 = (n / d) * (c1 * x + c2 * y) + cnt1 * (c1 * n2 - c2 * n1) / d;
				p2 = (n / d) * (c1 * x + c2 * y) + cnt2 * (c1 * n2 - c2 * n1) / d;
				if (p1 < p2)
				{
					final = cnt1;
				}
				else
				{
					final = cnt2;
				}
				cout << ((x * n) + (n2 * final)) / d << " " << ((y * n) - (n1 * final)) / d << endl;
			}
		}
	}
}