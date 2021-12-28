#include <iostream>
using namespace std;

long int catalan(int n)
{

    if (n <= 1)
        return 1;

    unsigned long int res = 0;
    for (int i = 0; i < n; i++)
        res += catalan(i) * catalan(n - i - 1);

    return res;
}

int main()
{
    int n;
    int f = 1;
    while (cin >> n)
    {
        if (f != 1)
        {
            cout << endl;
        }
        cout << catalan(n) << endl;
        f = 0;
    }
    return 0;
}