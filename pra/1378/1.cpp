#include <iostream>
#include <cstring>

using namespace std;

int 
main (int argc, char **argv)
{
	int l, k;
	cin >> l >> k;
	double siro[110], kuro[110];
	memset (siro, 0, sizeof(siro));
	memset (kuro, 0, sizeof(kuro));
	siro[0] = 1;
	
	for (int i = 0; i < l; i++)
	{
		siro[i+1] += kuro[i];
		kuro[i+1] += siro[i];
		kuro[i+k] += siro[i];
	}

	double sum = 0;
	for (int i = 0; i <= l; i++)
		sum += kuro[i];
	//cout << sum << endl;
	printf("%.0lf\n", sum);
	return 0;
}
