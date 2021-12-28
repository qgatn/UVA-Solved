#include <iostream>
#include <string>
#include <algorithm>
#include<cmath>
using namespace std;

#define ll long long

int main()
{
	int t, x, k, a, b, i, j, temp;
	bool flag = true;
	cin >> t;
	while (t--)
	{
		flag = true;
		cin >> x >> k;
		for (i = 0; flag && i <= k; i++)
		{
			for (j = 0; flag && j <= k; j++)
			{
				temp = (i * floor((double)x / (double)k)) + (j * ceil((double)x / (double)k));
				if (temp == x)
				{
					flag = false;
					break;
				}
			}
			if (flag == false)
			{
				break;
			}
		}
		cout << i << " " << j << endl;
	}
}