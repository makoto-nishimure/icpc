#include <iostream>
#include <vector>
#include <utility>
#include <tuple>
#include <random>
using namespace std;

struct data_t {
	int key1;
	int key2;
	float value;
};

bool cmp(const data_t& left, const data_t& right) {
	return (left.key1 == right.key1) ? (left.key2 < right.key2) : (left.key1 < right.key1);
}

//bool cmp2(const vector<pair<int,int> > left, 
//		const vector<pair<int,int> > right)
//{
//	return (left.first == right.first) ? (left.second < right.second) : (left.first < right.first);
//}

bool cmp3(pair<int,int> &l,
		pair<int,int> &r)
{
	return tie(l.first, l.second) < tie(r.first, r.second);
}

	int
main (int argc, char **argv)
{
	random_device seed_gen;
	minstd_rand engine(seed_gen());
	vector<pair<int,int> > v;
	for (int i = 0; i < 10; i++)
	{
		int Rnum = engine()%100;
		pair<int,int> p = make_pair(Rnum, i);
		v.push_back(p);
	}
	cout << "GENERATE" << endl;
	for (auto x:v)
	{
		cout << "(" << x.first << "," << x.second << ")" << endl;
	}
	cout << "CMP" << endl;
	sort(v.begin(), v.end(), cmp3);
	for (auto x:v)
	{
		cout << "(" << x.first << "," << x.second << ")" << endl;
	}
	return 0;
}
