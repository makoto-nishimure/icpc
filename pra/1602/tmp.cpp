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


//+, *を読み込んだ時，再帰を回す
//cur::suf //ope::+ or * //com::number of comma //v::array
int rec(int cur, int ope, int com, vector<pair<char,int> > &v)
{//ex //cur::1  //ope::+ //com::0

  vector<int> nums;
  
  for (int i = cur+1; i < v.size(); i++) {
    pair<char,int> p = v[i];
    //opeに関連する数またはope
    if (p.second == com+1) {
      //num
      if (p.first > 47) {
	int tmp = p.first - 48;
	nums.push_back(tmp);
      }
      //ope
      else if (p.first == 42 || p.first == 43) {
	int tmp = rec(i,p.first,p.second,v);
	nums.push_back(tmp);
      }
    }
    else if (p.second <= com)
      break;
  }

  //+
  if (ope == 43) {
    int sum = 0;
    for (int i = 0; i < nums.size(); i++) {
      sum += nums[i];
    }
    return sum;
  }
  //*
  else if (ope == 42) {
    int sum = nums[0];
    for (int i = 1; i < nums.size(); i++) {
      sum *= nums[i];
    }
    return sum;
  }
  else {
    pair<char,int>p = v[cur];
    return p.first-48;
  }
}


int main(void)
{
  while (true) {

    //+ 43  //* 42
    //. 46  //0 48 

    int n;
    cin >> n;

    if (n == 0) break;
    
    vector<pair<char,int> > v;
    for (int i = 0; i < n;i++) {
      string str;
      cin >> str;
      int com = 0;
      for (int j = 0; j < str.size(); j++) {
	int c = str[j];
	if (c == 46)
	  com++;
	else {
	  pair<char,int> p = make_pair(c,com);
	  v.push_back(p);
	}
      }
    }
    pair<char, int> p = v[0];

    cout << rec(0,p.first,p.second,v) << endl;
    
  }
  return 0;	
}

