#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

int
main (void)
{
	int n;
	cin >> n;
	vector<tuple<int, int, int, int, int> > q;
	for (int i = 0; i < n; i++)
	{
		int l, t, r, b;
		cin >> l >> t >> r >> b;
		q.push_back(make_tuple(i, l, r, b, t));
	}

}
