#include <iostream>
#include <stack> 
#include <math.h>
#include <cstdlib> 
#include <algorithm>  
#include <vector>
using namespace std;
#define MAXINT 1000000

vector<int> primes(MAXINT);
int pos = 0;


bool isprime(int n)
{
    for (int i = 2; i <= (int)sqrt(n); i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

void start(int a, int b)
{
    for (int i = a; i <= b; i++)
    {
        if (i % 2 != 0 || i == 2)
        {
            if (isprime(i))
            {
                primes[pos++] = i;
            }
        }
    }
}

int main()
{
    int u, l, min, max, a, b;
    while (cin >> u >> l)
    {
        pos = 0;
        start(u, l);
        min = 1000001;
        max = 0;
        for (int i = 0; i < pos - 1; i++)
        {
            if (primes[i + 1] - primes[i] > max)
            {
                max = primes[i + 1] - primes[i];
                a = i;
            }
            if (primes[i + 1] - primes[i] < min)
            {
                min = primes[i + 1] - primes[i];
                b = i;
            }
        }
        if ((max == 0) || (min == 1000001))
        {
            cout << "There are no adjacent primes." << endl;
        }
        else
        {
            cout << primes[b] << ", " << primes[b + 1] << " are closest, " << primes[a] << ", " << primes[a + 1] << " are most distant." << endl;
        }
    }
    return 0;
}