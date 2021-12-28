#include <iostream>
using namespace std;

int main() {
	int t;
	while (cin >> t && t)
	{
		int w, h, x = 0;
		double ma = 0.0;
		for (int i = 0; i < t; ++i)
		{
			cin >> w >> h;
			double k = max(min(w, h) / 2.0, max(min<double>(w / 4.0, h), min<double>(w, h / 4.0)));
			if (k > ma)
			{
				ma = k;
				x = i;
			}
		}
		cout << x + 1 << endl;
	}
}