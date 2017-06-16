#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
  while (true) {
  int h;
  cin >> h;
  if (h == 0) break;
  int array[h][5];
  int cp[h][5];
  int sco = 0;
  
  for (size_t i = 0; i < h; i++)
    for (size_t j = 0; j < 5; j++)
      cin >> array[i][j];

  while (true)  {
  int num;
  
  for (size_t i = 0; i < h; i++)
    for (size_t j = 0; j < 5; j++)
      cp[i][j] = array[i][j];
  
  for (size_t i = 0; i < h; i++){
    int tmp = array[i][0];
    int count = 0;
    num = 0;
    for (size_t j = 0; j < 5; j++){
      if (tmp == array[i][j]) {
	count++;
	num = tmp;
      } else {
	if (count >= 3) break;
	else {
	  tmp = array[i][j];
	  count = 1;
	  num = tmp;
	}
      } 
    }
    if (count >= 3) {
      for (size_t j = 0; j < 5; j++) {
	if (num == array[i][j])
	  array[i][j] = 0;
      }
      //cout << "num::" << num << endl;
      //cout << "count::" << count << endl;
      sco+=num*count;
    }
  }
  bool flag = true;
  for (size_t i = 0; i < h; i++)
    for (size_t j = 0; j < 5; j++ )
      if (cp[i][j] != array[i][j])
	flag = false;
  if (flag)
    break;

  
 
  for (size_t k = 1; k < h; k++) {
    for (size_t j = 0; j < 5; j++) {
      if (array[k][j] == 0) {
	for (int i = k; i > 0; i--) {
	  array[i][j] = array[i-1][j];
	}
	array[0][j] = 0;
      }
    }
  }
  
  }
   
  cout << sco << endl;
  }
  return 0;
  
}
