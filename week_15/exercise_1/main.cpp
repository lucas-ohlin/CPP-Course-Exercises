#include <iostream>

#ifndef NUMBER 
#error "NUMBER is not defined"
#endif

#if (NUMBER != 8 && NUMBER != 16)
#error "NUMBER must be 8 or 16"
#endif

int main() {
  printf("%d", NUMBER);
  return 0;
}
