#include <iostream>
#include <string>
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
	ll a, b;
	while (cin >> a >> b)
	{
		eeu(a, b);
		cout << x << " " << y << " " << d << endl;
	}
}