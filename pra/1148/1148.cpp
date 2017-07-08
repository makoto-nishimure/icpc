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
    //int time[r], pc[r], stu[r], log[r];
    int *time, *pc, *stu, *log;

    time = (int*)malloc(sizeof(int)*r);
    pc   = (int*)malloc(sizeof(int)*r);
    stu  = (int*)malloc(sizeof(int)*r);
    log  = (int*)malloc(sizeof(int)*r);

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

    //question
    for (size_t k = 0; k < que; k++) {

      vector<int> accep;
      for (size_t i = 0; i < r; i++) {
	if (stu[i] == qm[k]) {
	  accep.push_back(i);
	}
      }

      int tl[accep.size()]; //time log
      int ll[accep.size()]; //loginout log
      int pl[accep.size()]; //pc log
      
      for (size_t i = 0; i < accep.size(); i++) {
	tl[i] = time[accep[i]];
	ll[i] = log[accep[i]];
	pl[i] = pc[accep[i]];
      }

      cout << "    a" << endl;
      
      int diff = te[k] - ts[k];

      cout << diff << endl;
      vector<int> timecount;
      timecount.resize(diff);
      for (size_t i = 0; i < diff; i++)
	timecount[i] = 0;
      
      for (size_t i = 0; i < accep.size(); i++) {
	int start, end;
	
	//ログイン
	if (ll[i]) { 
	  if (tl[i] < te[k]) {
	    start = tl[i];
	    
	    int pcnum = pl[i];

	    cout << " pcnum " << pcnum << endl;
	    int j = i;
	    while (true) {
	      //ログインしたPC番号に対するログアウト
	      if (pl[j] == pcnum && ll[j] == 0) {
		end = tl[j];
		cout << " end pcnum " << pl[j] << endl;
		cout << " end " << end << endl;
		//ログインがtsより前の時
		if (start < ts[k]) {
		  start = ts[k];
		} start = start - ts[k];
		//ログアウトがteより後の時
		
		if (te[k] < end) {
		  end = te[k];
		} end = end -  ts[k];

		cout << start << "    " << end  << endl;
		for (size_t l = start; l < end; l++)
		  timecount[l] = 1;
		break;
	      }
	      j++;
	      if (j > accep.size())
		break;

	    }
	  }
	}

      }
      cout << "   b" << endl;
      
      int cnt = 0;
      for (size_t i = 0; i < diff; i++)
	if (timecount[i])
	  cnt++;
      cout << cnt << endl;
    }

    free(time);
    free(pc);
    free(stu);
    free(log);
  }
  
  return true;
}

