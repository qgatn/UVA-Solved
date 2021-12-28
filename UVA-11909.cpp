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
	d l, w, h, rad, ti, vol;
	d pi = 2 * acos(0.0);
	std::cout << std::setprecision(3) << std::fixed;
	while (cin >> l >> w >> h >> ti)
	{
		rad = ti * pi / 180;
		if (l * tan(rad) <= h)
		{
			vol = (l * w * h) - (w * (0.5) * l * l * tan(rad));
		}
		else
		{
			vol = w * (0.5) * h * h * (1 / tan(rad));
		}
		cout << vol << " mL" << endl;
	}
	return 0;
}