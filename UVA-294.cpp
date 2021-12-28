#include <iostream>
#include <stack> 
#include <math.h>
#include <cstdlib> 
#include <algorithm>  
#include <vector>
using namespace std;

int sd(int x)
{
    if (x == 1) return 1;
    int  i, ans = 2, sq = sqrt(x);
    for (i = 2; i <= sq; i++)
    {
        if (x % i == 0)
        {
            if (i * i == x)
            {
                ans += 1;
            }
            else
            {
                ans += 2;
            }

        }
    }
    return ans;
}

int main()
{
    int t, l, u, mi, md, d;
    cin >> t;
    int* lo = new int[t];
    int* hi = new int[t];
    for (int i = 0; i < t; i++)
    {
        cin >> lo[i] >> hi[i];
    }
    for (int i = 0; i < t; i++)
    {
        mi = 0; md = 0;
        l = lo[i]; u = hi[i];
        for (int i = l; i <= u; i++)
        {
            d = sd(i);
            if (d > md)
            {
                md = d; mi = i;
            }
        }
        cout << "Between " << l << " and " << u << ", " << mi << " has a maximum of " << md << " divisors." << endl;
    }
    return 0;
}