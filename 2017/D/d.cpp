#include <iostream>
#include <string.h>

using namespace std;

int main(void)
{
  while (true) {
    int n, m;
    cin >> n >> m;
    if (n == 0 && m == 0) break;
    int array[n][m];
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
	cin >> array[i][j];
    
    int goo[m][n];
    setmem(goo, 0, sizeof(goo));
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
	goo[j][i] = array[i][j];

    

    
  }
  return 0;
}
  
