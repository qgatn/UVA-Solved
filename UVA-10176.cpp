#include <stdio.h>
#include <iostream>
using namespace std;

int main() {
    char s;
    long long n = 0;
    while (s = getchar()) {
        if (s == -1)
            break;
        if (s == '1' || s == '0')
        {
            n = (n << 1) + s - '0';
            if (n >= 131071)
            {
                n %= 131071;
            }
        }
        else if (s == '#')
        {
            cout << ((n) ? "NO" : "YES") << endl;
            n = 0;
        }
    }
    return 0;
}