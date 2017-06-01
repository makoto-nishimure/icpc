//2017/05/30
//undirected_graph

#include <iostream>
#include <stdlib.h>
#include <bitset>

#define MAX 800

std::bitset<MAX> flag;  //admのnodes通過フラグ

//depth first search
//一番遠いノードの番号を返す
//n: number of nodes, sn: start node, adm: adjacency matrix, depth: each node's depth, cd: current depth
void dfs(int n, int sn, int **adm, int *depth, int cd) {
 
  depth[sn] = cd;
  flag.set(sn);
  for(int i = 0; i <= n; i++) {
    if(adm[sn][i]){
      if(!flag[i]){
	int tmp = cd + 1;
	dfs(n, i, adm, depth, tmp);
      }
    }
  }

  
}

int main(void) {

  int i,j,k;
  //int adm[MAX][MAX]; //adjacency matrix 隣接行列
  int **adm;
  adm = (int **)malloc(sizeof(int *)*MAX);
    
  for(i = 0; i < MAX; i++)
    adm[i] = (int *)malloc(sizeof(int)*MAX);
  
  std::bitset<MAX> dic;
  
  int *p,*d,*depth;
  p = (int *)malloc(sizeof(int) * MAX);
  d = (int *)malloc(sizeof(int) * MAX);
  depth = (int *)malloc(sizeof(int) * MAX);
  //int *root;
  //root = (int *)malloc(sizeof(int)*MAX);
  
  //start inputs
  int n;  //number of nodes
  int sn; //start node
  int en; //end node
  int eten; //end to end node
  int tmp;

  std::stack<int> root;


  
  std::cin >> n;
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
  //n
  /*
  for(i = 0; i < n; i++) {
    for(j = 0; j < n; j++)
      std::cout << adm[i][j] << " ";
    std::cout << std::endl;
  }
  std::cout << std::endl;
  */

  
  //decide a start node
 
  for(i = 0; i < n-1; i++){
    if(dic[i]) {
      sn = i;
      break;
    }
  }

  //depth first search (first time)
  
  //depth(array) init
  for(i = 0; i <= n; i++)
    depth[i] = 0;
  dfs(n, sn, adm, depth, 0);

  tmp = 0;
  for(i = 0; i <= n; i++){
    if(tmp < depth[i]) {
      tmp = depth[i];
      en = i;
    }
  }
  //end dfs(first time)
  for(i = 0; i < MAX; i++)
    flag.reset(i);
  //for(i = 0; i < n; i++)
  //std::cout << depth[i];
  std::cout << en << std::endl;

  //depth first search (second time)
  
  //depth(array) init
  for(i = 0; i <= n; i++)
    depth[i] = 0;
  dfs(n, en, adm, depth, 0);

  tmp = 0;
  for(i = 0; i <= n; i++){
    if(tmp < depth[i]) {
      tmp = depth[i];
      eten = i;
    }
  }
  //end dfs(second time)

  std::cout << eten << std::endl;

  //root of from end node to end to end node



  
  return 0;

  
}
