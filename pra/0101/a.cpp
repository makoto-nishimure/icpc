#include <iostream>
#include <string>

using namespace std;

int main(void)
{
  int n;
  cin >> n;

  //vector<string> vec;
  for (int i = 0; i < n; i++) {
    string str;
    while (getline(cin, str)) {
      for (int j = 0; j < str.size; j++) {
	string word;
	
      }
      cout << str << endl;
      cout << str.size() << endl;
    }
  }
  
  return 0;
}
