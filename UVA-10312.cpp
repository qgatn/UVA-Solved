#include <iostream>
#include <cstdlib>

using namespace std;

long long cat[27] = { 0 };
long long sup[27] = { 0 };

void super()
{
	sup[0] = 1; sup[1] = 1; sup[2] = 1;
	for (int i = 3; i < 27; ++i)
		sup[i] = (3 * (2 * i - 3) * sup[i - 1] - (i - 3) * sup[i - 2]) / i;
}

void catalan()
{

	cat[0] = 1;  cat[1] = 1;
	for (int i = 2; i < 27; ++i)
		for (int j = 0; j < i; ++j)
			cat[i] += cat[j] * cat[i - j - 1];
}


int main()
{
	int n;
	super();
	catalan();
	while (cin >> n)
	{
		if (n < 3)
		{
			cout << 0 << endl;
		}
		else
		{
			cout << sup[n] - cat[n - 1] << endl;
		}
	}
	return 0;
}