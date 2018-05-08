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
    
    bool correct = true;
    bool once = true;
    int i = 0;
    while (i < s1.size()) {
      //nor
      if ((int)s1[i] != 34) {
	int start = i;
	int end = 0;
	while (i < s1.size()) {
	  if ((int)s1[i+1] == 34)
	    break;
	  else if (i+1 == s1.size())
	    break;
	  else
	    i++;
	}
	end = i; i++;
	string tmp(s1,start,end-start+1);
	nor.push(tmp);
      }
      //quo
      else if ((int)s1[i] == 34) {
	int start = i; i++;
	int end = 0;
	while (i < s1.size()) {
	  if ((int)s1[i] == 34)
	    break;
	  else
	    i++;
	}
       	end = i; i++;
	string tmp(s1,start,end-start+1);
	quo.push(tmp);
      }
    }

     //nor,quo確認
    /*
    while (!nor.empty()) {
      cout << nor.front() << " ";
      nor.pop();
    } cout << endl;
    
    while (!quo.empty()) {
      cout << quo.front() << " ";
      quo.pop();
    } cout << endl;
    */
   
    i = 0;
    while (i < s2.size()) {
      if (nor.empty() && quo.empty()) {
	correct = false;
	break;
      }
      //nor
      if ((int)s2[i] != 34) {
	int start = i;
	int end = 0;
	while (i < s2.size()) {
	  if ((int)s2[i+1] == 34)
	    break;
	  else if (i+1 == s2.size())
	    break;
	  else
	    i++;
	}
	end = i;
	string tmp(s2,start,end-start+1);
	string pop = nor.front(); nor.pop();
	//cout << "tmp::" << tmp << endl;
	//cout << "pop::" << pop << endl;
	if (tmp == pop)
	  i++;
	else {
	  correct = false;
	  break;
	}
      }
      //quo
      else if ((int)s2[i] == 34) {
	int start = i; i++;
	int end = 0;
	while (i < s2.size()) {
	  if (s2[i] == 34)
	    break;
	  else
	    i++;
	}
	end = i;
	string tmp(s2,start,end-start+1);
	string pop = quo.front(); quo.pop();
	//cout << "tmp::" << tmp << endl;
	//cout << "pop::" << pop << endl;
	if (tmp == pop)
	  i++;
	else if (once) {
	  once = false;
	  i++;
	}
	else {
	  correct = false;
	  break;
	}
      }      
    }
    if (!nor.empty() || !quo.empty())
      correct = false;
    
    if (correct && once)
      cout << "IDENTICAL" << endl;
    else if (correct && !once)
      cout << "CLOSE" << endl;
    else
      cout << "DIFFERENT" << endl;
    
  }
  return 0;
}
