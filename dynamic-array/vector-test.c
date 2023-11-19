#include <stdlib.h>
#include "vector.h"

int main(void) {
   Vector v = create();
   for (int i = 0; i < 100; i++) {
      push(v, i);
   }
   show(v);
}