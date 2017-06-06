#include <iostream>
#include <vector>
#include <stack>
#include <stdlib.h>
#include <cstdlib>
#include <queue>

using namespace std;

//pair:p　これから行こうとしている場所
bool pass(const int w, const int h, const pair<int,int> cur, const pair<int,int> p, const vector<vector<int> > &length, const vector<vector<int> > &width, const vector<vector<int> > &passed) {
  
  //マイナス地点
  if (p.first < 0 || p.second < 0)
    return false;
  //wやhを超える
  if (p.first >= h || p.second >= w)
    return false;

  //まだ訪れてない場所
  if (passed[p.first][p.second] == 0) {  
    //壁があるかないか
    //縦の壁
    if (abs(p.first - cur.first)) {
      int i = width[cur.first][cur.second];
      if (i)
	return false;
      else
	return true;
    }
    //横の壁
    else if (abs(p.second - cur.second)) {
      int i = length[cur.first][cur.second];
      if (i)
	return false;
      else
	return true;
    }
  }
  
  return false;
}

void search(const int w, const int h, const vector<vector<int> > &length, const vector<vector<int> > &width, pair<int,int> cur, queue<pair<int,int> > &q, vector<vector<int> > &passed) {

				    
  pair<int,int> next;
  //left
  next = make_pair(cur.first, cur.second-1);
  if (pass(w, h, cur, next, length, width, passed)){
    q.push(next);
    passed[next.first][next.second] = passed[cur.first][cur.second] + 1;
    //cout << "candidate::" << next.first << next.second << endl;
  }
  
  //up
  next = make_pair(cur.first-1, cur.second);
  if (pass(w, h, cur, next, length, width, passed)){
    q.push(next);
    passed[next.first][next.second] = passed[cur.first][cur.second] + 1;
    //cout << "candidate::" << next.first << next.second << endl;
  }
  
  //right
  next = make_pair(cur.first, cur.second+1);
  if (pass(w, h, cur, next, length, width, passed)){
    q.push(next);
    passed[next.first][next.second] = passed[cur.first][cur.second] + 1;
    //cout << "candidate::" << next.first << next.second << endl;
  }
  
  //down
  next = make_pair(cur.first+1, cur.second);
  if (pass(w, h, cur, next, length, width, passed)){
    q.push(next);
    passed[next.first][next.second] = passed[cur.first][cur.second] + 1;
    //cout << "candidate::" << next.first << next.second << endl;
  }
  
}




int main(int argc, char *argv[]) {

  int h, w;  //height and width of maze
  bool flag = false;
  
  cin >> w;
  cin >> h;
  
  vector<vector<int> > length;//(w-1,vector<int>(h));
  vector<vector<int> > width;//(w, vector<int>(h-1));

  vector<vector<int> > passed;
  pair<int,int> start, goal;
  start = make_pair(0,0);
  goal = make_pair(h-1,w-1);

  length.resize(h); width.resize(h);
  for (int i = 0; i < h; i++) {
    length[i].resize(w);
    width[i].resize(w);
    }
  
  for (int i = 0; i < h-1; i++) {
    for (int j = 0; j < w-1; j++) {
      int e;
      cin >> e;
      length[i][j] = e;
    }
    for (int j = 0; j < w; j++) {
      int e;
      cin >> e;
      width[i][j] = e;
    } 
  }
  for (int j = 0; j < w-1; j++) {
    int e;
    cin >> e;
    length[h-1][j] = e;
  }

  for (int i = 0; i < w; i++) {
    vector<int> v(h, 0);
    passed.push_back(v);
  }

  queue<pair<int, int> > q;
  q.push(start);

  while ( !q.empty() ) {
    pair<int,int> cur = q.front(); q.pop();
    
    if (cur == goal) {
      flag = true;
      cout << passed[cur.first][cur.second] << endl;
    }
    search(w, h, length, width, cur, q, passed);

  }
  
  if(!flag)
    cout << 0 << endl;
  
  
  return 0;
  
}
