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

		for (double t = 0; ; t+=0.5)
		{
			// ありの動きを更新
			for (int i = 0; i < n; i++)
			{
				// 穴の中にいるあり
				if (a[i].h)
				{
					// left
					if (!a[i].d)
						a[i].p -= t;
					// right
					else
						a[i].p += t;
				}
				// いないやつ
				else {}
			}
			// 出て行ったやつの更新
			for (int i = 0; i < n; i++)
			{
				// 左から
				if (a[i].p < 0.0)
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
			// ぶつかった時
			for (int i = 0; i < n; i++)
			{
				for (int j = i+1; j < n; j++)
				{
					if (a[i].p == a[j].p)
					{
						double tmp = t - (int)t;
						if (tmp == 0.0)
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
			}
			// 残り1匹
			if (ants == 1)
			{
				int tmp;
				// 残り1匹を見つける
				for (int i = 0; i < n; i++)
					if (a[i].h)
						tmp = i;
				if (a[tmp].p == 0.0 || a[tmp].p == l)
				{
					cout << (int)t << " " << tmp << endl;
					flag = true;
				}
			}
			else if (ants == 2)
			{
				int tmp[2];
				int c = 0;
				// 残り2匹を見つける
				for (int i = 0; i < n; i++)
					if (a[i].h)
					{
						tmp[c] = i;
						c++;
					}
				int bigger, smaller;
				bool tFlag = false;
				if (a[tmp[1]].p < a[tmp[0]].p)
				{
					bigger  = tmp[0];
					smaller = tmp[1];
					tFlag = true;
				}
				else if (a[tmp[0]].p < a[tmp[1]].p)
				{
					smaller = tmp[0];
					bigger  = tmp[1];
					tFlag = true;
				}
				if (tFlag)
				{
					if (a[smaller].p == 0.0 && a[bigger].p == l)
					{
						cout << (int)t << " " << smaller << endl;
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
