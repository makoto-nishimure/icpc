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
  
  int c[MAX];

  for (int i = 0; i < MAX; i++)
    c[i] = 0;
  
  for (int i = 0; i < N; i++) {
    for (int j = a[i]; j <= b[i]; j++)
      c[j]++;
  }
  int max = -1;
  int min = 100000;

#ifdef DEBUG  
  for (int i = 0; i < 10; i++)
    cout << c[i] << " ";

  cout << endl;
#endif
  for (int i = 0; i < MAX; i++) {
    if (max < c[i]) {
      max = c[i];
    }
  }  

  for (int i = 0; i < N; i++) {
    if (min > a[i]) {
      min = a[i];
    }
  }
  cout << max << endl;
  cout << min << endl;
  if (min > max)
    max = 0;  
  for (int i = 0; i < N; i++) {
    if (max+1 > b[i])
      max--;
  }

  cout << max << endl;
  
  return 0;

}
