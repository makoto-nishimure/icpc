#include <iostream>

using namespace std;

	int 
main (int argc, char **argv)
{
	int max = 150 * 150;
	while (1)
	{
		int h, w;
		cin >> h >> w;
		if (h == 0 && w == 0)
			break;
		int hh = h * h;
		int ww = w * w;
		int rec = hh + ww;

		int ans_h, ans_w;

		// 幅
		for (int j = 1; j < 150; j++)
		{
			// 高さ
			for (int i = 1; i < 150; i++)
			{
				if (j > i)
				{
					int nh = i * i;
					int nw = j * j;
					int nrec = nh + nw;
					if (rec < nrec && nrec < max)
					{
						max = nrec;
						ans_h = i;
						ans_w = j;
					}
				}

			}
		}
		cout << ans_h << " " << ans_w << endl;	
	}
	return 0;
}
