//2017/05/30
//undirected_graph

#include <iostream>
#include <stdlib.h>
#include <bitset>

#define MAX 800

int main(void) {

  int i,j,k;
  int adm[MAX][MAX]; //adjacency matrix 隣接行列

  std::bitset<MAX> dic;
  //start inputs
  int n;  //number of nodes

  std::cin >> n;
  int *p,*d;
  p = (int *)malloc(sizeof(int) * n+1);
  d = (int *)malloc(sizeof(int) * n+1);

  for(i = 0; i < n-1; i++)
    std::cin >> p[i];
  for(i = 0; i < n-1; i++)
    std::cin >> d[i];
  //end inputs
  
  //配列pに出現する数字のフラグを立てていく．（枝ノードを刈る為）
  for(i = 0; i < n-1; i++)
    dic.set(p[i]);
  //std::cout << dic << std::endl;

  //init adm
  for(i = 0; i < n; i++)
    for(j = 0; j < n; j++)
      adm[i][j] = 0;

  //creat adm
  for(i = 2; i < n; i++) {
    if(dic[i]) {
      k = p[i-2];
      adm[i][k] = 1;
      adm[k][i] = 1;
    }
  }

  //print adm
  /*n
  for(i = 0; i < n; i++) {
    for(j = 0; j < n; j++)
      std::cout << adm[i][j];
    std::cout << std::endl;
  }
  */


  return 0;

  
}
