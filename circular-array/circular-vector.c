#include <stdlib.h>
#include <assert.h>
#include "circular-vector.h"

#define INITIAL_CAP 16

typedef struct CircVecRep {
   ValueType *vals;
   int cap;
   int len;
   int head;
} CircVecRep;

int offset(CircVec vec, int idx);
void changeCap(CircVec vec, int newCap);

CircVec newCircVec() {
   CircVec v = (CircVec*)malloc(sizeof(CircVecRep));
   assert(v != NULL);
   v->cap = INITIAL_CAP;
   v->len = 0;
   v->head = 0;
   v->vals = (ValueType*)malloc(sizeof(ValueType) * v->cap);
   assert(v->vals != NULL);
   return v;
}

ValueType get(CircVec vec, int idx) {
   assert(vec != NULL);
   assert(idx >= 0 && idx < vec->len);
   return vec->vals[offset(vec, idx)];
}

void set(CircVec vec, ValueType val, int idx) {
   assert(vec != NULL);
   assert(idx >= 0 && idx < vec->len);
   vec->vals[offset(vec, idx)] = val;
}

void insertAt(CircVec vec, ValueType val, int idx) {
   assert(vec != NULL);
   assert(idx >= 0 && idx <= vec->len);
   vec->len++;
   if (vec->len == vec->cap) {
      changeCap(vec, 2 * vec->cap);
   }
   for (int i = idx; i < vec->len - 1; i++) {
      vec->vals[offset(vec, i+1)] = vec->vals[offset(vec, i)];
   }
   vec->vals[offset(vec, idx)] = val;
}

ValueType removeAt(CircVec vec, int idx) {
   assert(vec != NULL);
   assert(idx >= 0 && idx < vec->len);
   ValueType result = vec->vals[offset(vec, idx)];
   vec->len--;
   if (4 * vec->len < vec->cap) {
      changeCap(vec, vec->cap / 2);
   }
   for (int i = idx; i < vec->len; i++) {
      vec->vals[offset(vec, i)] = vec->vals[offset(vec, i+1)];
   }
   return result;
}

int len(CircVec vec) {
   return vec->len;
}

void show(CircVec vec) {
   putchar('[');
   int i;
   for (i = 0; i < vec->len - 1; i++) {
      printf("%d, ", vec->vals[offset(vec, i)]);
   }
   printf("%d]\n", vec->vals[offset(vec, i)]);
}

void destroy(CircVec vec) {
   assert(vec != NULL);
   free(vec->vals);
   free(vec);
}

// helper to get the actual index of the underlying array
int offset(CircVec vec, int idx) {
   return (vec->head + idx) % vec->cap;
}

// helper for resizing the underlying array
void changeCap(CircVec vec, int newCap) {
   ValueType *newVals = (ValueType*)malloc(sizeof(ValueType) * newCap);
   assert(newVals != NULL);
   for (int i = 0; i < vec->len; i++) {
      newVals[i] = vec->vals[offset(vec, i)];
   }
   free(vec->vals);
   vec->cap = newCap;
   vec->head = 0;
   vec->vals = newVals;
}