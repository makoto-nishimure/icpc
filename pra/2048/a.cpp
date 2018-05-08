#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

/* 引数の整数x以下の全ての素数を返す関数 */
/* 返り値は素数の個数，引数の配列には，素数を格納する. */
int era (int x, int *array)
{
	int search[x];
	int len = 0;
	search[0] = search[1] = 0;
	for (int i = 2; i < x; i++)
		search[i] = 1;
	double root_x = sqrt(x);
	for (int i = 0; ; i++) {
		int num = search[i];
		if (num == 1) {
			if (root_x <= i)
				break;
			else {
				array[len++] = i;
				for (int j = i; j < x; j+=i)
					search[j] = 0;
			}
		}
	}
	for (int i = 0; i < x; i++) {
		if (search[i] == 1) {
			array[len++] = i;
			search[i] = 0;
		}
	}
	return len;
}

/* 引数の素因数を求める関数  */
int p_list(int a, int *list, int *primes, int len)
{
	int a_len = 0;
	int i = 0;
	while (primes[i] <= a) 
	{
		if (a % primes[i] == 0)
			list[a_len++] = primes[i];
		i++;
		if (len <= i)
			break;
	}
	return a_len++;
}

int key(int *list, int len)
{
	int sum = 0;
	if (len == 1)
		return list[0];
	for (int i = 0; i < len - 1; i++) 
		sum += list[i];
	return list[len-1] - sum;


}

int main (void)
{
	int *primes;
	int len;
	primes = (int *)malloc(sizeof(int) * 1000000);
	len = era(1000000, primes);	
	while (1) {
		int a, b;
		cin >> a >> b;
		if (a == 0 && b == 0)
			break;
		int a_pri[a/2], b_pri[b/2];
		int a_len, b_len;
		a_len = p_list(a, a_pri, primes, len);
		b_len = p_list(b, b_pri, primes, len);
#ifdef DEBUG
		cout << a_len << " " << b_len << endl;
		for (int i = 0; i < a_len; i++)
			cout << a_pri[i] << endl;
		for (int i = 0; i < b_len; i++)
			cout << b_pri[i] << endl;
#endif
		int a_key, b_key;
		a_key = key(a_pri, a_len);
		b_key = key(b_pri, b_len);
#ifdef DEBUG
		cout << "a " << a_key << endl;
		cout << "b " << b_key << endl;
#endif
		if (a_key > b_key)
			cout << "a" << endl;
		else
			cout << "b" << endl;
	}
	free(primes);
	return 0;
}

