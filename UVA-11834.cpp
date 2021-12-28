#include <iostream>
using namespace std;

bool solve(int l, int w, int r1, int r2)
{
    int s = (l < w) ? l : w;

    if (r1 * 2 > s || r2 * 2 > s)
    {
        return false;
    }
    else
    {
        int x = l - r1 - r2, y = w - r1 - r2, r = r1 + r2;

        if (x * x + y * y >= r * r)
        {
            return true;
        }

        return false;
    }
}

int main()
{
    int l, w, r1, r2;
    while (cin >> l >> w >> r1 >> r2 && l)
    {
        if (solve(l, w, r1, r2))
        {
            cout << "S" << endl;
        }
        else
        {
            cout << "N" << endl;
        }
    }
}