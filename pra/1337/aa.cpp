#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int
CountRangeSearch (int start, int end, set<int> &s)
{
	auto it = s.lower_bound(start);
	auto last = s.upper_bound(end);
	int count = 0;

	cout << "start::" << start << " ,end::" << end << endl;
	while (it != last)
	{
		cout << *it << " ";
		it++;
		count++;
	}
	cout << endl;
	return count;
}

int
main (int argc, char **argv)
{
	int n;
	cin >> n;
	vector<int> v;
	set<int> s;
	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	for (auto x:v)
		s.insert(x);

	int start, end;
	cin >> start >> end;
	int count = CountRangeSearch (start, end, s);
	cout << "count::" << count << endl;
	return 0;
}
