typedef struct CircVecRep* CircVec;
typedef int ValueType;

// create new circular vector
CircVec newCircVec();

// return the value held at `idx`
ValueType get(CircVec vec, int idx);

// set the element stored at `idx` of `vec` equal to `val`
void set(CircVec vec, ValueType val, int idx);

// insert `val` at the end of `vec`
void push(CircVec vec, ValueType val);

// insert `val` at the start of `vec`
void pushLeft(CircVec vec, ValueType val);

// remove and return last value in `vec`
ValueType pop(CircVec vec);

// remove and return fisrt value in `vec`
ValueType popLeft(CircVec vec);

// insert value at `idx` and shift subsequent values right by 1
void insertAt(CircVec vec, ValueType val, int idx);

// remove and return value at `idx` and shift subsequent values left by 1
ValueType removeAt(CircVec vec, int idx);

// return length of `vec`
int len(CircVec);

// print `vec`
void show(CircVec vec);

// free all the memory used by `vec`
void destroy(CircVec vec);