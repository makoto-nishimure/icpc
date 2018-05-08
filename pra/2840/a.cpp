#include <iostream>
#include <string>
#include <vector>
#include <string.h>
using namespace std;

int main(void) {

	string T, P;
	cin >> T;
	cin >> P;
	int array[P.size()];
	int pos = 0;
	bool flag = true;
	for (int i = 0; i < P.size(); i++)
		array[i] = 0;
#ifdef DEBUG
	for (int i = 0; i < P.size(); i++)
		cout << array[i] << endl;
#endif
	for (int i = 0; i < T.size(); i++) {
		if (P.size() < pos) {
			flag = false;
			break;
		}
		if (T[i] == P[pos]) {
			pos++;	
#ifdef DEBUG
	cout << pos-1 << endl;
	cout << P[pos-1] << endl;
#endif
		}					
		else if (pos) {
			if (T[i] == P[pos-1]) {
				array[pos-1]++;	
			}	
		}
	} 
#ifdef DEBUG
	cout << flag << endl;
#endif
	//まず，T.size < P.size となることはない．
	//一意の部分列が見つかった場合
	//posの値は，P.size と等しい．
	if (flag && pos == P.size()) {
		bool f = true;
		for (int i = 0; i < P.size(); i++) {
#ifdef DEBUG
	cout << array[i] << endl;
#endif
			if (array[i] != 0)
				f = false;		
		}	
		if (f) {
			printf("yes");
			return 0;
		}
	}
	printf("no");
	return 0;
}
