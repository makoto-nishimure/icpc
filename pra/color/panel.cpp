#include <iostream>
#include <stdlib.h>

using namespace std;

void create_m(const int h, const int w, const int num, int **passed, int **adm) {
  
  for (size_t i = 0; i < num; i++) {
    for (size_t j = 0; j < num; j++) {
      int fig = passed[i][j];
      //上下左右調べる
      //上
      if (i-1 > -1)
	  if (fig != passed[i-1][j])
	    adm[fig][passed[i-1][j]] = 1;
      //右
      if (j+1 < w)
	if(fig == passed[i][j+1])
	   adm[fig][passed[i][j+1]] = 1;
	//下
      if (i+1 < h)
	if(fig == passed[i+1][j])
	   adm[fig][passed[i+1][j]] = 1;
      //左
      if ( j-1 > -1)
	if(fig == passed[i][j-1])
	   adm[fig][passed[i][j-1]] = 1;
    }
  }
  for (size_t i = 0; i < num; i++) {
    for (size_t j = 0; j < num; j++)
      cout << adm[i][j];
  }
    cout << endl;

}

int ele(const int h, const int w, int **p, int **passed) {
  
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
  for (size_t i = 0; i < h; i++) {
    for (size_t j = 0; j < w; j++)
      cout << passed[i][j];
    cout << endl;
  }
  //num--;
  return num;
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
  
  int num;
  num = ele(h,w,p,passed);
  cout << "ele" << num << endl;
  
  int **adm;
  adm = (int **)malloc(sizeof(int *)*num);
  for (size_t i = 0; i < h; i++)
    adm[i] = (int *)malloc(sizeof(int)*num);
  for (size_t i = 0; i < h; i++)
    for (size_t j = 0; j < w; j++)
      adm[i][j] = 0;

  create_m(h,w,num,passed,adm);
  
  return 0;
}
