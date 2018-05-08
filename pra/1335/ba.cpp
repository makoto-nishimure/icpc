#include <iostream>
#include <cstring>
using namespace std;

	int
main (void)
{
	int DP[21][156][11];
	memset(DP, 0, sizeof(DP));
	DP[0][0][0] = 1;

	for (int n = 1; n <= 20; n++)
	{
		for (int s = 0; s <= 155; s++)
		{
			for (int k = 0; k <= 10; k++)
				DP[n][s][k] = DP[n-1][s][k];
		}
		for (int s = 0; s <= 155; s++)
		{
			for (int k = 1; k <= 10; k++)
			{
				if (s+n <= 155)
					DP[n][s+n][k] += DP[n-1][s][k-1];
			}
		}
	}

	while (1)
	{
		int N, K, S;
		cin >> N >> K >> S;
		if (N == 0)
			break;
		cout << DP[N][S][K] << endl;
	}
	return 0;
}
