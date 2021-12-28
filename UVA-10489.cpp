#include <iostream>
#include <string>
using namespace std;

#define ll long long

int main()
{
	int t;
	ll n, m, temp, x, c, ans;
	cin >> t;
	while (t--)
	{
		ans = 0;
		cin >> n >> m;
		while (m--)
		{
			temp = 1;
			cin >> x;
			while (x--)
			{
				cin >> c;
				temp *= c;
				temp %= n;
			}
			ans += temp;
			ans %= n;
		}
		cout << ans << endl;
	}
	return 0;
}