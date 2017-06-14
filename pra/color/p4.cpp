#include <iostream>
#include <queue>
#include <utility>
#include <stdlib.h>

using namespace std;


bool pass(const int h, const int w, pair<int,int> &next) {

  if (next.first < 0 || next.first >= h)
    return false;
  if (next.second < 0 || next.second >= w)
    return false;

  return true;
}

int search(const int h, const int w, const int c, int **p)
{
  queue<pair<int,int> > q;
  pair<int,int> start = make_pair(0,0);
  q.push(start);
  int max = 0;
  
  int **tmp;
  tmp = (int **)malloc(sizeof(int*)*h);
  for (size_t i = 0; i < h; i++)
    tmp[i] = (int *)malloc(sizeof(int)*w);
  for (size_t i = 0; i < h; i++)
    for (size_t j = 0; j < w; j++)
      tmp[i][j]  = 0;
  
  while (!q.empty()) {
    pair<int,int> cur = q.front(); q.pop();
    if (!tmp[cur.first][cur.second]) {
      tmp[cur.first][cur.second] = 1;
      max++;
      int a1[] = { -1, 0, 1, 0 };
      int a2[] = { 0, 1, 0, -1 };
      for (size_t i = 0; i < 4; i++) {
	pair<int,int> next = make_pair(cur.first+a1[i], cur.second+a2[i]);
	if (pass(h,w,next))
	  if (c == p[next.first][next.second] && tmp[next.first][next.second] != 1) {
	    q.push(next);
	  }
      }  
    }
  }
  for (size_t i = 0; i < h; i++)
    free(tmp[i]);
  free(tmp);

  return max;
}


int rec(const int h, const int w, const int c, int **p, const int times) {
  
  int now, max;
  max = 0;
  pair<int,int> start = make_pair(0,0);
  

  int **tmp;
  tmp = (int **)malloc(sizeof(int*)*h);
  for (size_t i = 0; i < h; i++)
    tmp[i] = (int *)malloc(sizeof(int)*w);
  
  if (times < 5) {
    for (size_t k = 1; k <= 6; k++) {
      
      for (size_t i = 0; i < h; i++)
	for (size_t j = 0; j < w; j++)
	  tmp[i][j] = p[i][j];
      
      int fig = tmp[start.first][start.second];
      if (fig != k) {
	tmp[start.first][start.second] = k;
	queue<pair<int,int> > q;
	q.push(start);
	while (!q.empty()) {
	  pair<int,int> cur = q.front(); q.pop();
	  int a1[] = { -1, 0, 1, 0 };
	  int a2[] = { 0, 1, 0, -1 };
	  for (size_t i = 0; i < 4; i++) {
	    pair<int,int> next = make_pair(cur.first+a1[i], cur.second+a2[i]);
	    if (pass(h,w,next))
	      if (fig == tmp[next.first][next.second]) {
		tmp[next.first][next.second] = k;
		q.push(next);
	      }
	  }
	}
	now = rec(h,w,c,tmp,times+1);
	if (now > max)
	  max = now;
      }
    }
  } else if (times == 5) {
    for (size_t i = 0; i < h; i++)
      for(size_t j = 0; j < w; j++)
	tmp[i][j] = p[i][j];
    queue<pair<int,int> > q;
    q.push(start);
    int fig = tmp[start.first][start.second];
    if (fig != c) {
      tmp[start.first][start.second] = c;
      while (!q.empty()) {
	pair<int,int> cur = q.front(); q.pop();
	int a1[] = { -1, 0, 1, 0 };
	int a2[] = { 0, 1, 0, -1 };
	for (size_t i = 0; i < 4; i++) {
	  pair<int,int> next = make_pair(cur.first+a1[i], cur.second+a2[i]);
	  if (pass(h,w,next))
	    if (fig == tmp[next.first][next.second]) {
	      tmp[next.first][next.second] = c;
	      q.push(next);
	    }
	}
      }
      max = search(h,w,c,tmp);
    } 
  }
  
  for (size_t i = 0; i < h; i++)
    free(tmp[i]);
  free(tmp);
  
  return max;
}


    
int main(int argc, char *argv[])
{
  while (true) {
  int h, w, c;
  cin >> h >> w >> c;
  if (h == 0 && w == 0 && c == 0) break;
  int **p;
  p = (int**)malloc(sizeof(int *)*h);
  for (size_t i = 0; i < h; i++)
    p[i] = (int*)malloc(sizeof(int)*w);
  for (size_t i = 0; i < h; i++)
    for (size_t j = 0; j < w; j++)
      cin >> p[i][j];

  int max;
  max = rec(h,w,c,p,1);

  cout << max << endl;
  }
  return 0;
}
