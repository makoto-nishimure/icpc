#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main(void)
{
  while (true) {
    
    queue<string> nor, quo;
    string s1, s2;
    cin >> s1;
    if (s1 == ".")
      break;
    cin >> s2;

    //s1をqueueに詰め込んでいく
    int i = 0;
    while (i < s1.size()) {
      //nor
      if ((int)s1[i] != 34) {
	nor.push(s1[i]);
	i++;
      }
      //quo
      else if ((int)s1[i] == 34) {
	while (true) {
	  quo.push(s1[i]);
	  i++;
	  if ((int)s1[i] == 34) {
	    quo.push(s1[i]);
	    i++;
	    break;
	  }
	}
      }
    }
    //nor,quo確認
    /*
    while (!nor.empty()) {
      cout << nor.front();
      nor.pop();
    } cout << endl;
    
    while (!quo.empty()) {
      cout << quo.front();
      quo.pop();
    } cout << endl;
    */

    i = 0;
    bool one_t = true;
    while (i < s2.size()) {
      if (nor.empty() && quo.empty()) break;
      
      //nor
      if ((int)s2[i] != 34) {
	char c = nor.front(); nor.pop();
	if (c == s2[i])
	  i++;
	else
	  break;
      }
      //quo
      else if ((int)s2[i] == 34) {
	string tmp; int count = 0;
	tmp[count] = s2[i];
	i++; count++;
	for ( ; i < s2.size(); i++) {
	  if ((int)s2[i] == 34) {
	    tmp[count] = s2[i];
	    i++;
	    break;
	  }
	  else {
	    tmp[count] = s2[i];
	    i++; count++;
	  }
	}
	cout << tmp << endl;
	
      }
    }
  }
  return 0;
}
  
