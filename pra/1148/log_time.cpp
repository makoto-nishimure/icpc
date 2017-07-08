#include <iostream>
#include <vector>
#include <utility>
#include <stdlib.h>

using namespace std;

int main(void)
{
  while (true) {
    int n, m;
    cin >> n >> m;
    if (n == 0 && m == 0) break;
    int r;
    cin >> r;
    int time[r], pc[r], stu[r], log[r];
    

    for (size_t i = 0; i < r; i++) {
      cin >> time[i] >> pc[i] >> stu[i] >> log[i];   
    }
    int que;
    cin >> que;
    int ts[que], te[que], qm[que];
    for (size_t i = 0; i < que; i++) {
      cin >> ts[i] >> te[i] >> qm[i];
    }
    //入力終

    for (size_t k = 0; k < que; k++) {

      int start = ts[k];
      int end = te[k];
      int diff = end - start;
      int student = qm[k];
      vector<int> timecount;
      timecount.resize(diff);
      for (size_t i = 0; i < diff; i++)
	timecount[i] = 0;

      for (size_t i = 0; i < r; i++) {
	int intime, outtime;

	//questionの学生のrecode かつ　ログインの時
	if (student == stu[i] && log[i]) {
	  intime = time[i];
	  //pc番号控え
	  int pcnum = pc[i]; 
	  int j = i + 1;
	  //ログアウト記録を探す
	  while (true) {
	    if(student == stu[j] && pcnum == pc[j]) {
	      outtime = time[j];

	      if (intime < start) intime = start;
	      if (outtime > end) outtime = end;
	      intime -= start;
	      outtime -= start;

	         
	      for (int l = intime; l < outtime; l++)
		timecount[l] = 1;
	      break;
	    }
	    j++;
	    if (j > r)
	      break;
	  }
	}
      }
      int cnt = 0;
      for (size_t i = 0; i < diff; i++){
	if (timecount[i])
	  cnt++;
      }
      cout << cnt << endl;
     

    }
  }
  
  
  return 0;
  
}
