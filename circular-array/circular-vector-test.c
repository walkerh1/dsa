#include <stdio.h>
#include "circular-vector.h"

CircVec createTestCircVec(int n) {
   CircVec v = newCircVec();
   for (int i = 0; i < n; i++) {
      push(v, i);
      show(v);
   }
   return v;
}

int main(void) {
   CircVec v = createTestCircVec(20);
   destroy(v);
   int res = -2 % 12;
   printf("%d\n", res);
}