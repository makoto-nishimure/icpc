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


//pair:p　これから行こうとしている場所
bool pass(const int w, const int h, const pair<int,int> cur, const pair<int,int> p, const vector<vector<int> > &length, const vector<vector<int> > &width, const vector<vector<int> > &passed) {
  
  //マイナス地点
  if (p.first < 0 || p.second < 0) return false;
  //wやhを超える
  if (p.first >= h || p.second >= w) return false;

  //まだ訪れてない場所
  if (passed[p.first][p.second] == 0) {  
    //壁があるかないか
    //縦の壁
    if (abs(p.first - cur.first)) {
      if (p.first - cur.first > 0) {
	int i = width[cur.first][cur.second];
	if (i) return false;
	else   return true;
      }
      else {
	int i = width[p.first][p.second];
	if (i) return false;
	else   return true;
      }
    }
    //横の壁
    else if (abs(p.second - cur.second)) {
      if (p.second - cur.second > 0) {
	int i = length[cur.first][cur.second];
	if (i) return false;
	else   return true;
      }
      else {
	int i = length[p.first][p.second];
	if (i) return false;
	else   return true;
      }  
    }
  }
  return false;
}

void search(const int w, const int h, const vector<vector<int> > &length, const vector<vector<int> > &width, pair<int,int> cur, queue<pair<int,int> > &q, vector<vector<int> > &passed) {

  pair<int,int> next;

  //down
  next = make_pair(cur.first+1, cur.second);
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
  
  //up
  next = make_pair(cur.first-1, cur.second);
  if (pass(w, h, cur, next, length, width, passed)){
    q.push(next);
    passed[next.first][next.second] = passed[cur.first][cur.second] + 1;
    //cout << "candidate::" << next.first << next.second << endl;
  }
  
  //left
  next = make_pair(cur.first, cur.second-1);
  if (pass(w, h, cur, next, length, width, passed)){
    q.push(next);
    passed[next.first][next.second] = passed[cur.first][cur.second] + 1;
    //cout << "candidate::" << next.first << next.second << endl;
  }
}

int main(void)
{
  while (true) {

    int h, w;
    cin >> h >> w;
    if (h == 0 && w == 0) break;
    vector<vector<int> > gyo, retu, pass;
    gyo.resize(h); retu.resize(h); pass.resize(h);
    for (int i = 0; i < h; i++) {
      gyo[i].resize(w);
      retu[i].resize(w);
      pass[i].resize(w);
    }
    
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w-1; j++)
	cin >> gyo[i][j];
      if (i < h-1) {
	for (int j = 0; j < w; j++)
	  cin >> retu[i][j];
      }
    }


    
    
    for (int i = 0; i < h; i++) 
      for (int j = 0; j < w; j++)  
	passed[i][j] = 0;
    
    queue<pair<int, int> > q;
    q.push(start);
    int tmp;
    while ( !q.empty() ) {
      pair<int,int> cur = q.front(); q.pop();
      //cout << "cur::" << cur.first << cur.second << endl;
      if (cur == goal) {
	flag = true;
	tmp =  pass[cur.first][cur.second] + 1;
      }
      search(w, h, length, width, cur, q, pass);
    }
    if(!flag)
      tmp = -1;
  }
  
  



    
    
  }
    return 0;	
}
  
  
