#include <iostream>
#include <stdlib.h>

using namespace std;

void ele(const int h, const int w, int **p, int **passed) {
  
  int num = 0;
  
  for (size_t i = 0; i < h; i++) {
    for (size_t j = 0; j < w; j++) {
      if (passed[i][j] == -1) {
	passed[i][j] = num;
	int fig = p[i][j];
	//上下左右調べる
	//上
	if (i-1 > -1)
	  if (fig == p[i-1][j])
	  passed[i-1][j] = num;
	//右
	if (j+1 < w)
	  if(fig == p[i][j+1])
	    passed[i][j+1] = num;
	//下
	if (i+1 < h)
	  if(fig == p[i+1][j])
	    passed[i+1][j] = num;
	//左
	if ( j-1 > -1)
	  if(fig == p[i][j-1])
	    passed[i][j-1] = num;
	num++;
	}
      else {
       	int fig = p[i][j];
	int tmp = passed[i][j];
	//上下左右調べる
	//上
	if (i-1 > -1)
	  if (fig == p[i-1][j])
	  passed[i-1][j] = tmp;
	//右
	if (j+1 < w)
	  if(fig == p[i][j+1])
	    passed[i][j+1] = tmp;
	//下
	if (i+1 < h)
	  if(fig == p[i+1][j])
	    passed[i+1][j] = tmp;
	//左
	if ( j-1 > -1)
	  if(fig == p[i][j-1])
	    passed[i][j-1] = tmp;
      }
    }
  }
  /*
  for (size_t i = 0; i < h; i++) {
    cout << "passed: ";
    for (size_t j = 0; j < w; j++) {
      cout << passed[i][j];
    }
    cout << endl;
    cout << "p: "; 
    for (size_t j = 0; j < w; j++) {
      cout << p[i][j];
    }
  
    cout << endl;
  }
  */
}


int mass(const int h, const int w, const int c, const int times, int **p, int **passed){

  int **tmp, **tpas;
  int max = 0;
  int cur;
  tmp = (int **)malloc(sizeof(int *)*h);
  tpas = (int **)malloc(sizeof(int *)*h);
  
  for (size_t i = 0; i < h; i++) {
    tmp[i] = (int *)malloc(sizeof(int)*w);
    tpas[i] = (int *)malloc(sizeof(int)*w);
  }
  
  if (times != 5) {
    for (size_t i = 1; i <= 6; i++) {
      for (size_t j = 0; j < h; j++)
	for (size_t k = 0; k < w; k++) {
	  tmp[j][k] = p[j][k];
	  tpas[j][k] = passed[j][k];
	}
      if (tmp[0][0] != i) {
	for (size_t j = 0; j < h; j++)
	  for (size_t k =0; k < w; k++)
	    if (tpas[0][0] == tpas[j][k]){
	      tmp[j][k] = i;
	    }
	ele(h,w,tmp,tpas);
	cur = mass(h,w,c,times+1,tmp,tpas);
	if (max < cur)
	  max = cur;
      }
    }
  }
  else if (times == 5) {
    tmp[0][0] = c;
    for (size_t j = 0; j < h; j++)
      for (size_t k =0; k < w; k++)
	if (tpas[0][0] == tpas[j][k]){
	  tmp[j][k] = c;
	}
    ele(h,w,tmp,tpas);
    for (size_t i = 0; i < h; i++)
      for (size_t j = 0; j < w; j++)
	if(tpas[0][0] == tpas[i][j])
	  max++;
   
  }
  
  
  
  for (size_t i = 0; i < h; i++) {
    free(tmp[i]);
    free(tpas[i]);
  }
  free(tmp);
  free(tpas);
  return max;
  
}



int main(int argc, char *argv[])
{
  int h, w, c;
  cin >> h >> w >> c;
  int **p;
  p = (int **)malloc(sizeof(int *)*h);
  for (size_t i = 0; i < h; i++)
    p[i] = (int *)malloc(sizeof(int)*w);
  for (size_t i = 0; i < h; i++)
    for (size_t j = 0; j < w; j++)
      cin >> p[i][j];

  int **passed;
  passed = (int **)malloc(sizeof(int *)*h);
  for (size_t i = 0; i < h; i++)
    passed[i] = (int *)malloc(sizeof(int)*w);
  for (size_t i = 0; i < h; i++)
    for (size_t j = 0; j < w; j++)
      passed[i][j] = -1;
  
  ele(h,w,p,passed);
  int max;
  max = mass(h,w,c,0,p,passed);

  cout << max << endl;

  return 0;
  //cout << "ele" << num << endl;
  
  
}
