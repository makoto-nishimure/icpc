#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(void) {

  while (true) {
  string str;
  getline(cin,str);
  if (str[0] == '.') break;
  bool flag = true;
  stack<int> s;
  for (size_t i = 0; str[i] != '\0'; i++) {
    //cout << i << endl;
    int c = str[i];
    if (c == 40) {
      s.push(0);
      //cout << "push::0" << endl;
    }
    else if (c  == 91) {
      s.push(1);
      //cout << "push::1" << endl;
    }
    else if (c == 41) {
      if (s.empty()) {
	flag = false;
	break;
      }
      else {
      if (s.top() == 0) {
	s.pop();
	//cout << "pop::0" << endl;
      }
      else
	break;
      }
    }
    else if (c == 93) {
      if (s.empty()) {
	flag = false;
	break;
      }
      else {
	if (s.top() == 1) {
	  s.pop();
	//cout << "pop::1" <<endl;
	}
	else
	  break;
      }
    }
	
  }
  
  if (s.empty() && flag)
    cout << "yes" << endl;
  else
    cout << "no" << endl;

  //cout << str << endl;
  }
  return 0;

}
