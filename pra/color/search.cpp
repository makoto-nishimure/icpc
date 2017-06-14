#include <iostream>
#include <queue>
#include <utility>

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
  max++;
  int **tmp;
  tmp = (int **)malloc(sizeof(int*)*h);
  for (size_t i = 0; i < h; i++)
    tmp[i] = (int *)malloc(sizeof(int)*w);
  for (size_t i = 0; i < h; i++)
    for (size_t j = 0; j < w; j++)
      tmp[i][j]  = 0;
  
  while (!q.empty()) {
    pair<int,int> cur = q.front(); q.pop();
    tmp[cur.first][cur.second] = 1;
    int a1[] = { -1, 0, 1, 0 };
    int a2[] = { 0, 1, 0, -1 };
    for (size_t i = 0; i < 4; i++) {
      pair<int,int> next = make_pair(cur.first+a1[i], cur.second+a2[i]);
      if (pass(h,w,next))
	if (c == p[next.first][next.second] && tmp[next.first][next.second] != 1) {
	  max++;
	  q.push(next);
	}
    }  
  }
  return max;
}


    
int main(int argc, char *argv[])
{
  int h, w, c;
  cin >> h >> w >> c;
  //int p[h][h];
  int **p;
  p = (int**)malloc(sizeof(int *)*h);
  for (size_t i = 0; i < h; i++)
    p[i] = (int*)malloc(sizeof(int)*w);
  for (size_t i = 0; i < h; i++)
    for (size_t j = 0; j < w; j++)
      cin >> p[i][j];

  int max;
  max = search(h,w,c,p);

  cout << max << endl;
  
  return 0;
}
