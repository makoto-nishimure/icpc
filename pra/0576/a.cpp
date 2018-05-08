#include <iostream>
#include <algorithm>

using namespace std;

int rec(int n, int m) {

  if (n <= 0)
    return 0;
  else
    return 1 + rec(n-m, m);
}

int main(void) {

  int L, A, B, C, D;
  cin >> L >> A >> B >> C >> D;
  
  int s, t, u;
  s = rec(A, C);
  t = rec(B, D);
  
  u = max(s, t);
  cout << L - u << endl;
  return 0;
  
}
