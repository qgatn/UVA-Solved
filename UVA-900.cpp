#include <iostream>
using namespace std;

unsigned long int fibonacci(int num, unsigned long int* memoize)
{
    if (memoize[num] == 0)
    {
        memoize[num] = fibonacci(num - 1, memoize) + fibonacci(num - 2, memoize);
    }
    return memoize[num];
}

int main()
{
    unsigned long int memory[51] = { 0 };
    unsigned long int answer[51] = { 0 };
    memory[0] = 1;
    memory[1] = 1;
    int n, c = 0;
    cin >> n;
    while (n != 0)
    {
        answer[c] = fibonacci(n, memory);
        cin >> n;
        c++;
    }
    for (int i = 0; i < c; i++)
    {
        cout << answer[i] << endl;
    }
    return 0;
}