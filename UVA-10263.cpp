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
	double x, y;
};

bool comp(pos& a, pos& b)
{
	return b.x < a.x;
}

int main()
{
	d xm, ym, n, m, b, a, ct, tx, ty, temp, nx, ny, k, s1, s2, dx, dy;
	bool flagy, flagx;
	// xm, ym is station
	// m is min distance
	// ct is c from ax + by + c = 0
	// a, b is from ax + by
	// nx, ny is new calculated x and y
	// k is the temporary distance from station to new line
	std::cout << std::setprecision(4) << std::fixed;
	while (cin >> xm >> ym >> n)
	{
		n++;
		vector<pos> cor;
		for (int i = 0; i < n; i++)
		{
			pos newt;
			cin >> newt.x >> newt.y;
			cor.push_back(newt);
		}
		//sort(cor.begin(), cor.end(), comp);
		m = ((xm - cor[0].x) * (xm - cor[0].x) + (ym - cor[0].y) * (ym - cor[0].y));
		//cout << "Starting at : " <<m << endl;
		tx = cor[0].x, ty = cor[0].y;
		for (int i = 0; i < n - 1; i++)
		{
			//cout << endl;
			//cout << "Points " << endl << cor[i].x << " " << cor[i].y << endl << cor[i + 1].x << " " << cor[i + 1].y << endl;
			dx = cor[i].x - cor[i + 1].x;
			dy = cor[i].y - cor[i + 1].y;
			ct = cor[i].y - ((dy / dx) * cor[i].x);
			a = dx;
			b = -1 * dy;
			ct = -1 * (dx * ct);
			//cout << "Equ. a: " << a << " b: " << b << " c: " << ct << endl;
			k = (d)abs(a * ym + b * xm + ct) / sqrt(a * a + b * b);
			//cout << "Min Dist: " << k << endl;
			nx = (a * (a * xm - b * ym) - b * ct) / (a * a + b * b);
			ny = (b * (b * ym - a * xm) - a * ct) / (a * a + b * b);
			//cout << "New Points: " << nx << " " << ny << endl;

			flagy = false;
			if ((ny <= cor[i].y && (ny >= cor[i + 1].y)) || (ny >= cor[i].y && (ny <= cor[i + 1].y)))
			{
				flagy = true;
			}
			flagx = false;
			if ((nx <= cor[i].x && (nx >= cor[i + 1].x)) || (nx >= cor[i].x && (nx <= cor[i + 1].x)))
			{
				flagx = true;
			}
			//cout << "Flag " << flagx << " " << flagy << endl;
			if (k < m)
			{
				//cout << "K smaller" << endl;
				if (flagx && (flagy))
				{
					m = k;
					tx = nx;
					ty = ny;
					//cout << "Changed" << endl;
				}
			}
			k = ((xm - cor[i + 1].x) * (xm - cor[i + 1].x) + (ym - cor[i + 1].y) * (ym - cor[i + 1].y));
			if (k < m)
			{
				m = k;
				tx = cor[i + 1].x;
				ty = cor[i + 1].y;
			}
		}
		//cout << endl;
		//cout << "FINAL: " << endl;
		cout << tx << endl;
		cout << ty << endl;
	}
	return 0;
}

/*
6
-3
3
0
1
5
5
9
-5
15
3

*/