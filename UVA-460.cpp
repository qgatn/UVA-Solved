#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <stack>
#include <iomanip>
#include <fstream>
using namespace std;

#define d double

struct rect
{
	d x1, y1, x2, y2;
};


int main()
{
	int tc, c;
	cin >> tc;
	rect a, b;
	while (tc--)
	{
		cin >> a.x1 >> a.y1 >> a.x2 >> a.y2;
		cin >> b.x1 >> b.y1 >> b.x2 >> b.y2;
		rect t;
		t.x1 = max(a.x1, b.x1);
		t.y1 = max(a.y1, b.y1);
		t.x2 = min(a.x2, b.x2);
		t.y2 = min(a.y2, b.y2);
		if (t.x1 < t.x2 && t.y1 < t.y2)
		{
			cout << t.x1 << " " << t.y1 << " " << t.x2 << " " << t.y2 << endl;
		}
		else
		{
			cout << "No Overlap" << endl;
		}
		if (tc)
		{
			cout << endl;
		}
	}
	return 0;
}