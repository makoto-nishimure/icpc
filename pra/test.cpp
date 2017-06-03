#include <iostream>


int main() {

  int i;
  i = 0;
  
  while(i < 10) {
    int j;
    std::cout << std::hex << &j <<std::endl;
    i++;
  }
  return 0;
}
