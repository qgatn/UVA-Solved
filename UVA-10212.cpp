#include <iostream>
using namespace std;

#define ll long long

int main()
{
    ll d, n, m, lim;
    while (cin >> n >> m)
    {
        if (m == 0)
        {
            cout << 1 << endl;
        }
        else
        {
            d = 1;
            lim = n - m + 1;
            for (ll i = n; i >= lim; i--)
            {
                d *= i;
                while (d % 10 == 0)
                {
                    d /= 10;
                }
                d %= 1000000000;
            }
            cout << d % 10 << endl;
        }
    }
    return 0;
}