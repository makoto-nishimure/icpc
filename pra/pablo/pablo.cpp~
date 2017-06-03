#include <iostream>
#include <vector>
#include <stack>
#include <stdlib.h>

using namespace std;


void create_map(int n, vector<pair<int,int> > &nd, vector<pair<int,int> > &place, int **array) {
  
  for(int i = 0; i < n-1; i++) {
    
    pair<int,int> p = nd[i];
    pair<int,int> adj  = place[p.first];

    pair<int,int> np = p;
    
    if(p.second == 0)
      np.second = adj.second - 1;
    else if(p.second == 1)
      np.first  = adj.first + 1;
    else if(p.second == 2)
      np.second = adj.second - 1;
    else if(p.second == 3)
      np.first  = adj.first + 1;
    
    array[np.first][np.second] = i+1;
    place.push_back(np);
    
  }


}



int main(int argc, char *argv[]){

  int n;
  cin >> n;

  vector<pair<int,int> > nd;
  vector<pair<int,int> > place;

  for(int i = 0; i < n-1; i++) {
    int e, d;
    cin >> e;
    cin >> d;
    nd.push_back(make_pair(e,d));
  }


  int tmp = n*2;
  int **array;
  array = (int **)malloc(sizeof(int *)*tmp);
  for(int i = 0; i < tmp; i++)
    array[i] = (int *)malloc(sizeof(int)*tmp);

  for(int i = 0; i < tmp; i++)
    for(int j = 0; j < tmp; j++)
      array[i][j]  = -1;
  
  
  array[n][n] = 0;
  place.push_back(make_pair(tmp,tmp));

  create_map(n, nd, place, array);
  
  for(int i = 0; i < tmp; i++) {
    for(int j = 0; j < tmp; j++)
      cout << array[i][j] << " ";
    cout << endl;
  }

  for(int i = 0; i < tmp; i++)
    free(array[i]);
  free(array);
  
  return 0;
}
