#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>

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
    
  int memo[MAX+1], memo_odd[MAX+1];

  for (int i = 1; i <= MAX; i++) {
    
    for (int j = 0; j < four.size(); j++) {
      
      memo[i] = min(four[
    }
  }
  

  return 0;

}
