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
   Vector v = createTestVector(10);
   insertAt(v, 20, 5);
   assert(get(v, 5) == 20);
   assert(get(v, 6) == 5);
   assert(len(v) == 11);
   destroy(v);
}

void test_removeAt() {
   Vector v = createTestVector(10);
   removeAt(v, 5);
   assert(get(v, 5) == 6);
   assert(len(v) == 9);
   destroy(v);
}

int main(void) {
   test_insertAt();
   test_removeAt();
}