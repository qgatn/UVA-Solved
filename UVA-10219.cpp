#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    unsigned long long n, k;
    while (cin >> n >> k)
    {
        long double num = 0;
        for (unsigned long long i = n - k + 1; i <= n; ++i)
        {
            num += log10((double)i);
        }
        for (unsigned long long i = 1; i <= k; ++i)
        {
            num -= log10((double)i);
        }
        cout << (int)num + 1 << endl;
    }
    return 0;
}