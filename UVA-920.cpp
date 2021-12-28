#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <stack>
#include <iomanip>
using namespace std;

#define d double
#define pb push_back
struct pos
{
	double x, y;
};


d dis(pos& a, pos& b)
{
	return sqrt(((a.x - b.x) * (a.x - b.x)) + ((a.y - b.y) * (a.y - b.y)));
}

bool comp(pos& a, pos& b)
{
	return b.x < a.x;
}


int main()
{
	int t, c, count, top;
	d ans, ht;
	cin >> t;
	std::cout << std::setprecision(2) << std::fixed;
	while (t--)
	{
		vector<pos> s;
		ht = 0.0;
		count = 0;
		top = 0;
		cin >> c;
		while (c--)
		{
			pos temp;
			cin >> temp.x >> temp.y;
			s.pb(temp);
			count++;
		}

		sort(s.begin(), s.end(), comp);

		for (int i = 1; i < s.size(); i++)
		{
			if (s[i].y > top)
			{
				ht += dis(s[i], s[i - 1]) * ((s[i].y - top) / (s[i].y - s[i - 1].y));
				top = s[i].y;
			}
		}
		cout << ht << endl;

	}
}