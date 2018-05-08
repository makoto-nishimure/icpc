#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K, S;
int COUNT;

// vector が同じ要素か判定
// 同じ要素なら true
// 異なるなら false
bool
judge (vector<int> &a, vector<int> &b)
{
	for (int i = 0; i < a.size(); i++)
		if (a[i] != b[i])
			return false;
	return true;
}

// vector b は探索済か
// 探索済ならば true
// 未探索ならば false
// vector<int> b はソートしておく．
bool
correct (vector<vector<int> > &a, vector<int> &b)
{
	bool flag = false;
	for (int j = 0; j < a.size(); j++)
	{
		// 第一要素が等しいなら
		if (a[j][0] == b[0])
		{
			flag = judge(a[j], b);
			if (flag)
				break;
		}
		// 探索する必要がない時
		else if (b[0] < a[j][0]) 
		{
			break;
		}
	}
	return flag;
}

void
rec (vector<vector<int> > &a, vector<int> &b, int now, int sum)
{
	// 全ての要素が決まったなら
	if (now == K)
	{
		vector<int> cp;
		cp = b;
		sort(cp.begin(), cp.end());
#ifdef D
		cout << "cp::"; 
		for (int x:cp)
		{
			cout << x << " ";
		}
		cout << endl;
#endif
		// 未探索であるなら
		bool flag = correct(a, cp);
#ifdef D
		cout << "flag " << flag << endl;
#endif
		if (!flag)
		{
			a.push_back(cp);
#ifdef D
			cout << "a" << endl;
			for (vector<int> x:a)
			{
				for (int y:x)
					cout << y << " ";
				cout << endl;
			}
			cout << endl;
#endif
		}
		// 探索済なら
		else {}
	}
	// K の中の now 番目の要素を探索
	else 
	{
		// 最後を探索する時
		if (now + 1 == K)
		{
			int diff = S - sum;
			// S-sum が1<=diff<=N の時
			if (1 <= diff && diff <= N)
			{
				b.push_back(diff);
				rec (a, b, now+1, S);
				b.pop_back();
			}
			// それ以外の時は適切でない
			else {}
		}
		// 最後以外を探索する時
		else 
		{
			// now 番目に適する数を探索
			for (int i = 1; i <= N; i++)
			{
				// sum+i がSより小さい時
				if (sum + i < S)
				{
					b.push_back(i);
					rec (a, b, now+1, sum+i);
					b.pop_back();
				}
				// それ以外は適切でない
				else {}
			}	
		}
	}
}

	int
main (void)
{
	while (1)
	{
		COUNT = 0;
		cin >> N >> K >> S;
		if (N == 0)
			break;
		vector<vector<int> > a;
		vector<int> b;
		rec (a, b, 0, 0);
		cout << a.size() << endl;
	}
	return 0;
}
