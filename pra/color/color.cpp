#include <iostream>
#include <vector>
#include <utility>

using namespace std;

//自分の領地をリストアップ
void own_box(const int h, const int w, const vector<vector<int> > &p, vector<pair<int,int> > &own)
{
  pair<int,int> cur = make_pair(0,0);
  own.push_back(cur);
  const int num = p[0][0];
  int side[4][4] = { {-1,0}, {0,1}, {1,0}, {0,-1} };
  size_t tmp_len = 0;
  
  
  for (size_t i = 0; tmp_len != own.size(); i++) {
    tmp_len = own.size();
    cur = make_pair(own[i].first,own[i].second);

    for (size_t j = 0; j < 4; j++) {
      pair<int,int> ad = make_pair(cur.first+side[j]1 5 6 1 2[0],cur.second+side[j][1]);
      if (ad.first <= -1 || ad.first >= h)
	break;
      else if (ad.second <= -1 || ad.second >= w)
	break;
      cout << ad.first << "," << ad.second << endl;
      if (num == p[ad.first][ad.second]) {
	own.push_back(ad);
      }
    }
    
  }
  

}

int main(int argc, char *argv[])
{
  int h, w, c;
  cin >> h >> w >> c;
  vector<vector<int> > p;
  p.resize(h);
  for (size_t i = 0; i < h; i++)
    p[i].resize(w);
  for (size_t i = 0; i < h; i++)
    for (size_t j = 0; j < w; j++)
      cin >> p[i][j];


  vector<pair<int,int> >own;
  //vector<pair<int, pair<int,int> > >adj;

  own_box(h,w,p,own);
  for(size_t i = 0; i < own.size(); i++) {
    pair<int,int> tmp = own[i];
    cout << "add:" << tmp.first << "," << tmp.second << endl;
  }
  return 0;
}
