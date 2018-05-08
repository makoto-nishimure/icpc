#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

typedef struct
{
	pair<int,int> f;
	pair<int,int> s;
} Point;

void
input (int n, vector<pair<int,Point> > &xl, 
		vector<pair<int,Point> > &yl)
{
	for (int i = 0; i < n; i++)
	{
		int l, t, r, b;
		cin >> l >> t >> r >> b;
		pair<int,int> A,B;
		Point P;
		pair<int,Point> C;
		// 左の垂線
		A = make_pair(l, b);
		B = make_pair(l, t);
		P.f = A; P.s = B;
		C = make_pair(i, P);
		xl.push_back(C);
		// 下の水平線
		B = make_pair(r, b);
		P.f = A; P.s = B;
		C = make_pair(i, P);
		yl.push_back(C);
		// 右の垂線
		A = make_pair(r, b);
		B = make_pair(r, t);
		P.f = A; P.s = B;
		C = make_pair(i, P);
		xl.push_back(C);
		// 下の水平線
		A = make_pair(l, t);
		P.f = A; P.s = B;
		C = make_pair(i, P);
		yl.push_back(C);
	}
}

void
print (pair<int, Point> P)
{
	printf("id:%d, (%d,%d), (%d, %d)\n", P.first,
			P.second.f.first, P.second.f.second,
			P.second.s.first, P.second.s.second);
}

bool
cmp (pair<int,Point> &x, pair<int,Point> &y)
{
	return (x.second.f.first == y.second.f.first) ? (x.first < y.first) : (x.second.f.first < y.second.f.first);
}


int
main (int argc, char **argv)
{
	int n;
	cin >> n;

	// id, Point(x, y), Point(x, y)
	vector<pair<int,Point> > xl, yl;
	input(n, xl, yl);

#ifdef D
	{
		cout << "xl" << endl;
		for (pair<int, Point> x:xl)
			print(x);

		cout << "yl" << endl;
		for (pair<int, Point> y:yl)
			print(y);
	}
#endif
	sort(xl.begin(), xl.end(), cmp);
	sort(yl.begin(), yl.end(), cmp);
#ifdef D
	{
		cout << "CMP xl" << endl;
		for (pair<int, Point> x:xl)
			print(x);

		cout << "CMP yl" << endl;
		for (pair<int, Point> y:yl)
			print(y);
	}
#endif

	return 0;
}
