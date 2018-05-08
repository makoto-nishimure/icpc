#include <iostream>
#include <bitset>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char **argv)
{
	while (true)
	{
		int m, min, max;
		cin >> m; 
		if (m == 0)
			break;
		cin >> min >> max;
		vector<int> v;
		for (int y = m; y > 0; --y &= m)
			v.push_back(y);
		for (auto x:v)
			cout << bitset<>(x) << endl;
	}
	return 0;
}
