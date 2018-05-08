#include <cstdio>
#include <cmath>
using namespace std;
 
int main()
{
  int n, testcase = 0;
  while (scanf("%d", &n), n) {
    int x0, y0, x1, y1, x2, y2;
    scanf("%d%d%d%d", &x0, &y0, &x1, &y1);
    x1 -= x0; y1 -= y0;
    int area = 0;
    for (int i = 2; i < n; ++i) {
      scanf("%d%d", &x2, &y2);
      x2 -= x0; y2 -= y0;
      area += x1*y2 - x2*y1;
      x1 = x2; y1 = y2;
    }
    printf("%d %.1lf\n", ++testcase, fabs(area / 2.0));
  }
}
