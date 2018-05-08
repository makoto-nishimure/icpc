#include <iostream>
#include <utility>
#include <vector>
#include <string.h>
#include <algorithm>

#define DEBUG

#define MAX 100000

using namespace std;


int main(void)
{
  int N;
  cin >> N;
  int a[N], b[N];
  
  //vector<piar<int, int> > v;
  for (int i = 0; i < N; i++) {
    cin >> a[i] >> b[i];
    //int a, b;
    //cin >> a >> b;
    //v.push_back(make_pair(a,b));
  }

  for (int i = N+1; i >= 2; i--) {
    int f = 0;
    for (int j = 0; j < N; j++) {
      if (a[j] <= i && i <= b[j])
	f++;
    }
    if (f >= i-1) {
      cout << i-1<< endl;
      return 0;
    }
  }
  cout << 0 << endl;
  return 0;
}
