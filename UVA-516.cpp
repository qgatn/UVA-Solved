#include <math.h>
#include <vector>
#include <queue>
#include <string>
#include <iostream>
using namespace std;

#define ll unsigned long long
#define pb push_back

vector<int> primes;
vector<bool> isPrime(1000000, true);
int pos = 1;

void start()
{
    primes.push_back(2);
    for (long long i = 3; i < 1000000; i += 2)
    {
        if (isPrime[i])
        {
            for (long long j = i * i; j < 1000000; j += i)
            {
                isPrime[j] = false;
            }

            primes.push_back(i);
            pos++;
        }
    }
}

void solve(int n) {
    vector<int> num, t;
    int p = 0, np = primes.size();
    while (p < np && n>1)
    {
        if (n % primes[p] == 0)
        {
            int Count = 0;
            while (n > 1 && n % primes[p] == 0)
            {
                n /= primes[p];
                Count++;
            }
            num.pb(primes[p]);
            t.pb(Count);
        }
        p++;
    }
    n = num.size();
    if (n)
        cout << num[n - 1] << " " << t[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        cout << " " << num[i] << " " << t[i];
    }
    cout << endl;
}

int main()
{
    string s;
    start();
    ll n, tot, po;
    getline(cin, s);
    bool flag = true;
    if (!s.compare("0"))
    {
        flag = false;
    }
    while (flag)
    {
        tot = 1;
        for (int i = 0; i < s.length(); i++)
        {
            po = 0;
            n = (ll)s[i++] - '0';
            while (s[i] != ' ' && i < s.length())
            {
                n = (n * 10) + ((ll)s[i] - '0');
                i++;
            }
            i++;
            po = s[i++] - '0';
            if (i < s.length())
            {
                while (s[i] != ' ' && i < s.length())
                {
                    po = (po * 10) + ((ll)s[i] - '0');
                    i++;
                }
            }
            tot *= (ll)pow(n, po);
        }
        tot--;
        solve(tot);

        getline(cin, s);
        if (!s.compare("0"))
        {
            flag = false;
        }
    }
    return 0;
}