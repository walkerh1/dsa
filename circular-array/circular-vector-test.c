#include <stdio.h>
#include <assert.h>
#include "circular-vector.h"

CircVec createTestCircVec(int n) {
   CircVec v = newCircVec();
   for (int i = 0; i < n; i++) {
      push(v, 1);
   }
   return v;
}

void test_left_overlap_works() {
   CircVec v = createTestCircVec(10);
   pushLeft(v, 1);
   assert(get(v, 0) == 1);
   pushLeft(v, 2);
   assert(get(v, 0) == 2);
   destroy(v);
}

void test_resize_works_from_left_overflow() {
   CircVec v = createTestCircVec(12);
   pushLeft(v, 1);
   pushLeft(v, 2);
   pushLeft(v, 3);
   assert(get(v, 0) == 3);
   pushLeft(v, 4); // resize happens on this push
   assert(get(v, 0) == 4);
   destroy(v);
}

void test_resize_works_from_right_overflow() {
   CircVec v = createTestCircVec(14);
   assert(popLeft(v) == 1);
   popLeft(v);
   push(v, 2);
   push(v, 2);
   push(v, 2);
   push(v, 2); // resize happens on this push
   assert(get(v, 0) == 1);
   assert(get(v, 15) == 2);
   destroy(v);
}

int main(void) {
   test_left_overlap_works();
   test_resize_works_from_left_overflow();
   test_resize_works_from_right_overflow();
}