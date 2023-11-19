#include <stdlib.h>
#include <stdio.h>
#include "vector.h"

#define INITIAL_CAP 64

typedef struct VecRep {
   ValueType *vals;
   int len;
   int cap;
} VecRep;

Vector create() {
   Vector v = (Vector)malloc(sizeof(VecRep));
   assert(v != NULL);
   v->len = 0;
   v->cap = INITIAL_CAP;
   v->vals = (ValueType*)malloc(sizeof(ValueType) * v->cap);
   assert(v->vals != NULL);
   return v;
}

ValueType get(Vector vec, int idx) {
   assert(vec != NULL);
   assert(idx >= 0 && idx < vec->len);
   return vec->vals[idx];
}

ValueType set(Vector vec, ValueType val, int idx) {
   assert(vec != NULL);
   assert(idx >= 0 && idx < vec->len);
   vec->vals[idx] = val;
}

void push(Vector vec, ValueType val) {
   assert(vec != NULL);
   vec->len++;
   if (vec->len == vec->cap) {
      changeCap(vec, 2 * vec->cap);
   }
   vec->vals[(vec->len) - 1] = val;
}

ValueType pop(Vector vec) {
   assert(vec != NULL);
   assert(vec->len > 0);
   vec->len--;
   if (4 * vec->len > vec->cap) {
      changeCap(vec, vec->cap / 2);
   }
   return vec->vals[vec->len];
}

void insertAt(Vector vec, ValueType val, int idx) {
   assert(vec != NULL);
   assert(idx >= 0 && idx < vec->len);
   vec->len++;
   if (vec->len == vec->cap) {
      changeCap(vec, 2 * vec->cap);
   }
   for (int i = idx; i < vec->len - 1; i++) {
      vec->vals[i+1] = vec->vals[i];
   }
   vec->vals[idx] = val;
}

ValueType removeAt(Vector vec, int idx) {
   assert(vec != NULL);
   assert(idx >= 0 && idx < vec->len);
   vec->len--;
   if (4 * vec->len > vec->cap) {
      changeCap(vec, vec->cap / 2);
   }
   ValueType result = vec->vals[idx];
   for (int i = idx; i < vec->len; i++) {
      vec->vals[i] = vec->vals[i+1];
   }
   return result;
}

int len(Vector vec) {
   return vec->len;
}

void show(Vector vec) {
   putchar("[");
   int i;
   for (i = 0; i < vec->len - 1; i++) {
      printf("%d, ", vec->vals[i]);
   }
   printf("%d]\n", vec->vals[i]);
}

void destroy(Vector vec) {
   assert(vec != NULL);
   free(vec->vals);
   free(vec);
}

// helper for resizing the underlying arrays
void changeCap(Vector vec, int newCap) {
   ValueType *newVals = (ValueType*)realloc(vec->vals, sizeof(ValueType) * newCap);
   assert(newVals != NULL);
   vec->cap = newCap;
   vec->vals = newVals;
}