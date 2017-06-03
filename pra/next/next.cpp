#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char *argv[]) {

  int n, p;
  int count;
  int c;
  vector<int> num;
  int i;
  bool flag, f;

  while(true) {
    cin >> n >> p;
    if(n == 0) break;
  count = p;
  num.resize(n);
  for(int j = 0; j < n; j++)
    num[j] = 0;
 
  i = 0;
  while(true){
    if(i >= n)
      i = 0;
    if(count > 0) {
      num[i]++;
      count--;
    }
    else if(count == 0){
      count = num[i];
      num[i] = 0;
    }
    if((count == 0) && (p == num[i]))
      break;
    i++;
  }
  
  cout << i << endl;
  }
  return 0;
}
