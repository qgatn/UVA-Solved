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
	d a, b, c;
	std::cout << std::setprecision(4) << std::fixed;
	d pi = 2 * acos(0.0);
	d y, z, s, t;
	while (cin >> a >> b >> c)
	{
		if (a == 0 || b == 0 || c == 0)
		{
			cout << 0.0000 << " " << 0.0000 << " " << 0.0000 << endl;
		}
		else
		{
			s = (a + b + c) / 2;
			t = (d)sqrt(s * (s - b) * (s - a) * (s - c));
			z = pi * (t * t) / (s * s);
			y = (a * b * c) / (4 * t);
			y = y * y * pi;
			cout << y - (t) << " " << t - z << " " << z << endl;
		}
	}
	return 0;
}