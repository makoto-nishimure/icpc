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

using namespace std;

bool jud(int i, int n, int atoz[])
{
  //case:: i < n/2
  if (i < n/2)
    return false;
  else {
    //1位と2位を探す
    //suf と　得票数
    pair<int,int> top, sec;
    top = sec = make_pair(0,0);

    for (int j = 0; j < 26; j++) {
      if (atoz[j] > 0 && top.second <= atoz[j]) {
	sec = make_pair(top.first,top.second);
	top = make_pair(j,atoz[j]);
      }
      else if (atoz[j] > 0 && sec.second <= atoz[j]) {
	sec  = make_pair(j,atoz[j]);
      }
    }   
    //最後まで投票した
    if (i == n-1) { 
      //1位が二人
      if (top.second == sec.second) {
	cout << "TIE" << endl;
	return true;
      }
      //1位が一人
      else {
	char c = top.first + 65;
	cout << c << " " << i+1 << endl;
	return true;
      }
    }
    //半数は投票した
    else {
      if (top.second > sec.second + n-1-i) {
	char c = top.first + 65;
	cout << c << " " << i+1 << endl;
	return true;
      }
    }
  }
  return false;
}

int main(void)
{
  int atoz[26];
 
  while (true) {
    int n;
    cin >> n;
    if (n == 0) break;
    char c[n];
    for (int i = 0; i < n; i++)
      cin >> c[i];
    memset(atoz, 0, sizeof(atoz));

    bool flag = false;
    for (int i = 0; i < n; i++) {
      atoz[c[i]-65]++;
      //true::decided
      flag = jud(i, n, atoz);
      if (flag)
	break;
    }
  }
  return 0;	
}

