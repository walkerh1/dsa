typedef struct VecRep *Vector;
typedef int ValueType;


// create new vetor that stores provided type
Vector create(ValueType type);

// return the element at idx if it exists, else error
ValueType get(Vector vec, int idx);

// insert element at the end of the vector
void push(Vector vec, ValueType val);

// remove element from the end of the vector
ValueType pop(Vector vec);

// insert provided element at the index specified
void insertAt(Vector vec, ValueType val, int idx);

// remove element at idx and shift subsequent elements left
ValueType removeAt(int idx);

// length of vector
int len(Vector vec);

// free all the memory used by vector
void destroy(Vector vec);