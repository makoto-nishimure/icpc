#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;
vector<vector<pair<int,int>>> es;
vector<int> depth;

template <typename T>
std::ostream& operator<<(ostream&os, const vector<T>& v) 
{ 
   os<<"(";
   for (typename vector<T>::const_iterator it = v.begin() ; it != v.end() ; ++it )
       os << *it << ", ";
   return os<<")"; 
}

template <typename F, typename S>
ostream &operator<<(ostream &os, const pair<F, S>&v) {
  os << "(" << v.first << ", " << v.second << ")";
}

void print() {
  for(const vector<pair<int,int>> & esx : es) {
//    cout << esx << endl;
    for(const pair<int,int>& a : esx) {
      cout << a << ", ";
      //cout << "(" << a.first << ", " << a.second << ")" << ", ";
    }
    cout << endl;
  }
}  

// recursion: contracting leaves
bool rec(int x, int prnt) {
  if(es[x].size() == 1) { // this is a leaf
    es[x].clear();
    return true;
  } else {
    vector<pair<int,int>> esx;
    for(auto p : es[x]) {
      if(p.first == prnt || !rec(p.first, x)) {
        esx.push_back(p);
      }
    }
    es[x] = esx;
    return false;
  }
}

// dfs
bool dfs(int x, int prnt) {
  for(auto p : es[x]) {
    if(p.first == prnt) continue;
    depth[p.first] = depth[x] + p.second;
    dfs(p.first, x);
  }
}

int main(int argc, char *argv[])
{
  for(;;) {
    int n;
    cin >> n;
    if(n == 0) break;
    vector<int> ps, ds;
    for(int i = 0; i < n - 1; i++) {
      int p;
      cin >> p;
      p--;
      ps.push_back(p);
    }
    int dsum = 0;  // sum of all edge lengths = the essential cost
    for(int i = 0; i < n - 1; i++) {
      int d;
      cin >> d;
      dsum += d;
      ds.push_back(d);
    }
    es.clear();
    for(int i = 0; i < n; i++) {
      es.push_back(vector<pair<int,int>>());
      
    }
    for(int i = 0; i < n - 1; i++) {
      int p = ps[i];
      int d = ds[i];
      es[i+1].push_back(pair<int,int>(p,d));
      es[p].push_back(pair<int,int>(i+1,d));
    }
    //print();
    // make a root
    int r = 0;
    while(es[r].size() < 2) r++;
    
    // contract the leaves; these can be removed without moving
    rec(r, -1);
    // print();

    // then, the cost is "dsum + the total remaining edges - the logest path"
    //   trivially, we can remove all bridges by moving around the remaining tree; this results in the cost "dsum + the total remaining edges".
    //   how can we reduce the cost? the starting and ending islands can be diffetent, and this means that we may reduce the cost by that of the 'return' trip.

    // total of the remaining edges (both direction) (= the length of the tour)
    int esum = 0;
    for(auto esx : es) {
      for(auto v : esx) {
        esum += v.second;
      }
    }

    // distance from the root
    depth = vector<int>(n, 0);
    dfs(r, -1);

    // new root = the fartheset
    int mx = 0;
    for(int i = 0; i < n; i++) {
      if(depth[i] > mx) {
        mx = depth[i];
        r = i;
      }
    }
    // again, dfs from the new root
    depth = vector<int>(n, 0);
    dfs(r, -1);    
    sort(depth.begin(), depth.end());
    // the longest path is the longest dist from the root
    int ls = depth[n-1];
    cout << dsum + esum - ls << endl;
  }
}
