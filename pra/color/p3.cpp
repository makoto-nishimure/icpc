#include <iostream>
#include <queue>
#include <utility>

using namespace std;


bool pass(const int h, const int w, int first, int second) {

  if (first < 0 || first >= h)
    return false;
  if (second < 0 || second >= w)
    return false;

  return true;
}

int rec(const int h, const int w, const int c, int **p, const int times) {
  queue<pair<int,int> > q;

  int **tmp;
  tmp = (int**)malloc(sizeof(int *)*h);
  for (size_t i = 0; i < h; i++)
    tmp[i] = (int*)malloc(sizeof(int)*w);
  
  pair<int,int> start,add;
  start = make_pair(0,0);
 
  int max = 0;
  int now;
 
  if (times < 5) {
    cout << "times::" << times << endl;
    for (size_t i = 1; i <= 6; i++) {
      cout << i << endl;
      
      for (size_t j = 0; j < h; j++)
	for (size_t k = 0; k < w; k++)
	  tmp[j][k] = p[j][k];
      q.push(start);
      while (!q.empty()) {
	
	pair<int,int> t = q.front(); q.pop();
	tmp[0][0] = i;
	int fig = i;

	//up
	add = make_pair(t.first-1,t.second);
	if (pass(h,w,add.first,add.second))
	  if (fig == tmp[add.first][add.second]) {
	    tmp[add.first][add.second] = fig;
	    q.push(add);
	  }
	//right
	add = make_pair(t.first,t.second+1);
	if (pass(h,w,add.first,add.second))
	  if (fig == tmp[add.first][add.second]) {
	    tmp[add.first][add.second] = fig;
	    q.push(add);
	  }
	//down
	add = make_pair(t.first+1,t.second);
	if (pass(h,w,add.first,add.second))
	  if (fig == tmp[add.first][add.second]) {
	    tmp[add.first][add.second] = fig;
	    q.push(add);
	  }
	//left
	add = make_pair(t.first,t.second-1);
	if (pass(h,w,add.first,add.second))
	  if (fig == tmp[add.first][add.second]) {
	  tmp[add.first][add.second] = fig;
	  q.push(add);
	}
      }
      now = rec(h,w,c,tmp,times+1);
      if (max < now)
	max = now;
    }
    
  } else if (times == 5) {
    for (size_t j = 0; j < h; j++)
      for (size_t k = 0; k < w; k++)
	tmp[j][k] = p[j][k];    
    cout << "times::" << times << endl;
    cout << c << endl;
    
    tmp[0][0] = c;
    int fig = c;
    max++;
    q.push(start);
    while (!q.empty()) {
      
      pair<int,int> t = q.front(); q.pop();
      //up
      add = make_pair(t.first-1,t.second);
      if (pass(h,w,add.first,add.second))
	 if (fig == tmp[add.first][add.second]) {
	   tmp[add.first][add.second] = c;
	   q.push(add);
	   max++;
	 }
      //right
      add = make_pair(t.first,t.second+1);
      if (pass(h,w,add.first, add.second))
	if (fig == tmp[add.first][add.second+1]) {
	  tmp[add.first][add.second] = c;
	  q.push(add);
	  max++;
	}
      //down
      add = make_pair(t.first+1,t.second);
      if (pass(h,w,add.first,add.second))
	if (fig == tmp[add.first][add.second]) {
	  tmp[add.first][add.second] = c;
	  q.push(add);
	  max++;
	}
      //left
      add = make_pair(t.first,t.second-1);
      if (pass(h,w,add.first,add.second))
	if (fig == tmp[add.first][add.second]) {
	  tmp[add.first][add.second] = c;
	  q.push(add);
	   max++;
	}
    }
    /*
      for (size_t i = 0; i < h; i++) {
      for (size_t j = 0; j < w; j++)
      cout << tmp[i][j] << " ";
      cout << endl;
      }
      cout << endl;
    */
  }
  
  for (size_t i = 0; i < h; i++)
    free(tmp[i]);
  free(tmp);
  
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
  max = rec(h,w,c,p,1);

  cout << max << endl;
  
  return 0;
}
