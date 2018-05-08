#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main (void)
{
	vector<string> list;
	string item;
	while (getline(cin, item) && !item.empty()) {
		list.push_back(item);
	}
	puts(list[0].c_str());		
	return 0;
}
