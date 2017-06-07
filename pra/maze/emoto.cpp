#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
  for(;;) {
    auto solve = [](){
      int n, m;
      cin >> n >> m;
      if(n==0 && m==0) exit(0);
      bool maze[m][n][4];
      int di [] = {0,0,1,-1};
      int dj [] = {1,-1,0,0};
      for(int i = 0; i < m*2-1; i++) {
        if(i % 2) { // side walls
          for(int j = 0; j < n; j++) {
            int k;
            cin >> k;
            int ii = i/2;
            maze[ii][j][2]   = k==1;    // to down
            maze[ii+1][j][3] = k==1;    // to top
          }
        } else { // vert walls
          for(int j = 0; j < n - 1; j++) {
            int k;
            cin >> k;
            int ii = i/2;
            maze[ii][j][0]   = k==1;    // to right
            maze[ii][j+1][1] = k==1;    // to left
          }
        }
      }
      int que_body[n*m];
      int nextque_body[n*m];
      int *que = que_body;
      int *nextque = nextque_body;
      int sp = 0;
      int nextsp = 0;
      int cnt = 0;
      bool visited[n*m];
      for(int i = 0; i < n*m; i++) {
        visited[i] = 0;
      }
      que[sp++] = 0;
      visited[0] = true;
      while(sp > 0) {
        cnt++;
        for(int k = 0; k < sp; k++) {
          int q = que[k];
          if(q == m*n-1) return cnt;
          int i = q / n;
          int j = q % n;
          //cout << cnt << " visiting " << i << ","<<j << endl;
          for(int o = 0; o < 4; o++) {
            int i2 = i + di[o];
            int j2 = j + dj[o];
            if(i2 >= 0 && j2 >= 0 && i2 < m && j2 < n && !maze[i][j][o]) {
              int nq = i2 * n + j2;
              if(!visited[nq]) {
                visited[nq] = true;
                nextque[nextsp++] = nq;
                //cout << cnt << " pushing " << i2 << ","<<j2 << endl;
              }
            }
          }
        }
        sp = nextsp;
        int *p = que;
        que = nextque;
        nextque = p;
        nextsp = 0;
      }
      return 0;
    };
    cout << solve() << endl;
  }
  return 0;
}
