#include <iostream>

using namespace std;

int main() {
    long long N, a, i;
    int c;
    while (cin >> N && N != 0)
    {
        if (N < 0)
        {
            N *= -1;
        }
        a = -1;
        c = 0;
        for (i = 2; i * i <= N && N != 1; i++) {
            while (N % i == 0) {
                N /= i;
                a = i;
            }
            if (a == i) {
                c++;
            }
        }
        if (N != 1 && a != -1)
            a = N;
        else if (c == 1)
            a = -1;

        cout << a << endl;
    }
    return 0;
}