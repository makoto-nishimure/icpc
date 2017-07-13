#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <stack>
#include <queue>
#include <utility>
#include <algorithm>
#include <string>
#include <bitset>
#include <tuple>

using namespace std;

bool cond(int n, int i, vector<pair<char,int> > &v)
{
  if ((n >> 2) > i+1)
    return false;
  //value, 添字
  pair<int, int> top, sec;
  top = sec = make_pair(0,0);
  for (int j = 0; j < v.size(); j++) {
    pair<char, int> p = v[j];
    if (top.first < p.second) {
      sec = top;
      top.first = p.second; top.second = j;
    }
  }
  
  if (top.first > sec.first+n-i-1) {
    pair<char,int> p = v[top.second];
    cout << p.first << " " << i+1 << endl;
    return true;
  } else if (n == i+1) {
    if (top.first == sec.first) {
      cout << "TIE" << endl;
      return true;
    }
  }
  

  return false;
}

int main(void)
{
  while (true) {

    int n;
    cin >> n;
    if (n == 0) break;
    
    vector<pair<char,int> > v;
    for (int i = 0; i < n; i++) {
      char c;
      cin >> c;
      
      bool flag = false;
      for (int j = 0; j < v.size(); j++) {
	pair<char,int> p = v[j];
	if ((int)c == (int)p.first) {
	  p.second++;
	  v[j] = p;
	  flag = true;
	  break;
	}
      }

      if (!flag) {
	pair<char,int> p = make_pair(c,1);
	v.push_back(p);
      }

      if (cond(n, i, v))
	break;
    }

    
    /*
    for (int i = 0; i < v.size(); i++) {
      pair<char,int> p = v[i];
      cout << p.first << " " << p.second << endl;
    }
    */
  }
  return 0;	
}

