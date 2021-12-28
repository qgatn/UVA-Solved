#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <stack>
#include <iomanip>
using namespace std;

#define d double

struct pos
{
	d x, y;
};

d dis(pos& a, pos& b)
{
	return sqrt(((a.x - b.x) * (a.x - b.x)) + ((a.y - b.y) * (a.y - b.y)));
}

bool in(pos& c, d a)
{
	pos d1{ 0,0 };
	pos d2{ a,0 };
	pos d3{ 0,a };
	pos d4{ a,a };
	bool flag = true;
	if (dis(c, d1) > a)
	{
		flag = false;
	}
	else if (dis(c, d2) > a)
	{
		flag = false;
	}
	else if (dis(c, d3) > a)
	{
		flag = false;
	}
	else if (dis(c, d4) > a)
	{
		flag = false;
	}
	return flag;
}

int main()
{
	d n, a, m;
	std::cout << std::setprecision(5) << std::fixed;
	while (cin >> n >> a && n)
	{
		m = 0;
		for (int i = 0; i < n; i++)
		{
			pos t;
			cin >> t.x >> t.y;
			if (in(t, a))
			{
				m++;
			}
		}
		cout << (m * a * a) / n << endl;
	}
	return 0;
}