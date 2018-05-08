#include <iostream>
#include <stdio.h>
#include <vector>
#include <utility>
#include <cmath>
#include <iomanip>

using namespace std;

double tri(pair<int,int> a, pair<int,int> b, pair<int,int> c)
{
  b.first -= a.first; b.second -= a.second;
  c.first -= a.first; c.second -= a.second;
  double tmp = (b.first * c.second) - (b.second * c.first);
  tmp /= 2;
  return abs(tmp);
  
}

int main(void)
{
  int num = 0;
  while (true) {
    int n;
    cin >> n;
    if (n == 0) break;
    num++;
    vector<pair<int,int> > p;
    for (int i = 0; i < n; i++) {
      int x, y;
      cin >> x >> y;
      p.push_back(make_pair(x,y));
    }
    double sum = 0.0;
    int count = 0;
    pair<int,int> start, end, middle;
    start = p[0];
    middle = p[1];
    end = p[n-1];
    sum += tri(start,middle,end);
    count++;
    
    for (int i = 1, j = n-1;; ) {
      if (j-i <= 1)
	break;
      if (count%2 == 1) {
	start = p[i];
	i++;
	middle = p[i];
	end = p[j];
	sum += tri(start,middle,end);
	count++;
      }
      else {
	start = p[i];
	end = p[j];
	j--;
	middle = p[j];
	sum += tri(start,middle,end);
	count++;
      }
    }

    printf("%d %.1lf\n", num, sum);
    
  }
  return 0;
}
