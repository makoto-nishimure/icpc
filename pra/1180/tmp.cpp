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

int main(void)
{
  int zton[10];
  
  while (true) {
    
    string num;
    int l;
    cin >> num >> l;

    
    int a = stoi(num);
    if (a == 0 && l == 0) break;
    

    
    vector<string> s;
    s.push_back(num);

    for (int i = 0; i < 20 ; i++) {
      memset(zton, 0, sizeof(zton));
      string str = s[i];

      if (str.size() != l) {
	string tmp = str;
	str.resize(l);
	for (int j = 0; j < l ; j++)
	  str[j] = '0';
	for (int j = l - tmp.size(); j < l; j++)
	  str[j] = tmp[j-l+tmp.size()];
      }
      
      cout << "str::" << str << endl;
      //数の出現頻度
      for (int j = 0; j < l; j++) {
	char c = str[j];
	zton[c-48]++;
      }
      
      //init max and min
      string max, min;
      max.resize(l); min.resize(l);
      for (int j = 0; j < l; j++) {
	max[i] = '0';
	min[i] = '0';
      }
      //create min
      int suf = l-1;
      for (int j = 9; j >= 0; j--) {
	for (int k = zton[j]; k > 0; k--) {
	  char c = j + 48;
	  min[suf] = c;
	  suf--;
	}
      }
      if (suf >= 0) {
	min[suf] = '0';
	suf--;
      }      
      //create max
      suf = 0;
      for (int j = 9; j >= 0; j--) {
	for (int k = zton[j]; k > 0; k--) {
	  char c = j + 48;
	  max[suf] = c;
	  suf++;
	}
      }
      cout << "max length" << max.size() << endl;
      cout << "max " << stoi(max) << endl;
      cout << "min " << stoi(min) << endl;
      
      int diff;
      diff = stoi(max) - stoi(min);
      cout << "diff::" << diff << endl;
      bool flag = false;
      for (int j = 0; j < s.size(); j++) {
	str = s[j];
	int tmp = stoi(str);
	if (diff == tmp) {
	  cout << j << " " << diff << " " << i - j + 1 << endl;
	  flag = true;
	}
      }
      if (flag)
	break;
      else
	s.push_back(to_string(diff));
    }
    
  }
  return 0;	
}

