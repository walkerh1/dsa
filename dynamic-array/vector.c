#include <stdlib.h>
#include "vector.h"

#define INITIAL_CAPACITY 64

typedef struct VecRep {
   ValueType *values;
   int length;
   int capacity;
} VecRep;

Vector create(ValueType type) {
   Vector v = (Vector)malloc(sizeof(VecRep));
   assert(v != NULL);
   v->length = 0;
   v->capacity = INITIAL_CAPACITY;
   v->values = (ValueType*)malloc(sizeof(ValueType) * v->capacity);
   assert(v->values != NULL);
   return v;
}

ValueType get(Vector vec, int idx) {
   assert(vec != NULL);
   assert(idx >= 0 && idx < vec->length);
   return vec->values[idx];
}

void push(Vector vec, ValueType val);

ValueType pop(Vector vec) {
   assert(vec != NULL);
   assert(vec->length > 0);
   vec->length--;
   return vec->values[vec->length];
}

void insertAt(Vector vec, ValueType val, int idx);

ValueType removeAt(int idx);

int len(Vector vec) {
   return vec->length;
}