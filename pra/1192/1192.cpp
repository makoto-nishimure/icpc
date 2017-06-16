#include <iostream>

using namespace std;

int main()
{
  
  double x, y, s;
  cin >> x >> y >> s;
  double fp;
  double t = x * 0.01;
  fp = s * t;
  int p = fp;
  int max = 0;
  cout << fp << endl;
  for (int i = 1; i < p; i++) {
    double tax = y * 0.01;
    int ano = p - i;
    double temp = i+(double)i * tax + ano+(double)ano * tax;
    int tmp = temp;
    if (tmp > max) {
      max = tmp;
      cout << tmp << i << ano << endl;
    }
  }
  cout << max << endl;

  return 0;
}
  
