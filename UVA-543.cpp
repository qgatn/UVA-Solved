#include <iostream>
#include <stack> 
#include <math.h>
#include <cstdlib> 
#include <algorithm>  
#include <vector>
using namespace std;

#define MP 100000000
#define PN 5000000

int pt = 0;
long n[PN] = { 0 };
long p[MP] = { 0 };

void prime()
{
    long c;
    p[0] = 1;
    p[1] = 1;
    for (long i = 2; i < (long)sqrt(MP); i++)
    {
        if (p[i] == 0)
        {
            n[pt++] = i;
            for (long j = i + i; j < MP; j += i)
            {
                if (p[j] == 0)
                {
                    p[j] = 1;
                }
            }
        }
    }
}


int main()
{
    prime();
    int s, c;
    while (cin >> s && s != 0)
    {
        c = 1;
        for (int i = 0; i < pt && n[i] <= s; i++)
        {
            if (p[s - n[i]] == 0)
            {
                cout << s << " = " << n[i] << " + " << s - n[i] << endl;
                c = 0;
                break;
            }
        }
        if (c == 1)
        {
            cout << "Goldbach's conjecture is wrong." << endl;
        }
    }
}