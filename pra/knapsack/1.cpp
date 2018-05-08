#include <iostream>
#include <algorithm>

using namespace std;

int DP[101][10001];

void
init_DP (int w)
{
	for (int i = 0; i <= w; i++)
		DP[0][i] = 0;
}

void
print (int n, int w)
{
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= w; j++)
		{
			cout << DP[i][j] << " ";
		}
		cout << endl;
	}
}

int
main (int argc, char **argv)
{
	int n, w;
	cin >> n >> w;
	int value[n], weight[n];
	for (int i = 0; i < n; i++)
		cin >> value[i] >> weight[i];

	init_DP(w);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= w; j++)
		{
			if (0 <= j - weight[i])
			{
				DP[i+1][j] = max(DP[i][j-weight[i]] + value[i], DP[i][j]);
			}
			else
			{
				DP[i+1][j] = DP[i][j];
			}
		}
	}
	cout << DP[n][w] << endl;
	return 0;
}
