#include <stdlib.h>
#include <stdio.h>
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
   CircVec v = (CircVec)malloc(sizeof(CircVecRep));
   assert(v != NULL);
   v->cap = INITIAL_CAP;
   v->len = 0;
   v->head = 0;
   v->vals = (ValueType*)malloc(sizeof(ValueType) * v->cap);
   assert(v->vals != NULL);
   show(v);
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

void push(CircVec vec, ValueType val) {
   assert(vec != NULL);
   vec->len++;
   if (vec->len == vec->cap) {
      changeCap(vec, 2 * vec->cap);
   }
   vec->vals[offset(vec, vec->len - 1)] = val;
}

void pushLeft(CircVec vec, ValueType val) {
   assert(vec != NULL);
   vec->len++;
   if (vec->len == vec->cap) {
      changeCap(vec, 2 * vec->cap);
   }
   int offset = vec->head - 1;
   vec->head = offset < 0 ? vec->cap + offset : offset;
}

ValueType pop(CircVec vec) {
   assert(vec != NULL);
   assert(vec->len > 0);
   ValueType result = vec->vals[offset(vec, vec->len - 1)];
   vec->len--;
   if (4 * vec->len < vec->cap) {
      changeCap(vec, vec->cap / 2);
   }
   return result;
}

ValueType popLeft(CircVec vec) {
      assert(vec != NULL);
   assert(vec->len > 0);
   ValueType result = vec->vals[offset(vec, 0)];
   vec->len--;
   if (4 * vec->len < vec->cap) {
      changeCap(vec, vec->cap / 2);
   }
   vec->head = (vec->head + 1) % vec->cap;
   return result;
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
   if (vec->len == 0) {
      printf("[]\n");
      return;
   }
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
   int offset = vec->head + idx;
   return offset < 0 ? vec->cap + offset : offset % vec->cap;
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