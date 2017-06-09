#include <iostream>
#include <vector>
#include <bitset>
#include <complex>
using namespace std;
int main(int argc, char *argv[]) {
  while (true) {
  int n, n2;
  cin >> n;
  if (n == 0) break;
  n2 = n + n;
  
  bitset<246912> p;
  vector<int> vec;

    int root = sqrt(n2);
    p[0] = true;
    p[1] = true;
    p[2] = true;
    int first;
    first = 2;
    
    while (true) {
      for (size_t i = first; i <= n2; i+=first) {
	p[i] = true;
      }
      vec.push_back(first);
      size_t j = first;
      while (p[j]) {
	j++;
      }
      first = j;
      if ( root < first )
	break;
    }
    for (size_t i = first; i <= n2; i++)
      if (!p[i])
	vec.push_back(i);
    bool f,e;
    f = false;
    e = false;
    int x,y;
    for (size_t i = 0; i < vec.size(); i++) {
      // cout << vec[i] << endl;
      if (!f && vec[i] > n) {
	f = true;
	x = i;
      }
      if(vec.size()-1 == i) {
	y = i;
	break;
      }
      if (!e && vec[i] >= n2) {
	e = true;
	y = i;
	break;
      }
    }
    cout << y-x+1 << endl;
  }
			      
  return 0;
}
