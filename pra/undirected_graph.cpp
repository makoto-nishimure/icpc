//2017/05/30
//undirected_graph

#include <iostream>
#include <stdlib.h>
#include <bitset>
#include <stack>

#define MAX 800

std::bitset<MAX> flag;  //admのnodes通過フラグ
std::stack<int> root;

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

bool memo_root(int n, int en, int eten, int **adm) {

  // std::cout << "current node is " << en << std::endl;
  
  bool rf;//root flag
  rf = false;
  if(en == eten){
    rf = true;
    return rf;
  }
    
  flag.set(en);
  for(int i = 0; i <= n; i++) {
    if(adm[en][i]) {
	if(!flag[i]){
	  if(memo_root(n, i, eten, adm)) {
	    root.push(i);
	    rf = true;
	    break;
	  }
	}
      }
  }
  return rf;
}

int cal_cost(int n, int *d) {

  int sum, size, tmp;

  sum = 0;
  size = root.size();
  for(int i = 0; i < size; i++) {
    tmp = root.top();
    root.pop();
    //std::cout << tmp << std::endl;
    if(tmp == 1)
      sum += 0;
    else
      sum += d[tmp-2];
  }
  return sum;

}


int main(int argc, char *argv[]) {

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
  std::stack<int> len; //list of en
  int en; //end node
  std::stack<int> leten; //list of eten
  int eten; //end to end node
  int tmp, temp;
  int sum; //root cost sum
  int size, sz; 
  int fn, nn; //first and next node
  int cc, wr;  //current cost ,worst root


  while(true){

    n = sn = en = eten = tmp =temp = sum =size =sz= fn= nn =cc =wr =0;
    
    for(i = 0; i < MAX; i++) {
      flag.reset(i);
      dic.reset(i);
    }


    
  std::cin >> n;
  if(n == 0)
    break;
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
  
  for(i = 0; i <= n; i++) {
    if(tmp == depth[i])
      len.push(i);
  }
  
  //end dfs(first time)
  for(i = 0; i < MAX; i++)
    flag.reset(i);
  //for(i = 0; i < n; i++)
  //std::cout << depth[i];
  
  //std::cout << "end node: " << en << std::endl;

  //depth first search (second time)
  
  //depth(array) init
  for(i = 0; i <= n; i++)
    depth[i] = 0;
  dfs(n, en, adm, depth, 0);

  tmp = 0;
  for(i = 0; i <= n; i++){
    //std::cout << "i : " << i << ", depth: " << depth[i] << std::endl;
    if(tmp < depth[i]) {
      tmp = depth[i];
    }
  }
  //end dfs(second time)

  //list up eten
  for(i = 0; i <= n; i++){
    if(tmp == depth[i])
      leten.push(i);
  }  
 

  
  //dicide most heavy root
  size = len.size();
  sz = leten.size();
  //std::cout << size << " " << sz << std::endl;

  if(sz > 0) {
    int *array;
    array = (int *)malloc(sizeof(int) * sz);
    for(k = 0; k < sz; k++) {
      array[k] = leten.top();
      leten.pop();
    }
    
    //std::cout << "size: " << size << std::endl;
    wr = 0;
    for(i = 0; i < size; i++) {
      
      temp = len.top();
      len.pop();
      
      
      for(k = 0; k < sz; k++) {
	tmp = array[k];
	if(temp == tmp)
	  break;
	
	//root of from end node to elements of leten
	for(j = 0; j < MAX; j++)
	  flag.reset(j);
	
	memo_root(n, temp, tmp, adm);
	root.push(temp);
	cc = cal_cost(n, d);
	// std::cout << tmp << " " << cc << std::endl;
	if(wr < cc) {
	  wr = cc;
	  en = temp;
	  eten = tmp;
	}
      }
    }
    free(array);

    
    //std::cout << "wr: " << wr << std::endl;
    //std::cout << "eten: " << eten << std::endl;
    
    tmp = 0;
    sum = 0;
    std::cout << "wr: " << wr << std::endl;
    for(j = 0; j < n-1; j++)
    std::cout << dic[j];
    std::cout << std::endl;
    for(k = 1; k < n; k++)
      if(dic[k] && ((k-2) >= 0))
	tmp+=d[k-2];
    
    tmp*=2;
    tmp-=wr;
    
    for(j = 0; j < n-1; j++)
      sum+=d[j];
    
    std::cout << "sum: " << sum << std::endl;
    std::cout << "tmp: " << tmp << std::endl;
    sum+=tmp;
    std::cout << sum << std::endl;
  }
  else {
    for(j = 0; j < n-1; j++)
      sum+=d[j];
    std::cout << sum << std::endl;
    
  }
  
  }
  return 0;
  
  
}
