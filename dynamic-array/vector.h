typedef struct VecRep *Vector;
typedef int ValueType;

// create new vector that stores elements of the specified type
Vector newVector();

// return the value held at idx
ValueType get(Vector vec, int idx);

// set the element stored at idx of vector equal to value
ValueType set(Vector vec, ValueType val, int idx);

// insert value at the end of the vector
void push(Vector vec, ValueType val);

// remove value from the end of the vector
ValueType pop(Vector vec);

// insert value at the index specified and shift subsequent values right by 1
void insertAt(Vector vec, ValueType val, int idx);

// remove and return value at idx and shift subsequent values left by 1
ValueType removeAt(Vector vec, int idx);

// return length of vector
int len(Vector vec);

// print vector
void show(Vector vec);

// free all the memory used by vector
void destroy(Vector vec);