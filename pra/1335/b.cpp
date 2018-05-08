#include <iostream>
#include <cstring>
using namespace std;

int
main (void)
{
	while (1)
	{
		int N, K, S;
		cin >> N >> K >> S;
		if (N == 0)
			break;
		int DP[N+1][156][K+1];
		memset(DP, 0, sizeof(DP));
		DP[0][0][0] = 1;

		for (int n = 1; n <= N; n++)
		{
			for (int s = 0; s <= S; s++)
			{
				for (int k = 0; k <= K; k++)
					DP[n][s][k] = DP[n-1][s][k];
			}
			for (int s = 0; s <= S; s++)
			{
				for (int k = 1; k <= K; k++)
				{
#ifdef D
					printf("DP[%d][%d][%d] += DP[%d][%d][%d]\n",
							n, s+n, k, n-1, s, k-1);
					printf("DP[%d][%d][%d] += %d\n",
							n, s+n, k, DP[n-1][s][k-1]);
					if (n == 2 && s+n == 2 && k == 1)
					{
						cout << "AAA" << endl;
						cout << DP[n-1][s][k-1] << endl;
						cout << endl;
					}
#endif

					if (s+n <= 155)
						DP[n][s+n][k] += DP[n-1][s][k-1];
				}
			}
		}
		int sum = 0;
		for (int n = 1; n <= N; n++)
		{
			sum += DP[n][S][K];
		}
		cout << sum << endl;
	}
	return 0;
}
