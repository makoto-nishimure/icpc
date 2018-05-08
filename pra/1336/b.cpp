#include <iostream>

using namespace std;

typedef struct
{
	// direction
	// if 0 then go left
	// el 1 then go right
	int d;
	// position
	double p;
	// in
	// hool
	// if h is true then ant in hool
	// el h is false then ant go out
	bool h;
} ant;

	int
main (void)
{
	while (1)
	{
		int n, l;
		cin >> n >> l;
		if (n == 0)
			break;
		ant a[n];
		for (int i = 0; i < n; i++)
		{
			char d;
			cin >> d >> a[i].p;
			if (d == 'L')
				a[i].d = 0;
			else
				a[i].d = 1;
			a[i].h = true;
		}

		int ants = n;
		bool flag = false;

		for (int t = 1; ; t++)
		{
			// ありの動きを更新
			for (int i = 0; i < n; i++)
			{
				// left
				if (!a[i].d)
					a[i].p -= 1;
				// right
				else
					a[i].p += 1;
			}
			// 出て行ったやつの更新
			for (int i = 0; i < n; i++)
			{
				if (a[i].h)
				{
					// 左から
					if (a[i].p < 0)
					{
						a[i].h = false;
						ants--;
					}
					// 右から
					else if (l < a[i].p) 
					{
						a[i].h = false;
						ants--;
					}
				}
			}

			// ぶつかった時
			for (int i = 0; i < n; i++)
			{
				for (int j = i+1; j < n; j++)
				{
					if (a[i].p == a[j].p)
					{
						if (a[i].d)
						{
							a[i].d = 0;
							a[j].d = 1;
						}
						else
						{
							a[i].d = 1;
							a[j].d = 0;
						}
					}
				}
			}
			// DEBUG
			{
#ifdef D
				cout << "time:" << t << endl;
				cout << "ants:" << ants << endl;
				for (int i = 0; i < n; i++)
				{
					cout << i << endl;
					cout << " " << "d:" << a[i].d << endl;
					cout << " " << "p:" << a[i].p << endl;
					cout << " " << "h:" << a[i].h << endl;
				}
				cout << endl;
				cout << "------------------"<< endl;
#endif
			}
			if (ants == 2)
			{
				int start, end;
				start = end = -1;
				for (int i = 0; i < n; i++)
				{
					if (a[i].h)
					{
						if (a[i].p == 0)
						{
							start = i;
						}
						if (a[i].p == l)
						{
							end = i;
						}
					}
				}
				if (-1 < start && -1 < end)
				{
					cout << t << " " << start + 1 << endl;
					flag = true;
				}
				/*
				else if (end)
				{
					cout << t << " " << end + 1 << endl;
					flag = true;
				}
				*/

			}
			else if (ants == 1)
			{
				for (int i = 0; i < n; i++)
					if (a[i].h)
					{
						if (a[i].p == 0 || a[i].p == l)
						{
							cout << t << " " << i + 1 << endl;
							flag = true;
						}
					}
			}
			if (flag)
				break;
		}
	}
	return 0;
}
