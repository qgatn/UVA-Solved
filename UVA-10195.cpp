#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <stack>
#include <iomanip>
using namespace std;

#define d double

d find(d a, d b, d c)
{
	if (a == 0 || b == 0 || c == 0)
	{
		return 0;
	}
	d s = (a + b + c) / 2;
	return ((d)sqrt(s * (s - b) * (s - a) * (s - c)) / s);
}


int main()
{
	d a, b, c;
	std::cout << std::setprecision(3) << std::fixed;
	while (cin >> a >> b >> c)
	{
		cout << "The radius of the round table is: " << find(a, b, c) << endl;
	}
}