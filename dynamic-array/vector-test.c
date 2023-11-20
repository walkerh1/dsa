#include <stdlib.h>
#include <assert.h>
#include "vector.h"

Vector createTestVector(int n) {
   Vector v = newVector();
   for (int i = 0; i < n; i++) {
      push(v, i);
   }
   return v;
}

void test_insertAt() {
   Vector v = createTestVector(20);
   insertAt(v, 20, 9);
   assert(get(v, 9) == 20);
   assert(get(v, 10) == 9);
   assert(len(v) == 21);
   destroy(v);
}

int main(void) {
   test_insertAt();
}