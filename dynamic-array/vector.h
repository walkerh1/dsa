typedef struct VecRep *Vector;
typedef int ValueType;

// create new vetor that stores provided type
Vector create(ValueType type);

// return the value at idx
ValueType get(Vector vec, int idx);

// set the element at idx equal to value
ValueType set(Vector vec, ValueType val, int idx);

// insert value at the end of the vector
void push(Vector vec, ValueType val);

// remove value from the end of the vector
ValueType pop(Vector vec);

// insert value at the index specified and shift subsequent elemenets right by 1
void insertAt(Vector vec, ValueType val, int idx);

// remove value at idx and shift subsequent values left by 1
ValueType removeAt(int idx);

// length of vector
int len(Vector vec);

// free all the memory used by vector
void destroy(Vector vec);