#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <stack>
#include <queue>
#include <utility>
#include <algorithm>
#include <string>
#include <bitset>

using namespace std;

void mal(int **a, int h, int w) {
  
  a = (int **)malloc(sizeof(int*)*h);
  for (int i = 0; i < h; i++)
    a[i] = (int*)malloc(sizeof(int)*w);

}
//true::範囲内 false::範囲外
bool jud(int h, int w, pair<int,int> cur, pair<int,int> next, int **tate, int yoko)
{
  if (next.first < 0 || next.second < 0)
    return false;
  else if (next.second >= w || next.first >= h)
    return false;
  else {
    
    
    
  }
}


int main(void)
{
  while (true) {

    int h, w;
    cin >> w >> h;
    if (h == 0 && w == 0) break;

    int **gyo, **retu, **pass;
    mal(gyo, h, w-1); mal(retu, h-1, w); mal(pass, h, w);

    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w-1; j++)
	cin >> gyo[i][j];
      if (i < h-1) {
	for (int j = 0; j < w; j++)
	  cin >> retu[i][j];
      }
    }
    memset(pass, 0, sizeof(pass));
    
    int t[] = {1, 0, 0, -1};
    int y[] = {0, 1, -1, 0};
    
    pair<int,int> start, goal;
    start= make_pair(0,0);
    goal = make_pair(h-1,w-1);
    queue<pair<int,int> > q;
    q.push_back(start);

    while (!q.empty()) {
      pair<int,int> cur = q.front; q.pop();
      if (cur == goal)
	cout << pass[cur.first][cur.second] << endl;
      else {
	for (int i = 0; i < 4; i++) {
	  pair<int,int> next = make_pair(cur.first+t[i]+y[i], cur.second+t[i]+y[i]);
	  if (jud(h,w,cur,next,gyo,retu)) {
	    if (pass[next.first][next.second] == 0) {
	      pass[next.first][next.second] = pass[cur.first][cur.second] + 1;
	      q.push_back(next);
	    }
	    
	  }
	}
      }
      
    }

  }
  return 0;	
}

