#include <iostream>
#include <math.h>
using namespace std;

#define MP 20000001
#define MA 100000

long p[MP] = { 0 };
long a[MA] = { 0 };

void prime()
{
	//cout << "Prime Start" << endl;
	long c;
	p[0] = 1;
	p[1] = 1;
	for (long i = 2; i < (long)sqrt(MP); i++)
	{
		//cout << i << endl;
		if (p[i] == 0)
		{
			c = 2;
			while ((c * i) < MP)
			{
				//cout << c * i << endl;
				p[c * i] = 1;
				c++;
			}
		}
		//cout << i <<" 2" << endl;
	}
	//cout << "Prime End" << endl;
}

void twin()
{
	//cout << "Twin Start" << endl;
	long c = 1;
	for (long i = 3; i < MP - 2; i++)
	{
		if ((p[i] == 0) && (p[i + 2] == 0) && (c <= 100000))
		{
			//cout << i << endl;
			a[c] = i;
			c++;
		}
	}
	//cout << "Twin End" << endl;
}

int main()
{
	prime();
	twin();
	long n;
	while (cin >> n)
	{
		cout << "(" << a[n] << ", " << a[n] + 2 << ")" << endl;
	}
	return 0;
}