#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "circular-vector.h"

#define INITIAL_CAP 16
#define DEBUG 1

typedef struct CircVecRep {
   ValueType *vals;
   int cap;
   int len;
   int head;
} CircVecRep;

int _offset(CircVec vec, int idx);
void _changeCap(CircVec vec, int newCap);

CircVec newCircVec() {
   CircVec v = (CircVec)malloc(sizeof(CircVecRep));
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
   return vec->vals[_offset(vec, idx)];
}

void set(CircVec vec, ValueType val, int idx) {
   assert(vec != NULL);
   assert(idx >= 0 && idx < vec->len);
   vec->vals[_offset(vec, idx)] = val;
}

void push(CircVec vec, ValueType val) {
   assert(vec != NULL);
   vec->len++;
   if (vec->len == vec->cap) {
      _changeCap(vec, 2 * vec->cap);
   }
   vec->vals[_offset(vec, vec->len - 1)] = val;
}

void pushLeft(CircVec vec, ValueType val) {
   assert(vec != NULL);
   vec->len++;
   if (vec->len == vec->cap) {
      _changeCap(vec, 2 * vec->cap);
   }
   int offset = vec->head - 1;
   vec->head = offset < 0 ? vec->cap + offset : offset;
   vec->vals[vec->head] = val;
}

ValueType pop(CircVec vec) {
   assert(vec != NULL);
   assert(vec->len > 0);
   ValueType result = vec->vals[_offset(vec, vec->len - 1)];
   vec->len--;
   if (4 * vec->len < vec->cap) {
      _changeCap(vec, vec->cap / 2);
   }
   return result;
}

ValueType popLeft(CircVec vec) {
   assert(vec != NULL);
   assert(vec->len > 0);
   ValueType result = vec->vals[_offset(vec, 0)];
   vec->len--;
   if (4 * vec->len < vec->cap) {
      _changeCap(vec, vec->cap / 2);
   }
   vec->head = (vec->head + 1) % vec->cap;
   return result;
}

void insertAt(CircVec vec, ValueType val, int idx) {
   assert(vec != NULL);
   assert(idx >= 0 && idx < vec->len);
   vec->len++;
   if (vec->len == vec->cap) {
      _changeCap(vec, 2 * vec->cap);
   }
   for (int i = idx; i < vec->len - 1; i++) {
      vec->vals[_offset(vec, i+1)] = vec->vals[_offset(vec, i)];
   }
   vec->vals[_offset(vec, idx)] = val;
}

ValueType removeAt(CircVec vec, int idx) {
   assert(vec != NULL);
   assert(idx >= 0 && idx < vec->len);
   ValueType result = vec->vals[_offset(vec, idx)];
   vec->len--;
   if (4 * vec->len < vec->cap) {
      _changeCap(vec, vec->cap / 2);
   }
   for (int i = idx; i < vec->len; i++) {
      vec->vals[_offset(vec, i)] = vec->vals[_offset(vec, i+1)];
   }
   return result;
}

int len(CircVec vec) {
   assert(vec != NULL);
   return vec->len;
}

void show(CircVec vec) {
   assert(vec != NULL);
   if (DEBUG) {
      printf("head: %d\n", vec->head);
      printf("length: %d\n", vec->len);
      printf("capacity: %d\n", vec->cap);
   }
   if (vec->len == 0) {
      printf("[]\n");
      return;
   }
   putchar('[');
   int i;
   for (i = 0; i < vec->len - 1; i++) {
      if (DEBUG) {
         printf("(%d: %d), ", _offset(vec, i), vec->vals[_offset(vec, i)]);
      } else {
         printf("%d, ", vec->vals[_offset(vec, i)]);
      }
   }
   if (DEBUG) {
      printf("(%d: %d)]\n", _offset(vec, i), vec->vals[_offset(vec, i)]);
   } else {
      printf("%d]\n", vec->vals[_offset(vec, i)]);
   }
}

void destroy(CircVec vec) {
   assert(vec != NULL);
   free(vec->vals);
   free(vec);
}

// helper to get the actual index of the underlying array
int _offset(CircVec vec, int idx) {
   int offset = vec->head + idx;
   return offset < 0 ? vec->cap + offset : offset % vec->cap;
}

// helper for resizing the underlying array
void _changeCap(CircVec vec, int newCap) {
   ValueType *newVals = (ValueType*)malloc(sizeof(ValueType) * newCap);
   assert(newVals != NULL);
   for (int i = 0; i < vec->len; i++) {
      newVals[i] = vec->vals[_offset(vec, i)];
   }
   free(vec->vals);
   vec->cap = newCap;
   vec->head = 0;
   vec->vals = newVals;
}