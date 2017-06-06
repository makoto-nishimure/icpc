#include <iostream>
#include <vector>
#include <stack>
#include <stdlib.h>
#include <cstdlib>

using namespace std;

int COST;
bool GOAL_FLAG;

//pair:p　これから行こうとしている場所
bool pass(const int w, const int h, const pair<int,int> p, const vector<vector<int> > &length, const vector<vector<int> > &width, const vector<pair<int,int> > &root) {

  //ゴールした時のコストと現在のコストを比較し、
  //現在のコストが大きい時、falseを返す
  if (GOAL_FLAG) {
    if(COST <= root.size()+1) //root.sizeだけかも？
      return false;
  }
  
  //マイナス地点
  if (p.first < 0 || p.second < 0)
    return false;
  //wやhを超える
  if (p.first >= h || p.second >= w)
    return false;
  
  //通った道ではないか
  size_t size = root.size()-1;
  bool flag = true;
  for (int i = 0; i <= size; i++){
    if (p == root[i]) {
      flag = false;
      break;
    }
  }
  if (!flag)
    return false;
  
  //壁があるかないか
  pair<int,int> cp = make_pair(root[size].first, root[size].second);
  //縦の壁
  if (abs(p.first - cp.first)) {
    int i = width[cp.first][cp.second];
    if (i)
      return false;
    else
      return true;
  }
  //横の壁
  else if (abs(p.second - cp.second)) {
    int i = length[cp.first][cp.second];
    if (i)
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

    //left
  tmp = make_pair(p.first, p.second-1);
  if (pass(w, h, tmp, length, width, root)){
    junc.push(tmp);
    //cout << "candidate::" << tmp.first << tmp.second << endl;
  }

  //up
  tmp = make_pair(p.first-1, p.second);
  if (pass(w, h, tmp, length, width, root)){
    junc.push(tmp);
    //cout << "candidate::" << tmp.first << tmp.second << endl;
  }

  //right
  tmp = make_pair(p.first, p.second+1);
  if (pass(w, h, tmp, length, width, root)){
    junc.push(tmp);
    //cout << "candidate::" << tmp.first << tmp.second << endl;
  }

  //down
  tmp = make_pair(p.first+1, p.second);
  if (pass(w, h, tmp, length, width, root)){
    junc.push(tmp);
    //cout << "candidate::" << tmp.first << tmp.second << endl;
  }
  
}


//前の分岐点に戻したい

void back() { 



}


int main(int argc, char *argv[]) {

  int h, w;  //height and width of maze
  
  cin >> w;
  cin >> h;

  COST = 0;
  GOAL_FLAG = false;
  
  vector<vector<int> > length;//(w-1,vector<int>(h));
  vector<vector<int> > width;//(w, vector<int>(h-1));
  
  vector<pair<int,int> > root;

  pair<int,int> goal = make_pair(h-1,w-1);
  
  stack<pair<int,int> > junc; //junction
  
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

  junc.push(make_pair(0,0));
  while (!junc.empty()) {
    //for(int j = 0; j < 19; j++){
    //search の方に記述してもいいかも？
  pair<int, int> p = junc.top(); //現在地をとってくる
    
  cout << "current::" << p.first << p.second << endl;

  root.push_back(make_pair(p.first, p.second));  //現在地を通った道として記録
  search(w, h, length, width, root, junc);  //いける分岐を探して、juncに挿入

  if (goal == junc.top()) { //合ってるかわからん
    COST = root.size() + 1;
    GOAL_FLAG = true;
    junc.pop();
    break;
  }
  /*
  p = junc.top();
  cout << "next::" << p.first << p.second << endl;
  
  size_t size = root.size();
  for (int i = 0; i < size; i++)
    cout << "root::" << root[i].first << root[i].second << endl;
  */
  }
  cout << "GOAL COST::" << COST << endl;
  cout << "STACK_SIZE::" << junc.size() << endl;
  size_t a = junc.size();
  for (int i = 0; i < a; i++) {
    pair<int, int> tmp = junc.top();
    junc.pop();
    cout << "stack::" << tmp.first << tmp.second <<endl;
  }
    
  
  return 0;
}
