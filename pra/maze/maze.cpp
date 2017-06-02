#include <iostream>
#include <vector>
#include <stack>
#include <stdlib.h>


using namespace std;

int main(int argc, char *argv[]) {

  int h, w;  //height and width of maze

  
  cin >> w;
  cin >> h;

  vector<vector<int> > length;//(w-1,vector<int>(h));
  vector<vector<int> > width;//(w, vector<int>(h-1));

  stack<pair<int,int>> junc; //junction
  
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
  while(true){
    pair<int, int> p = junc.top();
    

    
  }


  
  return 0;
}
