#include <stdlib.h>
#include "vector.h"

int main(void) {
   Vector v = newVector();
   for (int i = 0; i < 200; i++) {
      push(v, i);
   }
   show(v);
}