#include <iostream>
#include <vector>
#include <stack>
#include <stdlib.h>
#include <cstdlib>

using namespace std;

//pair:p　これから行こうとしている場所
bool pass(const int w, const int h, const pair<int,int> p, const vector<vector<int> > &length, const vector<vector<int> > &width, const vector<pair<int,int> > &root) {
  
  //マイナス地点
  if(p.first < 0 || p.second < 0)
    return false;
  //wやhを超える
  if(p.first >= h || p.second >= w)
    return false;
  
  //通った道ではないか
  size_t size = root.size()-1;
  bool flag = true;
  for(int i = 0; i <= size; i++){
    if((p.first == root[i].first) && (p.second == root[i].second))
       flag = false;
       break;
  }
  if(!flag)
    return false;

  //壁があるかないか
  pair<int,int> cp = make_pair(root[size].first, root[size].second);
  //縦の壁
  if(abs(p.first - cp.first)) {
    int i = width[cp.first][cp.second];
    if(i)
      return false;
    else
      return true;
  }
  //横の壁
  else if(abs(p.second - cp.second)) {
    int i = length[cp.first][cp.second];
    if(i)
      return false;
    else
      return true;
  }
  return true;
}
void search(const int w, const int h, const vector<vector<int> > &length, const vector<vector<int> > &width, const vector<pair<int,int> > &root, stack<pair<int,int> > &junc) {

  pair<int,int> p = junc.top();
  pair<int,int> tmp;
  junc.pop();
  //down
  tmp = make_pair(p.first+1, p.second);
  if(pass(w, h, tmp, length, width, root))
    junc.push(tmp);
  //right
  tmp = make_pair(p.first, p.second+1);
  if(pass(w, h, tmp, length, width, root))
    junc.push(tmp);
  //up
  tmp = make_pair(p.first-1, p.second);
  if(pass(w, h, tmp, length, width, root))
    junc.push(tmp);
  //left
  tmp = make_pair(p.first, p.second-1);
  if(pass(w, h, tmp, length, width, root))
    junc.push(tmp);
}



int main(int argc, char *argv[]) {

  int h, w;  //height and width of maze

  
  cin >> w;
  cin >> h;

  vector<vector<int> > length;//(w-1,vector<int>(h));
  vector<vector<int> > width;//(w, vector<int>(h-1));
  
  vector<pair<int,int> > root;
  
  stack<pair<int,int> > junc; //junction
  
  length.resize(h); width.resize(h);
  for(int i = 0; i < h; i++) {
    length[i].resize(w);
    width[i].resize(w);
    }
  /*int **length, **width;
  length = (int **)malloc(sizeof(int *)*h);
  width = (int **)malloc(sizeof(int *)*h);
  for(int i = 0; i < w; i++) {
    length[i] = (int *)malloc(sizeof(int)*w);
    width[i] = (int *)malloc(sizeof(int)*w);
    }*/
  
  for(int i = 0; i < h-1; i++) {
    for(int j = 0; j < w-1; j++) {
      int e;
      cin >> e;
      length[i][j] = e;
    }
    for(int j = 0; j < w; j++) {
      int e;
      cin >> e;
      width[i][j] = e;
    } 
  }
  for(int j = 0; j < w-1; j++) {
    int e;
    cin >> e;
    length[h-1][j] = e;
  }

  junc.push(make_pair(0,0));
  //while(true){
    //search の方に記述してもいいかも？
    pair<int, int> p = junc.top();
    
    cout << "current::" << p.first << p.second << endl;

    root.push_back(make_pair(p.first, p.second));
    search(w, h, length, width, root, junc);
    
    for(int i = 0; i < junc.size(); i++) {
      p = junc.top();
      cout << "current::" << p.first << p.second << endl;
    }
    
    //}
		   

  
  return 0;
}
