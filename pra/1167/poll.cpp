#include <iostream>
#include <vector>

using namespace std;

#define MAX 1000000

int main(void)
{
  vector<int> three, four;
  three.push_back(1); four.push_back(1);
  
  for (int i = 1; ; i++) {
    three.push_back(three[i-1]+i+1);
    four.push_back(four[i-1]+three[i]);
    if (four[i] > MAX) break;
  }

  while (true) {

    int n;
    cin >> n;
    if (n == 0) break;

    int array[n][four.size()][n];

    int suffix;
    for (int i = 0; ; i++) {
      array[0][i][0] = 0;
      if (four[i] > n) {
	suffix = i
	break;
      }
    }

    for (int i = 1; i < n; i++) {
      
      for (int j = 0; j < suffix; j++) {

	
      
      }
    }
  }
  
  return 0;

}
