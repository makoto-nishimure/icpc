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
      //短歌の1番目が5文字以下なら
      if (tannka[count.first] >= str.size()) {
	w = i;
	//5文字なら
	if (tannka[count.first] == str.size()) {
	  count.first++;
	  count.second = 0;
	}
	//5文字未満なら
	else {
	  count.second += str.size();
	}
	
	//短歌の1または2番目〜5番目
	for (int j = i+1; j < n; j++) {
	  str = v[j];
	  if (tannka[count.first] - count.second > str.size()) {
	    count.second += str.size();
	  } else if (tannka[count.first] - count.second == str.size()) {
	    count.first++;
	    count.second = 0;
	  } else {
	    count = make_pair(0,0);
	    break;
	  }
	  //短歌が整った
	  if (count.first == 5) {
	    cout << w+1 << endl;
	    break;
	  }
	}

	if (count.first == 5)
	  break;
	
      }
      //短歌の1番目が5より大きい
      else { }
    }
  }
  return 0;
}
