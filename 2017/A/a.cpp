#include <iostream>

using namespace std;

int main(void)
{
  while (true) {
    
    int n, m;
    cin >> n >> m;
    if (n == 0 && m == 0) break;

    int a[n];
    for (int i = 0; i < n; i++)
      cin >> a[i];

    int max = -1;
    for (int i = 0; i < n; i++) {
      for (int j = i+1; j < n; j++) {
	int tmp = a[i] + a[j];
	if (max < tmp && tmp <= m)
	  max = tmp;
      }
    }

    if (max == -1)
      cout << "NONE" << endl;
    else 
      cout << max << endl;
    
  }
  return 0;
}
