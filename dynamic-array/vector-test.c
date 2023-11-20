#include <stdlib.h>
#include <stdio.h>
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

void test_push() {
   Vector v = createTestVector(20);
   // check vec is not corrupted after realloc
   for (int i = 0; i < len(v); i++) {
      assert(get(v, i) == i);
   }
   destroy(v);
}

void test_pop() {
   Vector v = createTestVector(20);
   for (int i = 0; i < 10; i++) {
      pop(v);
   }
   assert(len(v) == 10);
   // check vec is not corrupted after realloc
   for (int i = 0; i < len(v); i++) {
      assert(get(v, i) == i);
   }
   destroy(v);
}

void test_ops_on_empty_list() {
   Vector v = createTestVector(0);
   assert(len(v) == 0);
   insertAt(v, 10, 0);
   assert(len(v) == 1);
   assert(get(v, 0) == 10);
   ValueType val = removeAt(v, 0);
   assert(val == 10);
   assert(len(v) == 0);
   push(v, 20);
   assert(len(v) == 1);
   val = pop(v);
   assert(val == 20);
   assert(len(v) == 0);
}

int main(void) {
   test_insertAt();
   test_removeAt();
   test_pop();
   test_push();
   test_ops_on_empty_list();
}