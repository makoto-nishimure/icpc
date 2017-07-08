#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

int main(void)
{
  int tannka[5] = {5, 7, 5, 7, 7};
  
  while (true) {
    int n;
    cin >> n;
    if (n == 0) break;
    int w;
    vector<string> v;
    v.resize(n);
    
    for (int i = 0; i < n; i++) {
      cin >> v[i];
    }
    
    //短歌の1~5番目  //入力文字数
    pair<int,int> count = make_pair(0,0);
    for (int i = 0; i < n; i++) {
      string str = v[i];	
      if (tannka[count.first] - count.second > str.size()) {
	if (count.first == 0 && count.second == 0) w = i;
	count.second += str.size();
      } else if (tannka[count.first] - count.second == str.size()) {
	if (count.first == 0 && count.second == 0) w = i;
	count.first++;
	  count.second = 0;
      } else {
	count = make_pair(0,0);
	i = w;
      }
      if (count.first == 5) {
	cout << w+1 << endl;
	break;
      }
    }
    
  }
  return 0;
}
