#include <iostream>
#include <stack> 
#include <math.h>
#include <cstdlib> 
#include <algorithm>  
#include <vector>
using namespace std;

int ans[1001] = { 0 };

int sd(int x)
{
    if (x == 1) return 1;
    int  i, ans = 1, sq = sqrt(x);
    for (i = 2; i <= sq; i++)
    {
        if (x % i == 0)
        {
            if (i * i == x)
            {
                ans += i;
            }
            else
            {
                ans += i + x / i;
            }

        }
    }
    return ans + x;
}

int main()
{
    int t, n, cs = 1;
    for (int i = 1; i < 1001; i++)
    {
        t = sd(i);
        if (t <= 1000)
        {
            ans[t] = i;
        }
    }
    cin >> n;
    while (n != 0)
    {
        if (ans[n] == 0)
        {
            cout << "Case " << cs << ": " << -1 << endl;
        }
        else
        {
            cout << "Case " << cs << ": " << ans[n] << endl;
        }
        cs++;
        cin >> n;
    }
    return 0;
}