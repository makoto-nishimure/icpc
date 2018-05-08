#include <iostream>
#include <stdlib.h>

#define SHIRO 0
#define USUI  1
#define ATSUI 2

using namespace std;

int l, k;
double array[200];
void print (int *pole)
{
	for (int i = 0; i < l; i++)
		printf ("%d ", pole[i]);
	printf("\n");
}

bool check (int *pole, int len)
{
	// l の長さを超えている時
	if (l < len)
		return false;
	// 下が黒以外の時
	if (pole[0] == SHIRO)
		return false;
	// 上が黒以外の時
	if (pole[len-1] == SHIRO)
		return false;
	return true;
}

/* copy array */
void copy (int *tmp, int *pole)
{
	for (int i = 0; i < l; i++)
		tmp[i] = pole[i];
}

double kuro(int *pole, int len);
// 返り値は，OKだった個数
double shiro (int *pole, int len)
{
	if (array[len] != -1){
	//	printf("%d\n", array[len]);
		return array[len];
	}
	int tmp[l]; /* pole のコピー */
	double count = 0;
	//薄い白を入れる
	//白を入れた時は，チェックはせずに良い．
	//ただ，長さだけのチェックはしてた方が良いかも．
	copy(tmp, pole);
	tmp[len] = SHIRO;
	if (len + 1 <= l) {
		count = kuro(tmp, len+1);
	}
	array[len] = count;
	return count;
}
// 返り値は，OKだった個数
double kuro (int *pole, int len)
{
	int tmp[l]; /* pole のコピー */
	double count = 0;
	//薄い黒を入れる
	copy(tmp, pole);
	tmp[len] = USUI;
	//check が真ならカウントして，再帰を回す．
	if (check(tmp, len+1)) {
		// print(tmp);
		count += 1 + shiro(tmp, len+1);
	}
	//厚い黒を入れる	
	copy(tmp, pole);
	if (len + k <= l) {
		for (int i = 0; i < k; i++)
			tmp[len + i] = ATSUI;
		if (check(tmp, len+k)) {
			// print(tmp);
			count += 1 + shiro(tmp, len+k);
		}
	}
	return count;
}


int main (void)
{
	cin >> l >> k;
	int pole[l];
	int len = 0; /* len of disks */
	for (int i = 0; i < l; i++)
	{
		pole[i] = -1;
	}
	for (int i = 0; i < 200; i++)
		array[i] = -1;
	//cout << kuro(pole, 0) << endl;
	printf("%.0lf\n", kuro(pole, 0));	

	return 0;
}
