#include <iostream>
using namespace std;

int
main (void)
{
	while (1)
	{
		int max = 150 * 150;
		int h, w;
		cin >> h >> w;
		if (h == 0 && w == 0)
			break;
		int hh = h * h;
		int ww = w * w;
		int rec = hh + ww;

		//cout << "rec " << rec << endl;
		int ah, aw;
		ah = 150;

		bool flag = true;
		// 幅
		for (int i = 1; i < 150; i++)
		{
			if (!flag)
				break;
			// 高さ
			for (int j = 1; j < 150; j++)
			{
				if (j < i)
				{
					int nh = i * i;
					int nw = j * j;
					int nrec = nh + nw;
					if (rec == nrec)
					{
						if (h < j)
						{
							ah = j;
							aw = i;
							flag = false;
							break;
						}
					}
					else if (rec < nrec && nrec < max)
					{
						max = nrec;
						ah = j;
						aw = i;
					}
				}
			}
		}
		cout << ah << " " << aw << endl;
	}
	return 0;
}

