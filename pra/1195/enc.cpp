#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <queue>


using namespace std;

//p::修正し終わった場所
int rec(string str, const int p, queue<string> &f, queue<string> &l)
{
  int count = 0;
  
  if (p == str.length()) {
    //すべて復号した
    //cout << str << endl;
    if (f.size() < 5) {
      f.push(str);
    } else {
      if (l.size() < 5) {
	l.push(str);
      }
      else {
	l.pop();
	l.push(str);
      }
    }
    return 1;
  } else {
    //復号化
    bool flag = true;
    bool flag2 = true;
    bool f3 = true;
   
    int c = str[p];
    int nc = c+1;
    for (size_t i = 0; i < p; i++)
      if (c == str[i])
	flag = false;
      else if (nc == str[i])
	flag2 = false;
    
   
      if (flag) { //str[p]が出現なし
	if (flag2) {
	  if (c == 97) 
	    count += rec(str,p+1,f,l);
	  if (c == 122)
	    count += 0; 
	  else {
	    c++;
	    str[p] = c;
	    count += rec(str,p+1,f,l);
	  }
	} else {
	  count += rec(str,p+1,f,l);
	}
      } else if (f3) {    //str[p]が出現あり
	//1
	if (c == 122) {
	  count += rec(str,p+1,f,l);
	} else {
	  count += rec(str,p+1,f,l);	
	  //2
	  bool f2 = true;
	  int nextc = c + 1;
	  for (size_t i = 0; i < p; i++)
	    if(nextc == str[i])
	      f2 = false;
	  if (f2) {
	    str[p] = nextc;
	    count += rec(str,p+1,f,l);
	  }
	}
	
      }
  }
  
  return count;
}

int main(int argc, char *argv[])
{

  while (true) {
  string str;

  int bt[26];
  for (size_t i = 0; i < 26; i++)
    bt[i] = 0;
  
  getline(cin,str);
  if (str[0] == '#') break;
  int count;
  queue<string> first, last;

  
  count = rec(str, 0, first, last); 

  cout << count << endl;
  while (!first.empty()) {
    string tmp = first.front(); first.pop();
    cout << tmp << endl;
  }
  while( !last.empty()) {
     string tmp = last.front(); last.pop();
    cout << tmp << endl;
  }
  }
  return true;
}
