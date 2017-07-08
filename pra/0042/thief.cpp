#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <string.h>

using namespace std;

int dp[1001][1001];


void rec(int i, const int weight, const int n, int v[], int w[], int *sum_w, int *sum_v)
{
  //葉の時
  if (i+1 == n) {
    if (weight >= w[i] + *sum_w) {
      *sum_w += w[i];
      *sum_v += v[i];
    } 
    
  }
  //葉でない時
  else {
    int tmpw, tmpv;
    tmpw = *sum_w;
    tmpv = *sum_v;
    
    int w1, v1, w2, v2;
    //袋に入れる
    if (weight >= w[i] + tmpw) {
      *sum_w += w[i];
      *sum_v += v[i];
      
      rec(i+1, weight, n, v, w, sum_w, sum_v);
      
      w1 =  *sum_w;
      v1 =  *sum_v;

    } else { v1 = 0; }
    
    *sum_w = tmpw;
    *sum_v = tmpv;
    
    //袋に入れない
    rec(i+1, weight, n, v, w, sum_w, sum_v);
    
    if (weight >= *sum_w) {
      w2 = *sum_w;
      v2 = *sum_v;
    }

    if (v1 > v2) {
      *sum_w = w1;
      *sum_v = v1;
    } else {
      *sum_w = w2;
      *sum_v = v2;
    }
    
  }
  
}

void rec2(int i, const int weight, const int n, int v[], int w[], int *sum_w, int *sum_v)
{
 
  if (i == n) {
    *sum_v = 0;
  }
  else {
    int tmpw, tmpv;
    tmpw = *sum_w;
    tmpv = *sum_v;
    
    int w1, v1, w2, v2;

    if (weight >= w[i] + tmpw) {
      *sum_w += w[i];
      
      rec2(1+i, weight, n, v, w, sum_w, sum_v);

      w1 = *sum_w;
      v1 = *sum_v + v[i];
    } else { v1 = -1; w1 = -1; }
    *sum_w = tmpw;
    *sum_v = tmpv;

    rec2(1+i, weight, n, v, w, sum_w, sum_v);

    w2 = *sum_w;
    v2 = *sum_v;

    if (v1 > v2) {
      *sum_w = w1;
      *sum_v = v1;
    } else {
      *sum_w = w2;
      *sum_v = v2;
    }
   
  }

}


int rec3(const int i, const int weight, const int n, int v[], int w[])
{
  if (dp[i][weight] != -1) {
    return dp[i][weight];
  }

  
  int res;
  
  if (i == n) {
    res = 0;
  }
  else {
    if (weight < w[i]) {
      res = rec3(i+1,weight,n,v,w);
    }
    else {
      res = max(rec3(i+1,weight,n,v,w), (rec3(i+1,weight-w[i],n,v,w)+v[i]));
    }
  }
  return dp[i][weight] = res;
}

int main(void)
{
  int count = 1;
  while (true) {
    
    int weight, n;
    cin >> weight;
    if (weight == 0) break;
    cin >> n;
    int v[n], w[n];
    char c;
    for (int i = 0; i < n; i++) cin >> v[i] >> c >> w[i];
    //入力終了

    
    
    int huroshiki, value;
    int *sum_w, *sum_v;

    huroshiki = 0;
    value = 0;
    sum_w = &huroshiki; sum_v = &value;

    
    
    rec2(0, weight, n, v, w, sum_w, sum_v);
    
    cout << "Case " << count << ":" << endl;
    cout << value << endl;
    cout << huroshiki << endl;

    memset(dp, -1, sizeof(dp));
    
    cout << rec3(0,weight,n,v,w) << endl;

    for (int i = 0; i < n+1; i++) {
      for (int j = 0; j < weight + 1; j++)
	cout << dp[i][j] << " ";
      cout << endl;
	}
    
    count++;
  }

  return 0;
}
