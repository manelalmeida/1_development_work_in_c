#include <stdio.h>
#include <assert.h>
#include "counter.h"

int main() {
reset();
assert(get() == 0);
printf("Counter: %d\n", get()); // deverá ser 0
incr();
incr();
assert(get() == 2);
printf("Counter: %d\n", get()); // deverá ser 2
reset();
assert(get() == 0);
printf("Counter: %d\n", get()); // deverá ser 0
return 0;
}
