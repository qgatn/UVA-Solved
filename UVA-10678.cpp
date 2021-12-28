#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <stack>
#include <iomanip>
using namespace std;

#define d double

int main()
{
	int t;
	d a, l, c;
	d pi = 2 * acos(0.0);
	cin >> t;
	std::cout << std::setprecision(3) << std::fixed;
	while (t--)
	{
		cin >> a >> l;
		a /= 2; l /= 2;
		c = (d)sqrt(l * l - a * a);
		cout << (d)(pi * l * c) << endl;
	}
	return 0;
}